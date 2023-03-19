const
  N: 6;
type
  UIDs: 1..N;
  MsgTypes: enum {EMPTY, SEND_ELECT, RECV_ELEC, ELECTED};
  NodeStates: enum {PARTICIPANT, NON_PARTICIPANT};
  Msg: record
    mtype: MsgTypes;
    elected: UIDs;
  end;
  
var
  p: Array [UIDs] of record        
    UID: UIDs;        
    isLeader: Boolean;    
    state: NodeStates;
    elected:UIDs;        
  end;
  channel: Array [UIDs] of Msg; 
  hasLeader: Boolean;
  leaderUID: UIDs;
  election_done: Boolean; 

startstate "Init"
for i: UIDs do
    p[i].UID := i;
    p[i].isLeader := false;
    p[i].state := NON_PARTICIPANT;
    undefine p[i].elected;
    channel[i].mtype := EMPTY;
    undefine channel[i].elected;
  end;
hasLeader := false;
election_done := false;
undefine leaderUID;
endstartstate;


ruleset i: UIDs do
  rule "Initiate election"
  hasLeader = false & p[i].state = NON_PARTICIPANT & channel[i].mtype = EMPTY
  ==>
  p[i].state := PARTICIPANT;
  channel[i].mtype := SEND_ELECT;
  channel[(i%N) + 1].mtype := RECV_ELEC;
  channel[i].elected := i;
  channel[(i%N) + 1].elected := channel[i].elected;
  endrule;
endruleset;

ruleset i: UIDs do
  rule "Election Message Received"
    channel[i].mtype = RECV_ELEC | channel[i].mtype = SEND_ELECT
  ==>
    if channel[i].elected > p[i].UID then
        p[i].state := PARTICIPANT;
        channel[i].mtype := SEND_ELECT;
        channel[(i%N) + 1].mtype := RECV_ELEC;
        channel[(i%N) + 1].elected := channel[i].elected;
    elsif channel[i].elected < p[i].UID & p[i].state=NON_PARTICIPANT  then
        p[i].state := PARTICIPANT;
        channel[i].mtype := SEND_ELECT;
        channel[i].elected := i;
        channel[(i%N) + 1].mtype := RECV_ELEC;
        channel[(i%N) + 1].elected := channel[i].elected;
    elsif channel[i].elected = p[i].UID & channel[i].mtype = RECV_ELEC & hasLeader = false then
        hasLeader := true;
        leaderUID := i;
        p[i].isLeader := true;
        p[i].elected := i;
        channel[i].mtype := ELECTED;
        channel[i].elected := i;
    endif;
  endrule;
endruleset;


ruleset i: UIDs do
  rule "Elected Message Received"
    hasLeader = true & channel[i].mtype!= EMPTY & p[i].state = PARTICIPANT
  ==>
    p[i].elected := leaderUID;
    p[i].state :=NON_PARTICIPANT;
    channel[i].elected := leaderUID;
    channel[i].mtype := EMPTY;
    election_done := true;
  endrule;
endruleset;


ruleset i: UIDs do
  rule "New Leader Discards Elected Message"
    hasLeader = true & p[i].state = NON_PARTICIPANT & election_done = true
  ==>
    if p[i].isLeader = true then
        p[i].isLeader := false;
    endif;
    undefine p[i].elected;
    undefine channel[i].elected;
    election_done := false;
  endrule;
endruleset;


invariant "Elected leader has highest UID among participants"
  forall i: UIDs do
    p[i].isLeader -> 
    forall j: UIDs do 
      p[j].state = PARTICIPANT -> p[j].UID <= p[i].UID
    end
end;



invariant "only one leader"
  forall i: UIDs do
    forall j: UIDs do 
      i!=j -> !(p[i].isLeader& p[j].isLeader)
    end
end;
