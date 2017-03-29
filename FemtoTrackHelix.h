#ifndef FEMTO_TRACK_HELIX_H
#define FEMTO_TRACK_HELIX_H

#include "TObject.h"

class FemtoTrackHelix : public TObject
{
public:
	FemtoTrackHelix(){ init(); }
	~FemtoTrackHelix(){ }

	virtual void init(){
		this->mPar[0] = 0;
		this->mPar[1] = 0;
		this->mPar[2] = 0;
		this->mPar[3] = 0;
		this->mPar[4] = 0;
		this->mPar[5] = 0;
		
		this->mMap0 = 0;
		this->mMap1 = 0;
	}
	void copy( FemtoTrackHelix * that){
		this->mPar[0] = that->mPar[0];
		this->mPar[1] = that->mPar[1];
		this->mPar[2] = that->mPar[2];
		this->mPar[3] = that->mPar[3];
		this->mPar[4] = that->mPar[4];
		this->mPar[5] = that->mPar[5];

		this->mMap0 = that->mMap0;
		this->mMap1 = that->mMap1;
	}

	Float_t mPar[6];
	UInt_t mMap0;
	UInt_t mMap1;
	ClassDef( FemtoTrackHelix, 2 )
};

#endif