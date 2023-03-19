/******************************
  Program "./murphi_model//leader_election.m" compiled by "Caching Murphi Release 5.5.0"

  Murphi Last Compiled date: "Aug  7 2022"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Caching Murphi Release 5.5.0"
#define MURPHI_DATE "Aug  7 2022"
#define PROTOCOL_NAME "./murphi_model//leader_election"
#define BITS_IN_WORLD 312
#define ALIGN

/********************
  Include
 ********************/
#include "mu_prolog.hpp"

/********************
  Decl declaration
 ********************/

class mu_1_UIDs: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_UIDs& val) { return mu__byte::operator=((int) val); };
  mu_1_UIDs (const char *name, int os): mu__byte(1, 6, 3, name, os) {};
  mu_1_UIDs (void): mu__byte(1, 6, 3) {};
  mu_1_UIDs (int val): mu__byte(1, 6, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1_UIDs mu_1_UIDs_undefined_var;

class mu_1_MsgTypes: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_MsgTypes& val) { return value(val.value()); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1_MsgTypes& val)
  {
    if (val.defined())
      return ( s << mu_1_MsgTypes::values[ int(val) - 1] );
    else return ( s << "Undefined" );
  };

  mu_1_MsgTypes (const char *name, int os): mu__byte(1, 4, 3, name, os) {};
  mu_1_MsgTypes (void): mu__byte(1, 4, 3) {};
  mu_1_MsgTypes (int val): mu__byte(1, 4, 3, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  const char * Name() { return values[ value() -1]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -1] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

const char *mu_1_MsgTypes::values[] = {"EMPTY","SEND_ELECT","RECV_ELEC","ELECTED",NULL };

/*** end of enum declaration ***/
mu_1_MsgTypes mu_1_MsgTypes_undefined_var;

class mu_1_NodeStates: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_NodeStates& val) { return value(val.value()); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1_NodeStates& val)
  {
    if (val.defined())
      return ( s << mu_1_NodeStates::values[ int(val) - 5] );
    else return ( s << "Undefined" );
  };

  mu_1_NodeStates (const char *name, int os): mu__byte(5, 6, 2, name, os) {};
  mu_1_NodeStates (void): mu__byte(5, 6, 2) {};
  mu_1_NodeStates (int val): mu__byte(5, 6, 2, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  const char * Name() { return values[ value() -5]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -5] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

const char *mu_1_NodeStates::values[] = {"PARTICIPANT","NON_PARTICIPANT",NULL };

/*** end of enum declaration ***/
mu_1_NodeStates mu_1_NodeStates_undefined_var;

class mu_1_Msg
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  void set_self(const char *n, int os);
  mu_1_MsgTypes mu_mtype;
  mu_1_UIDs mu_elected;
  mu_1_Msg ( const char *n, int os ) { set_self(n,os); };
  mu_1_Msg ( void ) {};

  virtual ~mu_1_Msg(); 
friend int CompareWeight(mu_1_Msg& a, mu_1_Msg& b)
  {
    int w;
    w = CompareWeight(a.mu_mtype, b.mu_mtype);
    if (w!=0) return w;
    w = CompareWeight(a.mu_elected, b.mu_elected);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_Msg& a, mu_1_Msg& b)
  {
    int w;
    w = Compare(a.mu_mtype, b.mu_mtype);
    if (w!=0) return w;
    w = Compare(a.mu_elected, b.mu_elected);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_mtype.MultisetSort();
    mu_elected.MultisetSort();
  }
  void print_statistic()
  {
    mu_mtype.print_statistic();
    mu_elected.print_statistic();
  }
  void clear() {
    mu_mtype.clear();
    mu_elected.clear();
 };
  void undefine() {
    mu_mtype.undefine();
    mu_elected.undefine();
 };
  void reset() {
    mu_mtype.reset();
    mu_elected.reset();
 };
  void print() {
    mu_mtype.print();
    mu_elected.print();
  };
  void print_diff(state *prevstate) {
    mu_mtype.print_diff(prevstate);
    mu_elected.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_mtype.to_state(thestate);
    mu_elected.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_Msg& operator= (const mu_1_Msg& from) {
    mu_mtype.value(from.mu_mtype.value());
    mu_elected.value(from.mu_elected.value());
    return *this;
  };
};

  void mu_1_Msg::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_Msg::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_Msg::set_self(const char *n, int os)
{
  name = (char *)n;

  if (name) mu_mtype.set_self_2(name, ".mtype", os + 0 ); else mu_mtype.set_self_2(NULL, NULL, 0);
  if (name) mu_elected.set_self_2(name, ".elected", os + 8 ); else mu_elected.set_self_2(NULL, NULL, 0);
}

mu_1_Msg::~mu_1_Msg()
{
}

/*** end record declaration ***/
mu_1_Msg mu_1_Msg_undefined_var;

class mu_1__type_0
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  void set_self(const char *n, int os);
  mu_1_UIDs mu_UID;
  mu_0_boolean mu_isLeader;
  mu_1_NodeStates mu_state;
  mu_1_UIDs mu_elected;
  mu_1__type_0 ( const char *n, int os ) { set_self(n,os); };
  mu_1__type_0 ( void ) {};

  virtual ~mu_1__type_0(); 
friend int CompareWeight(mu_1__type_0& a, mu_1__type_0& b)
  {
    int w;
    w = CompareWeight(a.mu_UID, b.mu_UID);
    if (w!=0) return w;
    w = CompareWeight(a.mu_isLeader, b.mu_isLeader);
    if (w!=0) return w;
    w = CompareWeight(a.mu_state, b.mu_state);
    if (w!=0) return w;
    w = CompareWeight(a.mu_elected, b.mu_elected);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1__type_0& a, mu_1__type_0& b)
  {
    int w;
    w = Compare(a.mu_UID, b.mu_UID);
    if (w!=0) return w;
    w = Compare(a.mu_isLeader, b.mu_isLeader);
    if (w!=0) return w;
    w = Compare(a.mu_state, b.mu_state);
    if (w!=0) return w;
    w = Compare(a.mu_elected, b.mu_elected);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_UID.MultisetSort();
    mu_isLeader.MultisetSort();
    mu_state.MultisetSort();
    mu_elected.MultisetSort();
  }
  void print_statistic()
  {
    mu_UID.print_statistic();
    mu_isLeader.print_statistic();
    mu_state.print_statistic();
    mu_elected.print_statistic();
  }
  void clear() {
    mu_UID.clear();
    mu_isLeader.clear();
    mu_state.clear();
    mu_elected.clear();
 };
  void undefine() {
    mu_UID.undefine();
    mu_isLeader.undefine();
    mu_state.undefine();
    mu_elected.undefine();
 };
  void reset() {
    mu_UID.reset();
    mu_isLeader.reset();
    mu_state.reset();
    mu_elected.reset();
 };
  void print() {
    mu_UID.print();
    mu_isLeader.print();
    mu_state.print();
    mu_elected.print();
  };
  void print_diff(state *prevstate) {
    mu_UID.print_diff(prevstate);
    mu_isLeader.print_diff(prevstate);
    mu_state.print_diff(prevstate);
    mu_elected.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_UID.to_state(thestate);
    mu_isLeader.to_state(thestate);
    mu_state.to_state(thestate);
    mu_elected.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1__type_0& operator= (const mu_1__type_0& from) {
    mu_UID.value(from.mu_UID.value());
    mu_isLeader.value(from.mu_isLeader.value());
    mu_state.value(from.mu_state.value());
    mu_elected.value(from.mu_elected.value());
    return *this;
  };
};

  void mu_1__type_0::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_0::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_0::set_self(const char *n, int os)
{
  name = (char *)n;

  if (name) mu_UID.set_self_2(name, ".UID", os + 0 ); else mu_UID.set_self_2(NULL, NULL, 0);
  if (name) mu_isLeader.set_self_2(name, ".isLeader", os + 8 ); else mu_isLeader.set_self_2(NULL, NULL, 0);
  if (name) mu_state.set_self_2(name, ".state", os + 16 ); else mu_state.set_self_2(NULL, NULL, 0);
  if (name) mu_elected.set_self_2(name, ".elected", os + 24 ); else mu_elected.set_self_2(NULL, NULL, 0);
}

mu_1__type_0::~mu_1__type_0()
{
}

/*** end record declaration ***/
mu_1__type_0 mu_1__type_0_undefined_var;

class mu_1__type_1
{
 public:
  mu_1__type_0 array[ 6 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_1 (const char *n, int os) { set_self(n, os); };
  mu_1__type_1 ( void ) {};
  virtual ~mu_1__type_1 ();
  mu_1__type_0& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 1 ) && ( index <= 6 ) )
      return array[ index - 1 ];
    else {
      if (index==UNDEFVAL) 
	Error.Error("Indexing to %s using an undefined value.", name);
      else
	Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 1 ];
#endif
  };
  mu_1__type_1& operator= (const mu_1__type_1& from)
  {
    for (int i = 0; i < 6; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_1& a, mu_1__type_1& b)
  {
    int w;
    for (int i=0; i<6; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_1& a, mu_1__type_1& b)
  {
    int w;
    for (int i=0; i<6; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<6; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<6; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 6; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 6; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 6; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 6; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 6; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 6; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_1::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_1::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_1::set_self( const char *n, int os)
{
  char* s;
  name = (char *)n;
  for(int i = 0; i < 6; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 1), i * 32 + os);
    delete[] s;
  }
};
mu_1__type_1::~mu_1__type_1()
{
}
/*** end array declaration ***/
mu_1__type_1 mu_1__type_1_undefined_var;

class mu_1__type_2
{
 public:
  mu_1_Msg array[ 6 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_2 (const char *n, int os) { set_self(n, os); };
  mu_1__type_2 ( void ) {};
  virtual ~mu_1__type_2 ();
  mu_1_Msg& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 1 ) && ( index <= 6 ) )
      return array[ index - 1 ];
    else {
      if (index==UNDEFVAL) 
	Error.Error("Indexing to %s using an undefined value.", name);
      else
	Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 1 ];
#endif
  };
  mu_1__type_2& operator= (const mu_1__type_2& from)
  {
    for (int i = 0; i < 6; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_2& a, mu_1__type_2& b)
  {
    int w;
    for (int i=0; i<6; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_2& a, mu_1__type_2& b)
  {
    int w;
    for (int i=0; i<6; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<6; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<6; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 6; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 6; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 6; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 6; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 6; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 6; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_2::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_2::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_2::set_self( const char *n, int os)
{
  char* s;
  name = (char *)n;
  for(int i = 0; i < 6; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 1), i * 16 + os);
    delete[] s;
  }
};
mu_1__type_2::~mu_1__type_2()
{
}
/*** end array declaration ***/
mu_1__type_2 mu_1__type_2_undefined_var;

const int mu_N = 6;
const int mu_EMPTY = 1;
const int mu_SEND_ELECT = 2;
const int mu_RECV_ELEC = 3;
const int mu_ELECTED = 4;
const int mu_PARTICIPANT = 5;
const int mu_NON_PARTICIPANT = 6;
/*** Variable declaration ***/
mu_1__type_1 mu_p("p",0);

/*** Variable declaration ***/
mu_1__type_2 mu_channel("channel",192);

/*** Variable declaration ***/
mu_0_boolean mu_hasLeader("hasLeader",288);

/*** Variable declaration ***/
mu_1_UIDs mu_leaderUID("leaderUID",296);

/*** Variable declaration ***/
mu_0_boolean mu_election_done("election_done",304);





/********************
  The world
 ********************/
void world_class::clear()
{
  mu_p.clear();
  mu_channel.clear();
  mu_hasLeader.clear();
  mu_leaderUID.clear();
  mu_election_done.clear();
}
void world_class::undefine()
{
  mu_p.undefine();
  mu_channel.undefine();
  mu_hasLeader.undefine();
  mu_leaderUID.undefine();
  mu_election_done.undefine();
}
void world_class::reset()
{
  mu_p.reset();
  mu_channel.reset();
  mu_hasLeader.reset();
  mu_leaderUID.reset();
  mu_election_done.reset();
}
void world_class::print()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_p.print();
  mu_channel.print();
  mu_hasLeader.print();
  mu_leaderUID.print();
  mu_election_done.print();
    num_calls--;
}
}
void world_class::print_statistic()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_p.print_statistic();
  mu_channel.print_statistic();
  mu_hasLeader.print_statistic();
  mu_leaderUID.print_statistic();
  mu_election_done.print_statistic();
    num_calls--;
}
}
void world_class::print_diff( state *prevstate )
{
  if ( prevstate != NULL )
  {
    mu_p.print_diff(prevstate);
    mu_channel.print_diff(prevstate);
    mu_hasLeader.print_diff(prevstate);
    mu_leaderUID.print_diff(prevstate);
    mu_election_done.print_diff(prevstate);
  }
  else
print();
}
void world_class::to_state(state *newstate)
{
  mu_p.to_state( newstate );
  mu_channel.to_state( newstate );
  mu_hasLeader.to_state( newstate );
  mu_leaderUID.to_state( newstate );
  mu_election_done.to_state( newstate );
}
void world_class::setstate(state *thestate)
{
}


/********************
  Rule declarations
 ********************/
/******************** RuleBase0 ********************/
class RuleBase0
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_UIDs mu_i;
    mu_i.value((r % 6) + 1);
    r = r / 6;
    return tsprintf("New Leader Discards Elected Message, i:%s", mu_i.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_UIDs mu_i;
    mu_i.value((r % 6) + 1);
    r = r / 6;
bool mu__boolexpr3;
bool mu__boolexpr4;
  if (!((mu_hasLeader) == (mu_true))) mu__boolexpr4 = FALSE ;
  else {
  mu__boolexpr4 = ((mu_p[mu_i].mu_state) == (mu_NON_PARTICIPANT)) ; 
}
  if (!(mu__boolexpr4)) mu__boolexpr3 = FALSE ;
  else {
  mu__boolexpr3 = ((mu_election_done) == (mu_true)) ; 
}
    return mu__boolexpr3;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 0;
    static mu_1_UIDs mu_i;
    mu_i.value((r % 6) + 1);
    r = r / 6;
    while (what_rule < 6 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr5;
bool mu__boolexpr6;
  if (!((mu_hasLeader) == (mu_true))) mu__boolexpr6 = FALSE ;
  else {
  mu__boolexpr6 = ((mu_p[mu_i].mu_state) == (mu_NON_PARTICIPANT)) ; 
}
  if (!(mu__boolexpr6)) mu__boolexpr5 = FALSE ;
  else {
  mu__boolexpr5 = ((mu_election_done) == (mu_true)) ; 
}
	      if (mu__boolexpr5) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 0;
    mu_i.value((r % 6) + 1);
    r = r / 6;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_UIDs mu_i;
    mu_i.value((r % 6) + 1);
    r = r / 6;
if ( (mu_p[mu_i].mu_isLeader) == (mu_true) )
{
mu_p[mu_i].mu_isLeader = mu_false;
}
mu_p[mu_i].mu_elected.undefine();
mu_channel[mu_i].mu_elected.undefine();
mu_election_done = mu_false;
  };

};
/******************** RuleBase1 ********************/
class RuleBase1
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_UIDs mu_i;
    mu_i.value((r % 6) + 1);
    r = r / 6;
    return tsprintf("Elected Message Received, i:%s", mu_i.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_UIDs mu_i;
    mu_i.value((r % 6) + 1);
    r = r / 6;
bool mu__boolexpr7;
bool mu__boolexpr8;
  if (!((mu_hasLeader) == (mu_true))) mu__boolexpr8 = FALSE ;
  else {
  mu__boolexpr8 = ((mu_channel[mu_i].mu_mtype) != (mu_EMPTY)) ; 
}
  if (!(mu__boolexpr8)) mu__boolexpr7 = FALSE ;
  else {
  mu__boolexpr7 = ((mu_p[mu_i].mu_state) == (mu_PARTICIPANT)) ; 
}
    return mu__boolexpr7;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 6;
    static mu_1_UIDs mu_i;
    mu_i.value((r % 6) + 1);
    r = r / 6;
    while (what_rule < 12 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr9;
bool mu__boolexpr10;
  if (!((mu_hasLeader) == (mu_true))) mu__boolexpr10 = FALSE ;
  else {
  mu__boolexpr10 = ((mu_channel[mu_i].mu_mtype) != (mu_EMPTY)) ; 
}
  if (!(mu__boolexpr10)) mu__boolexpr9 = FALSE ;
  else {
  mu__boolexpr9 = ((mu_p[mu_i].mu_state) == (mu_PARTICIPANT)) ; 
}
	      if (mu__boolexpr9) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 6;
    mu_i.value((r % 6) + 1);
    r = r / 6;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_UIDs mu_i;
    mu_i.value((r % 6) + 1);
    r = r / 6;
if (mu_leaderUID.isundefined())
  mu_p[mu_i].mu_elected.undefine();
else
  mu_p[mu_i].mu_elected = mu_leaderUID;
mu_p[mu_i].mu_state = mu_NON_PARTICIPANT;
if (mu_leaderUID.isundefined())
  mu_channel[mu_i].mu_elected.undefine();
else
  mu_channel[mu_i].mu_elected = mu_leaderUID;
mu_channel[mu_i].mu_mtype = mu_EMPTY;
mu_election_done = mu_true;
  };

};
/******************** RuleBase2 ********************/
class RuleBase2
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_UIDs mu_i;
    mu_i.value((r % 6) + 1);
    r = r / 6;
    return tsprintf("Election Message Received, i:%s", mu_i.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_UIDs mu_i;
    mu_i.value((r % 6) + 1);
    r = r / 6;
bool mu__boolexpr11;
  if ((mu_channel[mu_i].mu_mtype) == (mu_RECV_ELEC)) mu__boolexpr11 = TRUE ;
  else {
  mu__boolexpr11 = ((mu_channel[mu_i].mu_mtype) == (mu_SEND_ELECT)) ; 
}
    return mu__boolexpr11;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 12;
    static mu_1_UIDs mu_i;
    mu_i.value((r % 6) + 1);
    r = r / 6;
    while (what_rule < 18 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr12;
  if ((mu_channel[mu_i].mu_mtype) == (mu_RECV_ELEC)) mu__boolexpr12 = TRUE ;
  else {
  mu__boolexpr12 = ((mu_channel[mu_i].mu_mtype) == (mu_SEND_ELECT)) ; 
}
	      if (mu__boolexpr12) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 12;
    mu_i.value((r % 6) + 1);
    r = r / 6;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_UIDs mu_i;
    mu_i.value((r % 6) + 1);
    r = r / 6;
if ( (mu_channel[mu_i].mu_elected) > (mu_p[mu_i].mu_UID) )
{
mu_p[mu_i].mu_state = mu_PARTICIPANT;
mu_channel[mu_i].mu_mtype = mu_SEND_ELECT;
mu_channel[((mu_i) % (mu_N)) + (1)].mu_mtype = mu_RECV_ELEC;
mu_channel[((mu_i) % (mu_N)) + (1)].mu_elected = mu_channel[mu_i].mu_elected;
}
else
{
bool mu__boolexpr13;
  if (!((mu_channel[mu_i].mu_elected) < (mu_p[mu_i].mu_UID))) mu__boolexpr13 = FALSE ;
  else {
  mu__boolexpr13 = ((mu_p[mu_i].mu_state) == (mu_NON_PARTICIPANT)) ; 
}
if ( mu__boolexpr13 )
{
mu_p[mu_i].mu_state = mu_PARTICIPANT;
mu_channel[mu_i].mu_mtype = mu_SEND_ELECT;
mu_channel[mu_i].mu_elected = mu_i;
mu_channel[((mu_i) % (mu_N)) + (1)].mu_mtype = mu_RECV_ELEC;
mu_channel[((mu_i) % (mu_N)) + (1)].mu_elected = mu_channel[mu_i].mu_elected;
}
else
{
bool mu__boolexpr14;
bool mu__boolexpr15;
  if (!((mu_channel[mu_i].mu_elected) == (mu_p[mu_i].mu_UID))) mu__boolexpr15 = FALSE ;
  else {
  mu__boolexpr15 = ((mu_channel[mu_i].mu_mtype) == (mu_RECV_ELEC)) ; 
}
  if (!(mu__boolexpr15)) mu__boolexpr14 = FALSE ;
  else {
  mu__boolexpr14 = ((mu_hasLeader) == (mu_false)) ; 
}
if ( mu__boolexpr14 )
{
mu_hasLeader = mu_true;
mu_leaderUID = mu_i;
mu_p[mu_i].mu_isLeader = mu_true;
mu_p[mu_i].mu_elected = mu_i;
mu_channel[mu_i].mu_mtype = mu_ELECTED;
mu_channel[mu_i].mu_elected = mu_i;
}
}
}
  };

};
/******************** RuleBase3 ********************/
class RuleBase3
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_UIDs mu_i;
    mu_i.value((r % 6) + 1);
    r = r / 6;
    return tsprintf("Initiate election, i:%s", mu_i.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_UIDs mu_i;
    mu_i.value((r % 6) + 1);
    r = r / 6;
bool mu__boolexpr16;
bool mu__boolexpr17;
  if (!((mu_hasLeader) == (mu_false))) mu__boolexpr17 = FALSE ;
  else {
  mu__boolexpr17 = ((mu_p[mu_i].mu_state) == (mu_NON_PARTICIPANT)) ; 
}
  if (!(mu__boolexpr17)) mu__boolexpr16 = FALSE ;
  else {
  mu__boolexpr16 = ((mu_channel[mu_i].mu_mtype) == (mu_EMPTY)) ; 
}
    return mu__boolexpr16;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 18;
    static mu_1_UIDs mu_i;
    mu_i.value((r % 6) + 1);
    r = r / 6;
    while (what_rule < 24 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr18;
bool mu__boolexpr19;
  if (!((mu_hasLeader) == (mu_false))) mu__boolexpr19 = FALSE ;
  else {
  mu__boolexpr19 = ((mu_p[mu_i].mu_state) == (mu_NON_PARTICIPANT)) ; 
}
  if (!(mu__boolexpr19)) mu__boolexpr18 = FALSE ;
  else {
  mu__boolexpr18 = ((mu_channel[mu_i].mu_mtype) == (mu_EMPTY)) ; 
}
	      if (mu__boolexpr18) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 18;
    mu_i.value((r % 6) + 1);
    r = r / 6;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_UIDs mu_i;
    mu_i.value((r % 6) + 1);
    r = r / 6;
mu_p[mu_i].mu_state = mu_PARTICIPANT;
mu_channel[mu_i].mu_mtype = mu_SEND_ELECT;
mu_channel[((mu_i) % (mu_N)) + (1)].mu_mtype = mu_RECV_ELEC;
mu_channel[mu_i].mu_elected = mu_i;
mu_channel[((mu_i) % (mu_N)) + (1)].mu_elected = mu_channel[mu_i].mu_elected;
  };

};
class NextStateGenerator
{
  RuleBase0 R0;
  RuleBase1 R1;
  RuleBase2 R2;
  RuleBase3 R3;
public:
void SetNextEnabledRule(unsigned & what_rule)
{
  category = CONDITION;
  if (what_rule<6)
    { R0.NextRule(what_rule);
      if (what_rule<6) return; }
  if (what_rule>=6 && what_rule<12)
    { R1.NextRule(what_rule);
      if (what_rule<12) return; }
  if (what_rule>=12 && what_rule<18)
    { R2.NextRule(what_rule);
      if (what_rule<18) return; }
  if (what_rule>=18 && what_rule<24)
    { R3.NextRule(what_rule);
      if (what_rule<24) return; }
}
bool Condition(unsigned r)
{
  category = CONDITION;
  if (r<=5) return R0.Condition(r-0);
  if (r>=6 && r<=11) return R1.Condition(r-6);
  if (r>=12 && r<=17) return R2.Condition(r-12);
  if (r>=18 && r<=23) return R3.Condition(r-18);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
return 0;}
void Code(unsigned r)
{
  if (r<=5) { R0.Code(r-0); return; } 
  if (r>=6 && r<=11) { R1.Code(r-6); return; } 
  if (r>=12 && r<=17) { R2.Code(r-12); return; } 
  if (r>=18 && r<=23) { R3.Code(r-18); return; } 
}
int Priority(unsigned short r)
{
  if (r<=5) { return R0.Priority(); } 
  if (r>=6 && r<=11) { return R1.Priority(); } 
  if (r>=12 && r<=17) { return R2.Priority(); } 
  if (r>=18 && r<=23) { return R3.Priority(); } 
return 0;}
char * Name(unsigned r)
{
  if (r<=5) return R0.Name(r-0);
  if (r>=6 && r<=11) return R1.Name(r-6);
  if (r>=12 && r<=17) return R2.Name(r-12);
  if (r>=18 && r<=23) return R3.Name(r-18);
  return NULL;
}
};
const unsigned numrules = 24;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 24


/********************
  Startstate records
 ********************/
/******************** StartStateBase0 ********************/
class StartStateBase0
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("Init");
  }
  void Code(unsigned short r)
  {
{
for(int mu_i = 1; mu_i <= 6; mu_i++) {
mu_p[mu_i].mu_UID = mu_i;
mu_p[mu_i].mu_isLeader = mu_false;
mu_p[mu_i].mu_state = mu_NON_PARTICIPANT;
mu_p[mu_i].mu_elected.undefine();
mu_channel[mu_i].mu_mtype = mu_EMPTY;
mu_channel[mu_i].mu_elected.undefine();
};
};
mu_hasLeader = mu_false;
mu_election_done = mu_false;
mu_leaderUID.undefine();
  };

};
class StartStateGenerator
{
  StartStateBase0 S0;
public:
void Code(unsigned short r)
{
  if (r<=0) { S0.Code(r-0); return; }
}
char * Name(unsigned short r)
{
  if (r<=0) return S0.Name(r-0);
  return NULL;
}
};
const rulerec startstates[] = {
{ NULL, NULL, NULL, FALSE},
};
unsigned short StartStateManager::numstartstates = 1;

/********************
  Invariant records
 ********************/
int mu__invariant_20() // Invariant "only one leader"
{
bool mu__quant21; 
mu__quant21 = TRUE;
{
for(int mu_i = 1; mu_i <= 6; mu_i++) {
bool mu__quant22; 
mu__quant22 = TRUE;
{
for(int mu_j = 1; mu_j <= 6; mu_j++) {
bool mu__boolexpr23;
  if (!((mu_i) != (mu_j))) mu__boolexpr23 = TRUE ;
  else {
bool mu__boolexpr24;
  if (!(mu_p[mu_i].mu_isLeader)) mu__boolexpr24 = FALSE ;
  else {
  mu__boolexpr24 = (mu_p[mu_j].mu_isLeader) ; 
}
  mu__boolexpr23 = (!(mu__boolexpr24)) ; 
}
if ( !(mu__boolexpr23) )
  { mu__quant22 = FALSE; break; }
};
};
if ( !(mu__quant22) )
  { mu__quant21 = FALSE; break; }
};
};
return mu__quant21;
};

bool mu__condition_25() // Condition for Rule "only one leader"
{
  return mu__invariant_20( );
}

/**** end rule declaration ****/

int mu__invariant_26() // Invariant "Elected leader has highest UID among participants"
{
bool mu__quant27; 
mu__quant27 = TRUE;
{
for(int mu_i = 1; mu_i <= 6; mu_i++) {
bool mu__boolexpr28;
  if (!(mu_p[mu_i].mu_isLeader)) mu__boolexpr28 = TRUE ;
  else {
bool mu__quant29; 
mu__quant29 = TRUE;
{
for(int mu_j = 1; mu_j <= 6; mu_j++) {
bool mu__boolexpr30;
  if (!((mu_p[mu_j].mu_state) == (mu_PARTICIPANT))) mu__boolexpr30 = TRUE ;
  else {
  mu__boolexpr30 = ((mu_p[mu_j].mu_UID) <= (mu_p[mu_i].mu_UID)) ; 
}
if ( !(mu__boolexpr30) )
  { mu__quant29 = FALSE; break; }
};
};
  mu__boolexpr28 = (mu__quant29) ; 
}
if ( !(mu__boolexpr28) )
  { mu__quant27 = FALSE; break; }
};
};
return mu__quant27;
};

bool mu__condition_31() // Condition for Rule "Elected leader has highest UID among participants"
{
  return mu__invariant_26( );
}

/**** end rule declaration ****/

const rulerec invariants[] = {
{"Elected leader has highest UID among participants", &mu__condition_31, NULL, },
{"only one leader", &mu__condition_25, NULL, },
};
const unsigned short numinvariants = 2;

/********************
  Normal/Canonicalization for scalarset
 ********************/
/*
leaderUID:NoScalarset
channel:NoScalarset
p:NoScalarset
hasLeader:NoScalarset
election_done:NoScalarset
*/

/********************
Code for symmetry
 ********************/

/********************
 Permutation Set Class
 ********************/
class PermSet
{
public:
  // book keeping
  enum PresentationType {Simple, Explicit};
  PresentationType Presentation;

  void ResetToSimple();
  void ResetToExplicit();
  void SimpleToExplicit();
  void SimpleToOne();
  bool NextPermutation();

  void Print_in_size()
  { int ret=0; for (int i=0; i<count; i++) if (in[i]) ret++; cout << "in_size:" << ret << "\n"; }


  /********************
   Simple and efficient representation
   ********************/
  bool AlreadyOnlyOneRemain;
  bool MoreThanOneRemain();


  /********************
   Explicit representation
  ********************/
  unsigned long size;
  unsigned long count;
  // in will be of product of factorial sizes for fast canonicalize
  // in will be of size 1 for reduced local memory canonicalize
  bool * in;

  // auxiliary for explicit representation

  // in/perm/revperm will be of factorial size for fast canonicalize
  // they will be of size 1 for reduced local memory canonicalize
  // second range will be size of the scalarset
  // procedure for explicit representation
  // General procedure
  PermSet();
  bool In(int i) const { return in[i]; };
  void Add(int i) { for (int j=0; j<i; j++) in[j] = FALSE;};
  void Remove(int i) { in[i] = FALSE; };
};
bool PermSet::MoreThanOneRemain()
{
  int i,j;
  if (AlreadyOnlyOneRemain)
    return FALSE;
  else {
  }
  AlreadyOnlyOneRemain = TRUE;
  return FALSE;
}
PermSet::PermSet()
: Presentation(Simple)
{
  int i,j,k;
  if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize) {

  /********************
   declaration of class variables
  ********************/
  in = new bool[1];

    // Set perm and revperm

    // setting up combination of permutations
    // for different scalarset
    int carry;
    size = 1;
    count = 1;
    for (i=0; i<1; i++)
      {
        carry = 1;
        in[i]= TRUE;
    }
  }
  else
  {

  /********************
   declaration of class variables
  ********************/
  in = new bool[1];
  in[0] = TRUE;
  }
}
void PermSet::ResetToSimple()
{
  int i;

  AlreadyOnlyOneRemain = FALSE;
  Presentation = Simple;
}
void PermSet::ResetToExplicit()
{
  for (int i=0; i<1; i++) in[i] = TRUE;
  Presentation = Explicit;
}
void PermSet::SimpleToExplicit()
{
  int i,j,k;
  int start, class_size;

  // Setup range for mapping

  // To be In or not to be

  // setup explicit representation 
  // Set perm and revperm
  for (i=0; i<1; i++)
    {
      in[i] = TRUE;
    }
  Presentation = Explicit;
  if (args->test_parameter1.value==0) Print_in_size();
}
void PermSet::SimpleToOne()
{
  int i,j,k;
  int class_size;
  int start;


  // Setup range for mapping
  Presentation = Explicit;
}
bool PermSet::NextPermutation()
{
  bool nexted = FALSE;
  int start, end; 
  int class_size;
  int temp;
  int j,k;

  // algorithm
  // for each class
  //   if forall in the same class reverse_sorted, 
  //     { sort again; goto next class }
  //   else
  //     {
  //       nexted = TRUE;
  //       for (j from l to r)
  // 	       if (for all j+ are reversed sorted)
  // 	         {
  // 	           swap j, j+1
  // 	           sort all j+ again
  // 	           break;
  // 	         }
  //     }
if (!nexted) return FALSE;
  return TRUE;
}

/********************
 Symmetry Class
 ********************/
class SymmetryClass
{
  PermSet Perm;
  bool BestInitialized;
  state BestPermutedState;

  // utilities
  void SetBestResult(int i, state* temp);
  void ResetBestResult() {BestInitialized = FALSE;};

public:
  // initializer
  SymmetryClass() : Perm(), BestInitialized(FALSE) {};
  ~SymmetryClass() {};

  void Normalize(state* s);

  void Exhaustive_Fast_Canonicalize(state *s);
  void Heuristic_Fast_Canonicalize(state *s);
  void Heuristic_Small_Mem_Canonicalize(state *s);
  void Heuristic_Fast_Normalize(state *s);

  void MultisetSort(state* s);
};


/********************
 Symmetry Class Members
 ********************/
void SymmetryClass::MultisetSort(state* s)
{
        mu_leaderUID.MultisetSort();
        mu_channel.MultisetSort();
        mu_p.MultisetSort();
        mu_hasLeader.MultisetSort();
        mu_election_done.MultisetSort();
}
void SymmetryClass::Normalize(state* s)
{
  switch (args->sym_alg.mode) {
  case argsym_alg::Exhaustive_Fast_Canonicalize:
    Exhaustive_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Canonicalize:
    Heuristic_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Small_Mem_Canonicalize:
    Heuristic_Small_Mem_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Normalize:
    Heuristic_Fast_Normalize(s);
    break;
  default:
    Heuristic_Fast_Canonicalize(s);
  }
}

/********************
 Permute and Canonicalize function for different types
 ********************/
void mu_1_UIDs::Permute(PermSet& Perm, int i) {};
void mu_1_UIDs::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_UIDs::Canonicalize(PermSet& Perm) {};
void mu_1_UIDs::SimpleLimit(PermSet& Perm) {};
void mu_1_UIDs::ArrayLimit(PermSet& Perm) {};
void mu_1_UIDs::Limit(PermSet& Perm) {};
void mu_1_UIDs::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_MsgTypes::Permute(PermSet& Perm, int i) {};
void mu_1_MsgTypes::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_MsgTypes::Canonicalize(PermSet& Perm) {};
void mu_1_MsgTypes::SimpleLimit(PermSet& Perm) {};
void mu_1_MsgTypes::ArrayLimit(PermSet& Perm) {};
void mu_1_MsgTypes::Limit(PermSet& Perm) {};
void mu_1_MsgTypes::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_NodeStates::Permute(PermSet& Perm, int i) {};
void mu_1_NodeStates::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_NodeStates::Canonicalize(PermSet& Perm) {};
void mu_1_NodeStates::SimpleLimit(PermSet& Perm) {};
void mu_1_NodeStates::ArrayLimit(PermSet& Perm) {};
void mu_1_NodeStates::Limit(PermSet& Perm) {};
void mu_1_NodeStates::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_Msg::Permute(PermSet& Perm, int i)
{
};
void mu_1_Msg::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Record with no scalarset variable\n"); };
void mu_1_Msg::Canonicalize(PermSet& Perm)
{
};
void mu_1_Msg::SimpleLimit(PermSet& Perm){}
void mu_1_Msg::ArrayLimit(PermSet& Perm){}
void mu_1_Msg::Limit(PermSet& Perm)
{
};
void mu_1_Msg::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_0::Permute(PermSet& Perm, int i)
{
};
void mu_1__type_0::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Record with no scalarset variable\n"); };
void mu_1__type_0::Canonicalize(PermSet& Perm)
{
};
void mu_1__type_0::SimpleLimit(PermSet& Perm){}
void mu_1__type_0::ArrayLimit(PermSet& Perm){}
void mu_1__type_0::Limit(PermSet& Perm)
{
};
void mu_1__type_0::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_1::Permute(PermSet& Perm, int i)
{
  static mu_1__type_1 temp("Permute_mu_1__type_1",-1);
  int j;
  for (j=0; j<6; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_1::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_1::Canonicalize(PermSet& Perm){};
void mu_1__type_1::SimpleLimit(PermSet& Perm){}
void mu_1__type_1::ArrayLimit(PermSet& Perm) {}
void mu_1__type_1::Limit(PermSet& Perm){}
void mu_1__type_1::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_2::Permute(PermSet& Perm, int i)
{
  static mu_1__type_2 temp("Permute_mu_1__type_2",-1);
  int j;
  for (j=0; j<6; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_2::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_2::Canonicalize(PermSet& Perm){};
void mu_1__type_2::SimpleLimit(PermSet& Perm){}
void mu_1__type_2::ArrayLimit(PermSet& Perm) {}
void mu_1__type_2::Limit(PermSet& Perm){}
void mu_1__type_2::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };

/********************
 Auxiliary function for error trace printing
 ********************/
bool match(state* ns, StatePtr p)
{
  int i;
  static PermSet Perm;
  static state temp;
  StateCopy(&temp, ns);
  if (args->symmetry_reduction.value)
    {
      if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize) {
        Perm.ResetToExplicit();
        for (i=0; i<Perm.count; i++)
          if (Perm.In(i))
            {
              if (ns != workingstate)
                  StateCopy(workingstate, ns);
              
              mu_leaderUID.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_leaderUID.MultisetSort();
              mu_channel.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_channel.MultisetSort();
              mu_p.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_p.MultisetSort();
              mu_hasLeader.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_hasLeader.MultisetSort();
              mu_election_done.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_election_done.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
      else {
        Perm.ResetToSimple();
        Perm.SimpleToOne();
        if (ns != workingstate)
          StateCopy(workingstate, ns);

          mu_leaderUID.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_leaderUID.MultisetSort();
          mu_channel.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_channel.MultisetSort();
          mu_p.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_p.MultisetSort();
          mu_hasLeader.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_hasLeader.MultisetSort();
          mu_election_done.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_election_done.MultisetSort();
        if (p.compare(workingstate)) {
          StateCopy(workingstate,&temp); return TRUE; }

        while (Perm.NextPermutation())
          {
            if (ns != workingstate)
              StateCopy(workingstate, ns);
              
              mu_leaderUID.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_leaderUID.MultisetSort();
              mu_channel.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_channel.MultisetSort();
              mu_p.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_p.MultisetSort();
              mu_hasLeader.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_hasLeader.MultisetSort();
              mu_election_done.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_election_done.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
    }
  if (!args->symmetry_reduction.value
      && args->multiset_reduction.value)
    {
      if (ns != workingstate)
          StateCopy(workingstate, ns);
      mu_leaderUID.MultisetSort();
      mu_channel.MultisetSort();
      mu_p.MultisetSort();
      mu_hasLeader.MultisetSort();
      mu_election_done.MultisetSort();
      if (p.compare(workingstate)) {
        StateCopy(workingstate,&temp); return TRUE; }
      StateCopy(workingstate,&temp);
      return FALSE;
    }
  return (p.compare(ns));
}

/********************
 Canonicalization by fast exhaustive generation of
 all permutations
 ********************/
void SymmetryClass::Exhaustive_Fast_Canonicalize(state* s)
{
  int i;
  static state temp;
  Perm.ResetToExplicit();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_leaderUID.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_leaderUID.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_channel.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_channel.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_p.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_p.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_hasLeader.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_hasLeader.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_election_done.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_election_done.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

};

/********************
 Canonicalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and fast exhaustive generation of
 all permutations for other variables
 ********************/
void SymmetryClass::Heuristic_Fast_Canonicalize(state* s)
{
  int i;
  static state temp;

  Perm.ResetToSimple();

};

/********************
 Canonicalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and fast exhaustive generation of
 all permutations for other variables
 and use less local memory
 ********************/
void SymmetryClass::Heuristic_Small_Mem_Canonicalize(state* s)
{
  unsigned long cycle;
  static state temp;

  Perm.ResetToSimple();

};

/********************
 Normalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and for all other variables, pick any remaining permutation
 ********************/
void SymmetryClass::Heuristic_Fast_Normalize(state* s)
{
  int i;
  static state temp;

  Perm.ResetToSimple();

};

/********************
  Include
 ********************/
#include "mu_epilog.hpp"
