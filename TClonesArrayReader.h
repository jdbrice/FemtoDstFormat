#ifndef FEMTO_TCLONES_ARRAY_READER_H
#define FEMTO_TCLONES_ARRAY_READER_H

#include "TTRee.h"
#include "TClonesArray.h"

template <class BranchType>
class FemtoTClonesArrayReader
{
public:
	FemtoTClonesArrayReader() {}
	~FemtoTClonesArrayReader() {}
	
	void setup( TTree *tree, const char* branchName )
	{
		if ( nullptr == tree ) return;
		_branch = tree->GetBranch( branchName );
		if ( nullptr == _branch ) return;
		this->_carray = new TClonesArray( BranchType().name() );
		tree->SetBranchAddress( branchName, &(this->_carray) );
		this->_branch->SetAutoDelete( kFALSE );
	}

	BranchType *get( UInt_t index )
	{
		if ( nullptr == this->_carray ) return nullptr;
		return (BranchType*)this->_carray->At( index );
	}

	UInt_t N() 
	{
		if ( nullptr == this->_carray ) return 0;
		return this->_carray->GetEntries();
	}

protected:
	TBranch *_branch      = nullptr;
	TClonesArray *_carray = nullptr;
};


#endif