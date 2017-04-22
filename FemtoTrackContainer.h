#ifndef FEMTO_TRACK_CONTAINER_H
#define FEMTO_TRACK_CONTAINER_H

#include "FemtoDstFormat/FemtoTrack.h"
#include "FemtoDstFormat/FemtoMcTrack.h"
#include "FemtoDstFormat/FemtoMtdPidTraits.h"

class FemtoTrackContainer {
public:
	FemtoTrack *_track=nullptr;
	FemtoMcTrack *_mcTrack=nullptr;
	FemtoMtdPidTraits *_mtdPid=nullptr;
};

#endif