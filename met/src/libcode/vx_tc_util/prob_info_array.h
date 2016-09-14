// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
// ** Copyright UCAR (c) 1992 - 2016
// ** University Corporation for Atmospheric Research (UCAR)
// ** National Center for Atmospheric Research (NCAR)
// ** Research Applications Lab (RAL)
// ** P.O.Box 3000, Boulder, Colorado, 80307-3000, USA
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*

////////////////////////////////////////////////////////////////////////

#ifndef  __VX_PROB_INFO_ARRAY_H__
#define  __VX_PROB_INFO_ARRAY_H__

////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>

#include "atcf_prob_line.h"
#include "prob_info_base.h"
#include "prob_ri_info.h"

#include "vx_util.h"

////////////////////////////////////////////////////////////////////////
//
// ProbInfoArray class stores a vector of ProbInfoBase class pointers.
//
////////////////////////////////////////////////////////////////////////

class ProbInfoArray {

   protected:

      void init_from_scratch();
      void assign(const ProbInfoArray &);

      vector<ProbRIInfo> ProbRI;

   public:

      ProbInfoArray();
     ~ProbInfoArray();
      ProbInfoArray(const ProbInfoArray &);
      ProbInfoArray & operator=(const ProbInfoArray &);

      void clear();

      void         dump(ostream &, int = 0) const;
      ConcatString serialize()              const;
      ConcatString serialize_r(int = 0)     const;

         //
         //  get stuff
         //

      int n_probs() const;
      const ProbInfoBase * operator[](int) const;

      int n_prob_ri() const;
      const ProbRIInfo & prob_ri(int) const;

         //
         //  do stuff
         //

      bool add(const ATCFProbLine &, bool check_dup = false);
      void add(const ProbRIInfo &);

};

////////////////////////////////////////////////////////////////////////

inline int ProbInfoArray::n_probs()   const { return(ProbRI.size()); }
inline int ProbInfoArray::n_prob_ri() const { return(ProbRI.size()); }

////////////////////////////////////////////////////////////////////////

#endif   /*  __VX_PROB_INFO_ARRAY_H__  */

////////////////////////////////////////////////////////////////////////