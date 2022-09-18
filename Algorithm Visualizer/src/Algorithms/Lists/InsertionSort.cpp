#include "InsertionSort.h"

InsertionSort::InsertionSort(std::vector<float> dataSet) : ListSortBase(dataSet)
{
    m_activeIndices[0] = ActiveElementState::PRIMARY;
    enqueueState();
}

Complexity InsertionSort::getTimeComplexity()
{
    return Complexity::O_N2;
}

Complexity InsertionSort::getSpaceComplexity()
{
    return Complexity::O_1;
}

void InsertionSort::sort()
{
    for (int i = 0; i < m_data.size(); i++)
    {
        int si = i;
        while (si > 0 && m_data[si] < m_data[si - 1])
        {
            m_activeIndices[si] = ActiveElementState::PRIMARY;
            m_activeIndices[si - 1] = ActiveElementState::SECONDARY;

            //swap
            float temp = m_data[si];
            m_data[si] = m_data[si - 1];
            m_data[si - 1] = temp;

            enqueueState();

            si--;
        }
    }
}
