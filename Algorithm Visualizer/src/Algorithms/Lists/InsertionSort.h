#pragma once

#include "ListSortBase.h"

class InsertionSort : public ListSortBase
{
public:
    InsertionSort(std::vector<float> dataSet);

    Complexity getTimeComplexity() override;
    Complexity getSpaceComplexity() override;
    void sort() override;
};