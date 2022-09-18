#pragma once

#include "ListSortBase.h"

class BubbleSort : public ListSortBase
{
public:
    BubbleSort(std::vector<float> dataSet);

    Complexity getTimeComplexity() override;
    Complexity getSpaceComplexity() override;
    void sort() override;
};