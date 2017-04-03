#ifndef FEMTO_TCLONES_ARRAY_WRITER_H
#define FEMTO_TCLONES_ARRAY_WRITER_H

#include "TTree.h"
#include "TClonesArray.h"

template<class BranchType>
class FemtoTClonesArrayWriter
{
public:
	FemtoTClonesArrayWriter() {}
	~FemtoTClonesArrayWriter() {}

	void createBranch( TTree *tree, const char* name){
		_carray = new TClonesArray( BranchType().name() );
		tree->Branch( name, &this->_carray, 256000, 99 );
	}

	void add( BranchType &track ){
		BranchType *new_track = new ((*this->_carray)[this->_n]) BranchType( );
		new_track->copy( &track );
		this->_n++;
	}

	void reset(){
		this->_n = 0;
		this->_carray->Clear();
	}

	UInt_t N() const { return _n; }
	BranchType *at( UInt_t i ){
		if ( nullptr == _carray )
			return nullptr;
		return (BranchType*)_carray->At( i );
	}



protected:
	TClonesArray        * _carray        = nullptr;
	UInt_t                _n = 0;
};

#endif