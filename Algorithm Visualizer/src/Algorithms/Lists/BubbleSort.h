#pragma once

#include "ListSortBase.h"

class BubbleSort : public ListSortBase<float>
{
public:
    BubbleSort(std::vector<float> dataSet);
    virtual void enqueueState() override;
    void sort() override;

private:
    std::vector<ActiveIndex> m_activeIndices;
};