#include "BubbleSort.h"

BubbleSort::BubbleSort(std::vector<float> dataSet) : ListSortBase(dataSet)
{
    m_activeIndices = { ActiveIndex{ 0, ActiveElementState::PRIMARY } };
    enqueueState();
}

void BubbleSort::enqueueState()
{
    m_states.push(SortState{ m_data, m_activeIndices });
    m_activeIndices.clear();
}

void BubbleSort::sort()
{
    for (int i = 0; i < m_data.size() - 1; i++)
    {
        for (int n = i + 1; n < m_data.size(); n++)
        {
            m_activeIndices.push_back(ActiveIndex{ i, ActiveElementState::PRIMARY });
            m_activeIndices.push_back(ActiveIndex{ n, ActiveElementState::SECONDARY });

            if (m_data[n] < m_data[i])
            {
                //Swap
                float temp = m_data[i];
                m_data[i] = m_data[n];
                m_data[n] = temp;
            }

            enqueueState();
        }
    }
}
