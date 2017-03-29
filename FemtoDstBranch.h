#ifndef FEMTO_DST_BRANCH_H
#define FEMTO_DST_BRANCH_H

class FemtoDstBranch
{
public:
	// virtual const char* branchName() const = 0;
	virtual const char* name() const = 0;

	virtual ~FemtoDstBranch() {};
};

#endif