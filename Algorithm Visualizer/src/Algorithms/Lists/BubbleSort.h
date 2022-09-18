#pragma once

#include "ListSortBase.h"

class BubbleSort : public ListSortBase
{
public:
    BubbleSort(std::vector<float> dataSet);

    void enqueueState() override;
    Complexity getTimeComplexity() override;
    Complexity getSpaceComplexity() override;
    void sort() override;

private:
    std::vector<ActiveIndex> m_activeIndices;
};