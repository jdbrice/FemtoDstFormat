#ifndef FEMTO_TRACK_H
#define FEMTO_TRACK_H

#include "TObject.h"
#include "TVector3.h"

#include "FemtoDstBranch.h"

class FemtoTrack : public TObject, public FemtoDstBranch
{
public:
	virtual const char* name() const { return "FemtoTrack"; }
	FemtoTrack(){
		reset();
	}
	~FemtoTrack(){
	}

	void reset(){
		mPMomentum_mX1      = 0.0;
		mPMomentum_mX2      = 0.0;
		mPMomentum_mX3      = 0.0;
		mId                 = 0.0;
		mDedx               = 0.0;
		mNHitsFit           = 0.0;
		mNHitsMax           = 0.0;
		mNHitsDedx          = 0.0;
		mNSigmaPion         = 0.0;
		mNSigmaKaon         = 0.0;
		mNSigmaProton       = 0.0;
		mNSigmaElectron     = 0.0;
		mDCA                = 0.0;
		
		// pidTraits
		mBTofPidTraitsIndex = -1;
		mMtdPidTraitsIndex  = -1;
		mEmcPidTraitsIndex  = -1;
		mHelixIndex         = -1;
	}

	void copy( FemtoTrack * that ) {
		this->mPMomentum_mX1      = that->mPMomentum_mX1;
		this->mPMomentum_mX2      = that->mPMomentum_mX2;
		this->mPMomentum_mX3      = that->mPMomentum_mX3;
		this->mId                 = that->mId;
		this->mDedx               = that->mDedx;
		this->mNHitsFit           = that->mNHitsFit;
		this->mNHitsMax           = that->mNHitsMax;
		this->mNHitsDedx          = that->mNHitsDedx;
		this->mNSigmaPion         = that->mNSigmaPion;
		this->mNSigmaKaon         = that->mNSigmaKaon;
		this->mNSigmaProton       = that->mNSigmaProton;
		this->mNSigmaElectron     = that->mNSigmaElectron;
		this->mDCA                = that->mDCA;

		this->mBTofPidTraitsIndex = that->mBTofPidTraitsIndex;
		this->mMtdPidTraitsIndex  = that->mMtdPidTraitsIndex;
		this->mEmcPidTraitsIndex  = that->mEmcPidTraitsIndex;
		this->mHelixIndex         = that->mHelixIndex;
	}

	int charge() { return mNHitsFit > 0 ? 1 : -1; }
	float nSigmaPion() { return mNSigmaPion / 100.0; }
	void nSigmaPion( float tmp ){ this->mNSigmaPion = tmp * 100; }
	float nSigmaKaon() { return mNSigmaKaon / 100.0; }
	void nSigmaKaon( float tmp ){ this->mNSigmaKaon = tmp * 100; }
	float nSigmaProton() { return mNSigmaProton / 100.0; }
	void nSigmaProton( float tmp ){ this->mNSigmaProton = tmp * 100; }
	float nSigmaElectron() { return mNSigmaElectron / 100.0; }
	void nSigmaElectron( float tmp ){ this->mNSigmaElectron = tmp * 100; }

	float gDCA() { return mDCA / 1000.0; }
	void gDCA( float dca ) 
	{ 
		if (dca < 0 ) dca = 50;		// dont default to zero, something is wrong 
		this->mDCA = dca * 1000; 
	}

	TVector3 pMomentum() { return TVector3( mPMomentum_mX1, mPMomentum_mX2, mPMomentum_mX3 ); }
	void pMomentum( float pX, float pY, float pZ ) {
		this->mPMomentum_mX1 = pX;
		this->mPMomentum_mX2 = pY;
		this->mPMomentum_mX3 = pZ;
	}
	float dEdx() { return mDedx / 1000.0; }
	void dEdx( float tmp ) { this->mDedx = tmp * 1000; }
	

	Float_t 	mPMomentum_mX1;					// primary track px
	Float_t 	mPMomentum_mX2;					// primary track py
	Float_t 	mPMomentum_mX3;					// primary track pz
	UShort_t 	mId;				// track Id
	UShort_t 	mDedx;				// dEdx*1000
	Char_t 		mNHitsFit;			// q*nHitsFit - TPC
	Char_t 		mNHitsMax;			// nHitsMax - TPC
	UChar_t 	mNHitsDedx;			// nHitsDedx - TPC
	Short_t 	mNSigmaPion;		// nsigmaPi * 100
	Short_t 	mNSigmaKaon;		// nsigmaK * 100
	Short_t 	mNSigmaProton;		// nsigmaP * 100
	Short_t 	mNSigmaElectron;	// nsigmaE * 100
	UShort_t 	mDCA;				// global track gDCA * 1000
	
	// pidTraits
	Short_t 	mBTofPidTraitsIndex; // index of the BTOF pidTratis in the event
	Short_t 	mMtdPidTraitsIndex;  // index of the MTD pidTratis in the event
	Short_t 	mEmcPidTraitsIndex;  // index of the EMC pidTratis in the event
	Short_t 	mHelixIndex;		 // index of associated Track Helix
	
	ClassDef( FemtoTrack, 3 )
};

#endif