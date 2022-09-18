#pragma once

#include "../IAlgBase.h"

#include <vector>
#include <queue>
#include <unordered_map>

enum class ActiveElementState { NONE, PRIMARY, SECONDARY, ALTERNATE };

class ListSortBase : public IAlgBase
{
public:
    struct SortState
    {
        std::vector<float> data;
        std::unordered_map<int, ActiveElementState> activeIndices;
    };

public:
    ListSortBase(const std::vector<float>& dataSet);

    virtual bool dequeueState();
    virtual SortState peek() const;
    virtual int statesRemaining() const;
    const int queueLength() const;
    const int dataSetSize() const;
    //Shuffles the list by swapping every index with another random index
    virtual void unsort();
    virtual void sort() = 0;

protected:
    std::queue<SortState> m_states;
    std::vector<float> m_data;
};