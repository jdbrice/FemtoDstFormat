#ifndef FEMTO_MTD_PID_TRAITS_H
#define FEMTO_MTD_PID_TRAITS_H

#include "TObject.h"

class FemtoMtdPidTraits : public TObject
{
public:
	FemtoMtdPidTraits(){ }
	~FemtoMtdPidTraits(){ }

	void copy( FemtoMtdPidTraits * that ){
		this->mDeltaY            = that->mDeltaY;
		this->mDeltaZ            = that->mDeltaZ;
		this->mDeltaTimeOfFlight = that->mDeltaTimeOfFlight;
		this->mMatchFlag         = that->mMatchFlag;
		this->mMtdHitChan        = that->mMtdHitChan;
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

	ClassDef( FemtoMtdPidTraits, 2 )
};

#endif