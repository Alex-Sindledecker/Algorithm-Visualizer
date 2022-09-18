#pragma once

#include "ListSortBase.h"

class InsertionSort : public ListSortBase
{
public:
    InsertionSort(std::vector<float> dataSet);

    void enqueueState() override;
    Complexity getTimeComplexity() override;
    Complexity getSpaceComplexity() override;
    void sort() override;

private:
    std::unordered_map<int, ActiveElementState> m_activeIndices;
};