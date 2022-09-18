#include "ListSortBase.h"

ListSortBase::ListSortBase(const std::vector<float>& dataSet)
{
    m_data = dataSet;
}

void ListSortBase::enqueueState()
{
    m_states.push(SortState{ m_data, m_activeIndices });
    m_activeIndices.clear();
}

bool ListSortBase::dequeueState()
{
    m_states.pop();

    return !m_states.empty();
}

ListSortBase::SortState ListSortBase::peek() const
{
    return m_states.front();
}

int ListSortBase::statesRemaining() const
{
    return m_states.size();
}

const int ListSortBase::queueLength() const
{
    return m_states.size();
}

const int ListSortBase::dataSetSize() const
{
    return m_data.size();
}

//Shuffles the list by swapping every index with another random index
void ListSortBase::unsort()
{
    for (int i = 0; i < m_data.size(); i++)
    {
        int ri = rand() % m_data.size();

        int temp = m_data[i];
        m_data[i] = m_data[ri];
        m_data[ri] = temp;
    }
}
