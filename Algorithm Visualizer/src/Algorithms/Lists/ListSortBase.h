#pragma once

#include "../IAlgBase.h"

#include <vector>
#include <queue>

enum class ActiveElementState { NONE, PRIMARY, SECONDARY, ALTERNATE };

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
        std::vector<float> data;
        std::vector<ActiveIndex> activeIndices;
    };

public:
    ListSortBase(const std::vector<float>& dataSet)
    {
        m_data = dataSet;
    }

    virtual bool dequeueState() override
    {
        m_states.pop();

        return !m_states.empty();
    }

    virtual SortState peek() const
    {
        return m_states.front();
    }

    virtual bool isStateRemaining() const
    {
        return !m_states.empty();
    }

    const int queueLength() const
    {
        return m_states.size();
    }

    const int dataSetSize() const
    {
        return m_data.size();
    }

    //Shuffles the list by swapping every index with another random index
    virtual void unsort()
    {
        for (int i = 0; i < m_data.size(); i++)
        {
            int ri = rand() % m_data.size();

            int temp = m_data[i];
            m_data[i] = m_data[ri];
            m_data[ri] = temp;
        }
    }

    int stateCount = 0;

    virtual void sort() = 0;

protected:
    std::queue<SortState> m_states;
    std::vector<float> m_data;
};