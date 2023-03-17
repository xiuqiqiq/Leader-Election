const
  N: 6;
type
  UIDs: 1..N;
  MsgTypes: enum {ELECT, ELECTED};
  NodeStates: enum {IDLE, ELECTING, DONE_ELECTED};
  Msg: record
    mtype: MsgTypes;
    uid: UIDs;     
    elected: UIDs;
  end;

var
  p: Array [UIDs] of Record    
    isParticipant: Boolean;   
    isLeader: Boolean;       
    receivedUID: UIDs;  
    electedUID: UIDs;       
    state: NodeStates;        
  End;
  channel: Array [UIDs] of Msg;     


startstate "Init"
for i: UIDs do
    p[i].isParticipant := false;
    p[i].isLeader := false;
    p[i].receivedUID := i;
    undefine p[i].electedUID;
    p[i].state := IDLE;
    channel[i].mtype := ELECT;
    channel[i].uid := i;
    undefine channel[i].elected;
  end;
endstartstate;


ruleset i: UIDs do
  rule "Election"
    p[i].state = IDLE & !p[i].isParticipant
  ==>
    p[i].state := ELECTING;
    p[i].isParticipant := true;
    channel[i].uid := i;
    channel[(i % N) + 1].uid := i;
    channel[(i % N) + 1].mtype := ELECT;
  endrule;
endruleset;

ruleset i: UIDs do
  rule "Election Message Received"
    channel[i].mtype = ELECT
  ==>
    if channel[i].uid > p[i].receivedUID then
      p[i].isParticipant := false;
      channel[(i % N) + 1].mtype := ELECT;
      channel[(i % N) + 1].uid := channel[i].uid;
    elsif channel[i].uid < p[i].receivedUID & !p[i].isParticipant then
      p[i].isParticipant := true;
      p[i].receivedUID := channel[i].uid;
      channel[(i % N) + 1].uid := i;
      channel[(i % N) + 1].mtype := ELECT;
    elsif channel[i].uid = p[i].receivedUID & p[i].isParticipant & !p[i].isLeader then
      p[i].isLeader := true;
      p[i].electedUID := channel[i].uid;
      channel[i].mtype := ELECTED;
      channel[i].elected := channel[i].uid;
    endif;
  endrule;
endruleset;

ruleset i: UIDs do
  rule "Elected Message Received"
    channel[i].mtype = ELECTED
  ==>
    p[i].state := DONE_ELECTED;
    channel[(i % N) + 1] := channel[i];
  endrule;
endruleset;

/*
ruleset i: UIDs do
  rule "New Leader Discards Elected Message"
    p[i].isLeader & channel[i].mtype = ELECTED
  ==>
    channel[((i % N) + 1) % N].mtype := ELECT;
    p[i].isLeader := false;
    p[i].isParticipant := false;
  endrule;
endruleset;
*/


invariant "Node states must be IDLE, ELECTING or DONE_ELECTED"
  forall i: UIDs do
    p[i].state = IDLE | p[i].state = ELECTING | p[i].state = DONE_ELECTED
  end;

invariant "Elected leader has highest UID among participants"
  forall i: UIDs do
    p[i].isLeader -> 
    forall j: UIDs do 
      p[j].isParticipant -> p[j].receivedUID <= p[i].receivedUID
    end
  end;




