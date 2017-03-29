#ifndef FEMTO_BRANCH_READER_H
#define FEMTO_BRANCH_READER_H

#include <memory>
#include "TTree.h"
#include "TBranch.h"

template<class BranchType>
class FemtoBranchReader
{
public:
	FemtoBranchReader() {}
	~FemtoBranchReader() {}

	void setup( TTree* tree, const char* branchName )
	{
		if ( nullptr == tree ) return;
		_branch = tree->GetBranch( branchName );
		if ( nullptr == _branch ) return;
		tree->SetBranchAddress( branchName, &(this->_object) );
	}

	BranchType* get() { return _object; }

protected:
	TBranch *_branch = nullptr;
	BranchType* _object = nullptr;
};

#endif