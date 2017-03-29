#ifndef FEMTO_BTOF_PID_TRAITS_H
#define FEMTO_BTOF_PID_TRAITS_H

#include "TObject.h"

class FemtoBTofPidTraits : public TObject
{
public:
	FemtoBTofPidTraits(){ }
	~FemtoBTofPidTraits(){ }

	void copy( FemtoBTofPidTraits * that){
		this->mBTofBeta      = that->mBTofBeta;
		this->mBTofYLocal    = that->mBTofYLocal;
		this->mBTofZLocal    = that->mBTofZLocal;
		this->mBTofMatchFlag = that->mBTofMatchFlag;
	}

	UShort_t mBTofBeta;			// beta * 20000
	Short_t  mBTofYLocal;		// ylocal * 1000
	Short_t  mBTofZLocal;		// zlocal * 1000
	UChar_t  mBTofMatchFlag;	// 0 - no match, 1 - one-to-one, 2 - one-to-multiple
	
	ClassDef( FemtoBTofPidTraits, 1 )
};

#endif