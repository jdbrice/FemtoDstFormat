#ifndef FEMTO_BTOF_PID_TRAITS_H
#define FEMTO_BTOF_PID_TRAITS_H

#include "TObject.h"
#include "FemtoDstBranch.h"

class FemtoBTofPidTraits : public TObject, public FemtoDstBranch
{
public:
	virtual const char* name() const { return "FemtoBTofPidTraits"; }
	FemtoBTofPidTraits(){ reset(); }
	~FemtoBTofPidTraits(){ }

	void reset(){
		this->mBTofBeta      = 0.0;
		this->mBTofYLocal    = 0.0;
		this->mBTofZLocal    = 0.0;
		this->mBTofMatchFlag = 0.0;
	}
	void copy( FemtoBTofPidTraits * that){
		this->mBTofBeta      = that->mBTofBeta;
		this->mBTofYLocal    = that->mBTofYLocal;
		this->mBTofZLocal    = that->mBTofZLocal;
		this->mBTofMatchFlag = that->mBTofMatchFlag;
	}

	float yLocal( ) {return this->mBTofYLocal / 1000.0;}
	void yLocal( float ylocal ){this->mBTofYLocal = ylocal * 1000;}
	float zLocal( ) {return this->mBTofZLocal / 1000.0;}
	void zLocal( float zlocal ){this->mBTofZLocal = zlocal * 1000;}

	float beta( ) {return this->mBTofBeta / 20000.0;}
	void beta( float tmp ){this->mBTofZLocal = tmp * 20000;}

	void matchFlag( int tmp ){ this->mBTofMatchFlag = tmp; }
	int matchFlag() { return this->mBTofMatchFlag; }

	UShort_t mBTofBeta;			// beta * 20000
	Short_t  mBTofYLocal;		// ylocal * 1000
	Short_t  mBTofZLocal;		// zlocal * 1000
	UChar_t  mBTofMatchFlag;	// 0 - no match, 1 - one-to-one, 2 - one-to-multiple
	
	ClassDef( FemtoBTofPidTraits, 1 )
};

#endif