#pragma once

#include "ListSortBase.h"

class SelectionSort : public ListSortBase
{
public:
	SelectionSort(std::vector<float> dataSet);
	virtual Complexity getTimeComplexity() override;
	virtual Complexity getSpaceComplexity() override;
	virtual void sort() override;

private:
	std::unordered_map<int, ActiveElementState> m_activeIndices;
};