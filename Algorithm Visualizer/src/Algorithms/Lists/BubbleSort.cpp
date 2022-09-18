#include "BubbleSort.h"

BubbleSort::BubbleSort(std::vector<float> dataSet) : ListSortBase(dataSet)
{
    m_activeIndices[0] = ActiveElementState::PRIMARY;
    enqueueState();
}

Complexity BubbleSort::getTimeComplexity()
{
    return Complexity::O_N2;
}

Complexity BubbleSort::getSpaceComplexity()
{
    return Complexity::O_1;
}

void BubbleSort::sort()
{
    for (int i = 0; i < m_data.size(); i++)
    {
        for (int n = 0; n < m_data.size() - 1; n++)
        {
            m_activeIndices[n] = ActiveElementState::PRIMARY;
            m_activeIndices[n + 1] = ActiveElementState::SECONDARY;

            if (m_data[n] > m_data[n + 1])
            {
                //Swap
                float temp = m_data[n];
                m_data[n] = m_data[n + 1];
                m_data[n + 1] = temp;
            }

            enqueueState();
        }
    }
}
