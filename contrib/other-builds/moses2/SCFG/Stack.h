#pragma once
#include <boost/unordered_map.hpp>
#include "../HypothesisColl.h"
#include "../Recycler.h"
#include "Word.h"

namespace Moses2
{
class HypothesisBase;
class ArcLists;

namespace SCFG
{
class Hypothesis;
class Manager;

class Stack
{
public:
  typedef boost::unordered_map<SCFG::Word, Moses2::HypothesisColl*> Coll;

  Stack(const Manager &mgr);

  Coll &GetColl()
  {
    return m_coll;
  }
  const Coll &GetColl() const
  {
    return m_coll;
  }

  size_t GetSize() const;

  StackAdd Add(SCFG::Hypothesis *hypo, Recycler<HypothesisBase*> &hypoRecycle,
      ArcLists &arcLists);

protected:
  const Manager &m_mgr;
  Coll m_coll;

  Moses2::HypothesisColl &GetMiniStack(const SCFG::Word &key);

};

}

}

