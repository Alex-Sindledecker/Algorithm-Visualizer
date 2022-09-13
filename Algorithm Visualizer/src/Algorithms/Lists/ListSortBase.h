#pragma once

#include "../IAlgBase.h"

#include <vector>
#include <queue>

enum class ActiveElementState { NONE, PRIMARY, SECONDARY, ALTERNATE };

template<class T>
class ListSortBase : public IAlgBase
{
public:
    struct ActiveIndex
    {
        int index;
        ActiveElementState color;
    };

    struct SortState
    {
        std::vector<T> data;
        std::vector<ActiveIndex> activeIndices;
    };

public:
    ListSortBase(const std::vector<T>& dataSet)
    {
        m_data = dataSet;
    }

    virtual void enqueueState() = 0;

    virtual bool dequeueState() override
    {
        m_states.pop();

        return !m_states.empty();
    }

    virtual SortState peek()
    {
        return m_states.front();
    }

    virtual bool isStateRemaining()
    {
        return !m_states.empty();
    }

    virtual void sort() = 0;

protected:
    std::queue<SortState> m_states;
    std::vector<T> m_data;
};