#ifndef FEMTO_EVENT_WRITER_H
#define FEMTO_EVENT_WRITER_H

#include <memory>
// #include "FemtoDstFormat/FemtoEvent.h"
#include "TTree.h"

template <class BranchType>
class FemtoBranchWriter
{
public:
	FemtoBranchWriter() {}
	~FemtoBranchWriter() {}

	void createBranch( TTree * tree, const char* name ){
		this->_event = std::shared_ptr<BranchType>(new BranchType());
		tree->Branch( name, this->_event.get(), 256000, 99 );
	}

	void set( BranchType &event ){
		this->_event->copy( &event );
	}

protected:
	std::shared_ptr<BranchType> _event = nullptr;
};
#endif