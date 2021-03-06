// -*-c++-*-
//
// Autogenerated by mkevent.pl
//

#ifndef _LIBTAME_EVENT_AG_H_
#define _LIBTAME_EVENT_AG_H_

#include "tame_event.h"
#include "tame_closure.h"
#include "tame_rendezvous.h"

template<>
class _event<> :
     public _event_cancel_base,
     public callback<void>
{
public:
  _event (const _tame_slot_set<> &rs, const char *loc)
   : _event_cancel_base (loc),
     callback<void> (CALLBACK_ARGS(loc))
    {}

  _tame_slot_set<> slot_set() const
  { return _tame_slot_set<> (); }  void slot_set_reassign (const _tame_slot_set<> &ss) {}

  void trigger ()
  {
    if (can_trigger ()) {
      _performing = true;
      _event_hold_t hold = mkref (this);
      if (perform_action (this, this->_loc, _reuse)) {
        _cleared = true;
      }
      _performing = false;
    }
  }
  void operator() () { trigger (); }

};

template<class A>
class _event_impl<A> :
     public _event<>
{
public:
  _event_impl (const A &action, const _tame_slot_set<> &rs, const char *loc)
    : _event<> (rs, loc),
      _action (action) {}

  ~_event_impl () { if (!this->_cleared) clear_action (); }

  bool perform_action (_event_cancel_base *e, const char *loc, bool reuse)
  { return _action.perform (e, loc, reuse); }
  void clear_action () { _action.clear (this); }

private:
  A _action;
};

event<>::ref
_mkevent_rs (ptr<closure_t> c, const char *loc, const _tame_slot_set<> &rs, rendezvous_t<> &rv)
;

event<>::ref
_mkevent (ptr<closure_t> c, const char *loc, rendezvous_t<> &rv)
;

template<class W1>
typename event<>::ref
_mkevent_rs (ptr<closure_t> c, const char *loc, const _tame_slot_set<> &rs, rendezvous_t<W1> &rv, const W1 &w1)
{
  return rv._ti_mkevent (c,
                        loc,
                        value_set_t<W1> (w1),
                        rs);
}

template<class W1>
typename event<>::ref
_mkevent (ptr<closure_t> c, const char *loc, rendezvous_t<W1> &rv, const W1 &w1)
{
  return _mkevent_rs (c,
                      loc,
                      _tame_slot_set<> (),
                      rv,
                      w1);
}

template<class W1, class W2>
typename event<>::ref
_mkevent_rs (ptr<closure_t> c, const char *loc, const _tame_slot_set<> &rs, rendezvous_t<W1, W2> &rv, const W1 &w1, const W2 &w2)
{
  return rv._ti_mkevent (c,
                        loc,
                        value_set_t<W1, W2> (w1, w2),
                        rs);
}

template<class W1, class W2>
typename event<>::ref
_mkevent (ptr<closure_t> c, const char *loc, rendezvous_t<W1, W2> &rv, const W1 &w1, const W2 &w2)
{
  return _mkevent_rs (c,
                      loc,
                      _tame_slot_set<> (),
                      rv,
                      w1,
                      w2);
}

template<class W1, class W2, class W3>
typename event<>::ref
_mkevent_rs (ptr<closure_t> c, const char *loc, const _tame_slot_set<> &rs, rendezvous_t<W1, W2, W3> &rv, const W1 &w1, const W2 &w2, const W3 &w3)
{
  return rv._ti_mkevent (c,
                        loc,
                        value_set_t<W1, W2, W3> (w1, w2, w3),
                        rs);
}

template<class W1, class W2, class W3>
typename event<>::ref
_mkevent (ptr<closure_t> c, const char *loc, rendezvous_t<W1, W2, W3> &rv, const W1 &w1, const W2 &w2, const W3 &w3)
{
  return _mkevent_rs (c,
                      loc,
                      _tame_slot_set<> (),
                      rv,
                      w1,
                      w2,
                      w3);
}

template<class T1>
class _event<T1> :
     public _event_cancel_base,
     public callback<void, T1>
{
public:
  _event (const _tame_slot_set<T1> &rs, const char *loc)
   : _event_cancel_base (loc),
     callback<void, T1> (CALLBACK_ARGS(loc)),
    _slot_set (rs)
    {}

  const _tame_slot_set<T1> &slot_set() const
  { return _slot_set; }
  void slot_set_reassign (const _tame_slot_set<T1> &ss) { _slot_set = ss; }

  void trigger (const T1 &t1)
  {
    if (can_trigger ()) {
      _performing = true;
      _event_hold_t hold = mkref (this);
      _slot_set.assign (t1);
      if (perform_action (this, this->_loc, _reuse)) {
        _cleared = true;
      }
      _performing = false;
    }
  }
  void operator() (T1 t1) { trigger (t1); }
private:
  _tame_slot_set<T1> _slot_set;

};

template<class A, class T1>
class _event_impl<A, T1> :
     public _event<T1>
{
public:
  _event_impl (const A &action, const _tame_slot_set<T1> &rs, const char *loc)
    : _event<T1> (rs, loc),
      _action (action) {}

  ~_event_impl () { if (!this->_cleared) clear_action (); }

  bool perform_action (_event_cancel_base *e, const char *loc, bool reuse)
  { return _action.perform (e, loc, reuse); }
  void clear_action () { _action.clear (this); }

private:
  A _action;
};

template<class C, class T1>
typename event<T1>::ref
_mkevent (const closure_wrapper<C> &c, const char *loc, T1 &t1)
{
  return _mkevent_implicit_rv (c.closure (), loc, _tame_slot_set<T1> (&t1));
}

template<class T1>
typename event<T1>::ref
_mkevent_rs (ptr<closure_t> c, const char *loc, const _tame_slot_set<T1> &rs, rendezvous_t<> &rv)
{
  return rv._ti_mkevent (c,
                        loc,
                        value_set_t<> (),
                        rs);
}

template<class T1>
typename event<T1>::ref
_mkevent (ptr<closure_t> c, const char *loc, rendezvous_t<> &rv, T1 &t1)
{
  return _mkevent_rs (c,
                      loc,
                      _tame_slot_set<T1> (&t1),
                      rv);
}

template<class W1, class T1>
typename event<T1>::ref
_mkevent_rs (ptr<closure_t> c, const char *loc, const _tame_slot_set<T1> &rs, rendezvous_t<W1> &rv, const W1 &w1)
{
  return rv._ti_mkevent (c,
                        loc,
                        value_set_t<W1> (w1),
                        rs);
}

template<class W1, class T1>
typename event<T1>::ref
_mkevent (ptr<closure_t> c, const char *loc, rendezvous_t<W1> &rv, const W1 &w1, T1 &t1)
{
  return _mkevent_rs (c,
                      loc,
                      _tame_slot_set<T1> (&t1),
                      rv,
                      w1);
}

template<class W1, class W2, class T1>
typename event<T1>::ref
_mkevent_rs (ptr<closure_t> c, const char *loc, const _tame_slot_set<T1> &rs, rendezvous_t<W1, W2> &rv, const W1 &w1, const W2 &w2)
{
  return rv._ti_mkevent (c,
                        loc,
                        value_set_t<W1, W2> (w1, w2),
                        rs);
}

template<class W1, class W2, class T1>
typename event<T1>::ref
_mkevent (ptr<closure_t> c, const char *loc, rendezvous_t<W1, W2> &rv, const W1 &w1, const W2 &w2, T1 &t1)
{
  return _mkevent_rs (c,
                      loc,
                      _tame_slot_set<T1> (&t1),
                      rv,
                      w1,
                      w2);
}

template<class W1, class W2, class W3, class T1>
typename event<T1>::ref
_mkevent_rs (ptr<closure_t> c, const char *loc, const _tame_slot_set<T1> &rs, rendezvous_t<W1, W2, W3> &rv, const W1 &w1, const W2 &w2, const W3 &w3)
{
  return rv._ti_mkevent (c,
                        loc,
                        value_set_t<W1, W2, W3> (w1, w2, w3),
                        rs);
}

template<class W1, class W2, class W3, class T1>
typename event<T1>::ref
_mkevent (ptr<closure_t> c, const char *loc, rendezvous_t<W1, W2, W3> &rv, const W1 &w1, const W2 &w2, const W3 &w3, T1 &t1)
{
  return _mkevent_rs (c,
                      loc,
                      _tame_slot_set<T1> (&t1),
                      rv,
                      w1,
                      w2,
                      w3);
}

template<class T1, class T2>
class _event<T1, T2> :
     public _event_cancel_base,
     public callback<void, T1, T2>
{
public:
  _event (const _tame_slot_set<T1, T2> &rs, const char *loc)
   : _event_cancel_base (loc),
     callback<void, T1, T2> (CALLBACK_ARGS(loc)),
    _slot_set (rs)
    {}

  const _tame_slot_set<T1, T2> &slot_set() const
  { return _slot_set; }
  void slot_set_reassign (const _tame_slot_set<T1, T2> &ss) { _slot_set = ss; }

  void trigger (const T1 &t1, const T2 &t2)
  {
    if (can_trigger ()) {
      _performing = true;
      _event_hold_t hold = mkref (this);
      _slot_set.assign (t1, t2);
      if (perform_action (this, this->_loc, _reuse)) {
        _cleared = true;
      }
      _performing = false;
    }
  }
  void operator() (T1 t1, T2 t2) { trigger (t1, t2); }
private:
  _tame_slot_set<T1, T2> _slot_set;

};

template<class A, class T1, class T2>
class _event_impl<A, T1, T2> :
     public _event<T1, T2>
{
public:
  _event_impl (const A &action, const _tame_slot_set<T1, T2> &rs, const char *loc)
    : _event<T1, T2> (rs, loc),
      _action (action) {}

  ~_event_impl () { if (!this->_cleared) clear_action (); }

  bool perform_action (_event_cancel_base *e, const char *loc, bool reuse)
  { return _action.perform (e, loc, reuse); }
  void clear_action () { _action.clear (this); }

private:
  A _action;
};

template<class C, class T1, class T2>
typename event<T1, T2>::ref
_mkevent (const closure_wrapper<C> &c, const char *loc, T1 &t1, T2 &t2)
{
  return _mkevent_implicit_rv (c.closure (), loc, _tame_slot_set<T1, T2> (&t1, &t2));
}

template<class T1, class T2>
typename event<T1, T2>::ref
_mkevent_rs (ptr<closure_t> c, const char *loc, const _tame_slot_set<T1, T2> &rs, rendezvous_t<> &rv)
{
  return rv._ti_mkevent (c,
                        loc,
                        value_set_t<> (),
                        rs);
}

template<class T1, class T2>
typename event<T1, T2>::ref
_mkevent (ptr<closure_t> c, const char *loc, rendezvous_t<> &rv, T1 &t1, T2 &t2)
{
  return _mkevent_rs (c,
                      loc,
                      _tame_slot_set<T1, T2> (&t1, &t2),
                      rv);
}

template<class W1, class T1, class T2>
typename event<T1, T2>::ref
_mkevent_rs (ptr<closure_t> c, const char *loc, const _tame_slot_set<T1, T2> &rs, rendezvous_t<W1> &rv, const W1 &w1)
{
  return rv._ti_mkevent (c,
                        loc,
                        value_set_t<W1> (w1),
                        rs);
}

template<class W1, class T1, class T2>
typename event<T1, T2>::ref
_mkevent (ptr<closure_t> c, const char *loc, rendezvous_t<W1> &rv, const W1 &w1, T1 &t1, T2 &t2)
{
  return _mkevent_rs (c,
                      loc,
                      _tame_slot_set<T1, T2> (&t1, &t2),
                      rv,
                      w1);
}

template<class W1, class W2, class T1, class T2>
typename event<T1, T2>::ref
_mkevent_rs (ptr<closure_t> c, const char *loc, const _tame_slot_set<T1, T2> &rs, rendezvous_t<W1, W2> &rv, const W1 &w1, const W2 &w2)
{
  return rv._ti_mkevent (c,
                        loc,
                        value_set_t<W1, W2> (w1, w2),
                        rs);
}

template<class W1, class W2, class T1, class T2>
typename event<T1, T2>::ref
_mkevent (ptr<closure_t> c, const char *loc, rendezvous_t<W1, W2> &rv, const W1 &w1, const W2 &w2, T1 &t1, T2 &t2)
{
  return _mkevent_rs (c,
                      loc,
                      _tame_slot_set<T1, T2> (&t1, &t2),
                      rv,
                      w1,
                      w2);
}

template<class W1, class W2, class W3, class T1, class T2>
typename event<T1, T2>::ref
_mkevent_rs (ptr<closure_t> c, const char *loc, const _tame_slot_set<T1, T2> &rs, rendezvous_t<W1, W2, W3> &rv, const W1 &w1, const W2 &w2, const W3 &w3)
{
  return rv._ti_mkevent (c,
                        loc,
                        value_set_t<W1, W2, W3> (w1, w2, w3),
                        rs);
}

template<class W1, class W2, class W3, class T1, class T2>
typename event<T1, T2>::ref
_mkevent (ptr<closure_t> c, const char *loc, rendezvous_t<W1, W2, W3> &rv, const W1 &w1, const W2 &w2, const W3 &w3, T1 &t1, T2 &t2)
{
  return _mkevent_rs (c,
                      loc,
                      _tame_slot_set<T1, T2> (&t1, &t2),
                      rv,
                      w1,
                      w2,
                      w3);
}

template<class T1, class T2, class T3>
class _event<T1, T2, T3> :
     public _event_cancel_base,
     public callback<void, T1, T2, T3>
{
public:
  _event (const _tame_slot_set<T1, T2, T3> &rs, const char *loc)
   : _event_cancel_base (loc),
     callback<void, T1, T2, T3> (CALLBACK_ARGS(loc)),
    _slot_set (rs)
    {}

  const _tame_slot_set<T1, T2, T3> &slot_set() const
  { return _slot_set; }
  void slot_set_reassign (const _tame_slot_set<T1, T2, T3> &ss) { _slot_set = ss; }

  void trigger (const T1 &t1, const T2 &t2, const T3 &t3)
  {
    if (can_trigger ()) {
      _performing = true;
      _event_hold_t hold = mkref (this);
      _slot_set.assign (t1, t2, t3);
      if (perform_action (this, this->_loc, _reuse)) {
        _cleared = true;
      }
      _performing = false;
    }
  }
  void operator() (T1 t1, T2 t2, T3 t3) { trigger (t1, t2, t3); }
private:
  _tame_slot_set<T1, T2, T3> _slot_set;

};

template<class A, class T1, class T2, class T3>
class _event_impl<A, T1, T2, T3> :
     public _event<T1, T2, T3>
{
public:
  _event_impl (const A &action, const _tame_slot_set<T1, T2, T3> &rs, const char *loc)
    : _event<T1, T2, T3> (rs, loc),
      _action (action) {}

  ~_event_impl () { if (!this->_cleared) clear_action (); }

  bool perform_action (_event_cancel_base *e, const char *loc, bool reuse)
  { return _action.perform (e, loc, reuse); }
  void clear_action () { _action.clear (this); }

private:
  A _action;
};

template<class C, class T1, class T2, class T3>
typename event<T1, T2, T3>::ref
_mkevent (const closure_wrapper<C> &c, const char *loc, T1 &t1, T2 &t2, T3 &t3)
{
  return _mkevent_implicit_rv (c.closure (), loc, _tame_slot_set<T1, T2, T3> (&t1, &t2, &t3));
}

template<class T1, class T2, class T3>
typename event<T1, T2, T3>::ref
_mkevent_rs (ptr<closure_t> c, const char *loc, const _tame_slot_set<T1, T2, T3> &rs, rendezvous_t<> &rv)
{
  return rv._ti_mkevent (c,
                        loc,
                        value_set_t<> (),
                        rs);
}

template<class T1, class T2, class T3>
typename event<T1, T2, T3>::ref
_mkevent (ptr<closure_t> c, const char *loc, rendezvous_t<> &rv, T1 &t1, T2 &t2, T3 &t3)
{
  return _mkevent_rs (c,
                      loc,
                      _tame_slot_set<T1, T2, T3> (&t1, &t2, &t3),
                      rv);
}

template<class W1, class T1, class T2, class T3>
typename event<T1, T2, T3>::ref
_mkevent_rs (ptr<closure_t> c, const char *loc, const _tame_slot_set<T1, T2, T3> &rs, rendezvous_t<W1> &rv, const W1 &w1)
{
  return rv._ti_mkevent (c,
                        loc,
                        value_set_t<W1> (w1),
                        rs);
}

template<class W1, class T1, class T2, class T3>
typename event<T1, T2, T3>::ref
_mkevent (ptr<closure_t> c, const char *loc, rendezvous_t<W1> &rv, const W1 &w1, T1 &t1, T2 &t2, T3 &t3)
{
  return _mkevent_rs (c,
                      loc,
                      _tame_slot_set<T1, T2, T3> (&t1, &t2, &t3),
                      rv,
                      w1);
}

template<class W1, class W2, class T1, class T2, class T3>
typename event<T1, T2, T3>::ref
_mkevent_rs (ptr<closure_t> c, const char *loc, const _tame_slot_set<T1, T2, T3> &rs, rendezvous_t<W1, W2> &rv, const W1 &w1, const W2 &w2)
{
  return rv._ti_mkevent (c,
                        loc,
                        value_set_t<W1, W2> (w1, w2),
                        rs);
}

template<class W1, class W2, class T1, class T2, class T3>
typename event<T1, T2, T3>::ref
_mkevent (ptr<closure_t> c, const char *loc, rendezvous_t<W1, W2> &rv, const W1 &w1, const W2 &w2, T1 &t1, T2 &t2, T3 &t3)
{
  return _mkevent_rs (c,
                      loc,
                      _tame_slot_set<T1, T2, T3> (&t1, &t2, &t3),
                      rv,
                      w1,
                      w2);
}

template<class W1, class W2, class W3, class T1, class T2, class T3>
typename event<T1, T2, T3>::ref
_mkevent_rs (ptr<closure_t> c, const char *loc, const _tame_slot_set<T1, T2, T3> &rs, rendezvous_t<W1, W2, W3> &rv, const W1 &w1, const W2 &w2, const W3 &w3)
{
  return rv._ti_mkevent (c,
                        loc,
                        value_set_t<W1, W2, W3> (w1, w2, w3),
                        rs);
}

template<class W1, class W2, class W3, class T1, class T2, class T3>
typename event<T1, T2, T3>::ref
_mkevent (ptr<closure_t> c, const char *loc, rendezvous_t<W1, W2, W3> &rv, const W1 &w1, const W2 &w2, const W3 &w3, T1 &t1, T2 &t2, T3 &t3)
{
  return _mkevent_rs (c,
                      loc,
                      _tame_slot_set<T1, T2, T3> (&t1, &t2, &t3),
                      rv,
                      w1,
                      w2,
                      w3);
}

#endif // _LIBTAME_EVENT_AG_H_ 
