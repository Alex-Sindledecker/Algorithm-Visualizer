#include "SelectionSort.h"

SelectionSort::SelectionSort(std::vector<float> dataSet) 
    : ListSortBase(dataSet)
{
    m_activeIndices[0] = ActiveElementState::PRIMARY;
    enqueueState();
}

Complexity SelectionSort::getTimeComplexity()
{
	return Complexity::O_N2;
}

Complexity SelectionSort::getSpaceComplexity()
{
	return Complexity::O_1;
}

void SelectionSort::sort()
{
    for (int i = 0; i < m_data.size() - 1; i++)
    {
        for (int n = i + 1; n < m_data.size(); n++)
        {
            m_activeIndices[i] = ActiveElementState::PRIMARY;
            m_activeIndices[n] = ActiveElementState::SECONDARY;

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

void SelectionSort::enqueueState()
{
    m_states.push(SortState{ m_data, m_activeIndices });
    m_activeIndices.clear();
}
