#ifndef FEMTO_MTD_PID_TRAITS_H
#define FEMTO_MTD_PID_TRAITS_H

#include "TObject.h"
#include "FemtoDstBranch.h"

class FemtoMtdPidTraits : public TObject, public FemtoDstBranch
{
public:
	virtual const char* classname() const {return "FemtoMtdPidTraits"; }
	FemtoMtdPidTraits(){ }
	~FemtoMtdPidTraits(){ }

	void reset(){
		this->mDeltaY            = 0;
		this->mDeltaZ            = 0;
		this->mDeltaTimeOfFlight = 0;
		this->mMatchFlag         = 0;
		this->mMtdHitChan        = 0;
		this->mTriggerFlag       = 0;
		this->mIdTruth           = -1;
	}

	void copy( FemtoMtdPidTraits * that ){
		this->mDeltaY            = that->mDeltaY;
		this->mDeltaZ            = that->mDeltaZ;
		this->mDeltaTimeOfFlight = that->mDeltaTimeOfFlight;
		this->mMatchFlag         = that->mMatchFlag;
		this->mMtdHitChan        = that->mMtdHitChan;
		this->mTriggerFlag       = that->mTriggerFlag;
		this->mIdTruth           = that->mIdTruth;
	}

	int backleg( ){
		return mMtdHitChan / 60;
	}
	int module( ){
		return ( mMtdHitChan % 60 ) / 12;
	}
	int cell() {
		return mMtdHitChan % 12;
	}

	Float_t   mDeltaY;					// DeltaY between matched track-hit pair
	Float_t   mDeltaZ;					// DeltaZ between matched track-hit pair
	Float_t   mDeltaTimeOfFlight;		// Difference between measured and expected time-of-flight
	Char_t    mMatchFlag;				// Matching flag indicating multiple matches
	Short_t   mMtdHitChan;				// (backleg-1) * 60 + (module-1) * 12 + cell
	Char_t    mTriggerFlag;				// Trigger Flag from MtdHit struct -1 = unset, otherwise value 
	Short_t   mIdTruth;					// the idTruth used to id which MCTrack caused this info, only used in MC

	ClassDef( FemtoMtdPidTraits, 3 )
};

#endif