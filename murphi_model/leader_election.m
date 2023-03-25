const
  N: 10;
type
  UIDs: 1..N;
  CNT: 0..N;
  MsgTypes: enum {EMPTY, ELECTION, ELECTED};
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
  leaderUID: UIDs;
  total_PARTICIPANT : CNT;

startstate "Init"
for i: UIDs do
    p[i].UID := i;
    p[i].isLeader := false;
    p[i].state := NON_PARTICIPANT;
    undefine p[i].elected;
    channel[i].mtype := EMPTY;
    undefine channel[i].elected;
  end;
undefine leaderUID;
total_PARTICIPANT := 0;
endstartstate;


ruleset i: UIDs do
  rule "Initiate election"
  p[i].state = NON_PARTICIPANT & channel[i].mtype = EMPTY & total_PARTICIPANT = 0
  ==>
  p[i].state := PARTICIPANT;
  total_PARTICIPANT := total_PARTICIPANT+1;
  channel[(i%N) + 1].mtype := ELECTION;
  channel[i].elected := i;
  channel[(i%N) + 1].elected := channel[i].elected;
  undefine leaderUID;
  endrule;
endruleset;

ruleset i: UIDs do
  rule "Election Message Received"
    channel[i].mtype = ELECTION & p[i].isLeader = false
  ==>
    if p[i].state = NON_PARTICIPANT then
        total_PARTICIPANT := total_PARTICIPANT+1;
    endif;
    if channel[i].elected > p[i].UID then
        p[i].state := PARTICIPANT;
        channel[i].mtype := EMPTY;
        channel[(i%N) + 1].mtype := ELECTION;
        channel[(i%N) + 1].elected := channel[i].elected;
    elsif channel[i].elected < p[i].UID then
        p[i].state := PARTICIPANT;
        channel[i].elected := i;
        channel[i].mtype := EMPTY;
        channel[(i%N) + 1].mtype := ELECTION;
        channel[(i%N) + 1].elected := channel[i].elected;
    elsif channel[i].elected = p[i].UID & channel[i].mtype = ELECTION & p[i].state = PARTICIPANT then
      leaderUID := i;
      p[i].isLeader := true;
      p[i].elected := leaderUID;
      channel[i].mtype := ELECTED;
      channel[i].elected := leaderUID;
      channel[(i%N) + 1].mtype := ELECTED;
      channel[(i%N) + 1].elected := leaderUID;
    endif;
  endrule;
endruleset;


ruleset i: UIDs do
  rule "Elected Message Received"
    channel[i].mtype = ELECTED & p[i].state = PARTICIPANT & ISUNDEFINED(p[i].elected)
  ==>
    p[i].elected := leaderUID;
    if p[(i%N)+1].isLeader = true then
      channel[(i%N) + 1].mtype := EMPTY;
      undefine channel[(i%N) + 1].elected;
    else
      channel[(i%N) + 1].mtype := ELECTED;
      channel[(i%N) + 1].elected := leaderUID;
    endif;
  endrule;
endruleset;


ruleset i: UIDs do
  rule "New Leader Discards Elected Message"
    (channel[i].mtype = ELECTED & !ISUNDEFINED(p[i].elected)) & (p[i].state = PARTICIPANT) & (channel[leaderUID].mtype = EMPTY)
  ==>
    p[i].state := NON_PARTICIPANT;
    total_PARTICIPANT := total_PARTICIPANT-1;
    undefine p[i].elected;
    channel[i].mtype := EMPTY;
    undefine channel[i].elected;
    if p[(i%N)+1].isLeader = true then
      p[(i%N)+1].state := NON_PARTICIPANT;
      total_PARTICIPANT := total_PARTICIPANT-1;
      p[(i%N)+1].isLeader := false;
      undefine p[(i%N)+1].elected;
    endif;
  endrule;
endruleset;



invariant "only one leader"
  forall i: UIDs do
    forall j: UIDs do 
      i!=j -> !(p[i].isLeader& p[j].isLeader)
    end
end;


invariant "Elected leader has highest UID among participants"
  forall i: UIDs do
    p[i].isLeader -> 
    forall j: UIDs do 
      p[j].state = PARTICIPANT -> p[j].UID <= p[i].UID
    end
end;


invariant "Elected leader has the same UID as global variable leaderUID"
  forall i: UIDs do
    p[i].isLeader -> i = leaderUID
end;
