#ifndef FEMTO_MC_TRACK_H 
#define FEMTO_MC_TRACK_H 
 
#include "TObject.h" 
#include "TVector3.h" 
 
#include "FemtoDstBranch.h" 
 
class FemtoMcTrack : public TObject, public FemtoDstBranch 
{ 
public: 
  virtual const char* name() const { return "FemtoMcTrack"; } 
  FemtoMcTrack(){ 
    reset(); 
  } 
  ~FemtoMcTrack(){ 
  } 
 
  void reset(){ 
    mPMomentum_mX1        = 0; 
    mPMomentum_mX2        = 0; 
    mPMomentum_mX3        = 0; 
    mId                   = 0; 
    mGeantPID             = 0; 
    mCharge               = 0; 
    mEnergy               = 0; 
    mNHits                = 0; 
 
    mParentMcTrackIndex   = -1; 
    mAssociatedTrackIndex = -1; 
    mStartVertexIndex     = -1; 
    mStopVertexIndex      = -1; 
  } 
 
  void copy( FemtoMcTrack * that ) { 
    this->mPMomentum_mX1    = that->mPMomentum_mX1; 
    this->mPMomentum_mX2    = that->mPMomentum_mX2; 
    this->mPMomentum_mX3    = that->mPMomentum_mX3; 
    this->mId               = that->mId; 
    this->mGeantPID         = that->mGeantPID; 
    this->mCharge           = that->mCharge; 
    this->mEnergy           = that->mEnergy; 
    this->mNHits            = that->mNHits; 
 
    mParentMcTrackIndex     = that->mParentMcTrackIndex; 
    mAssociatedTrackIndex   = that->mAssociatedTrackIndex; 
    this->mStartVertexIndex = that->mStartVertexIndex; 
    this->mStopVertexIndex  = that->mStopVertexIndex; 
  } 
 
  TVector3 pMomentum() { return TVector3( mPMomentum_mX1, mPMomentum_mX2, mPMomentum_mX3 ); } 
  void pMomentum( float pX, float pY, float pZ ) { 
    this->mPMomentum_mX1 = pX; 
    this->mPMomentum_mX2 = pY; 
    this->mPMomentum_mX3 = pZ; 
  } 
   
   
 
  Float_t   mPMomentum_mX1;          // primary track px 
  Float_t   mPMomentum_mX2;          // primary track py 
  Float_t   mPMomentum_mX3;          // primary track pz 
  UShort_t   mId;        // track Id 
  UShort_t   mGeantPID; 
  Char_t     mCharge; 
  Float_t   mEnergy; 
  Char_t     mNHits; 
 
  UShort_t   mParentMcTrackIndex; 
  UShort_t   mAssociatedTrackIndex; 
  UShort_t   mStartVertexIndex; 
  UShort_t   mStopVertexIndex; 
 
   
  ClassDef( FemtoMcTrack, 1 ) 
}; 
 
#endif