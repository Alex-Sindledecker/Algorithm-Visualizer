#pragma once

#include <type_traits>
#include <SFML/Graphics.hpp>
#include <random>
#include <memory>

#include "../../Algorithms/Lists/ListSortBase.h"
#include "../../Algorithms/Lists/BubbleSort.h"
#include "VisualizerBase.h"

class ListSortVisualizer : public VisualizerBase
{
public:
	ListSortVisualizer(std::unique_ptr<ListSortBase> algorithm);
	ListSortVisualizer(ListSortVisualizer&& old) noexcept;
	ListSortVisualizer(const ListSortVisualizer&) = delete;

protected:
	virtual void safeRender() override;
	virtual void safeUpdate() override;
	virtual AlgStats safeGetStats();

private:
	sf::RectangleShape m_rect;

	std::unique_ptr<ListSortBase> m_algorithm;
};

//Creates a list sort visualizer from an existing dataset
template<class SortAlgT, typename = std::enable_if_t<std::is_base_of<ListSortBase, SortAlgT>::value, bool>>
ListSortVisualizer createListVisualizer(std::vector<float> dataSet)
{
	return ListSortVisualizer(std::unique_ptr<SortAlgT>(new SortAlgT(dataSet)));
}

//Creates a list sort visualizer from a random dataset
template<class SortAlgT, typename = std::enable_if_t<std::is_base_of<ListSortBase, SortAlgT>::value, bool>>
ListSortVisualizer createListVisualizer(int dataPoints)
{
	std::vector<float> dataSet(dataPoints);
	for (int i = 0; i < dataSet.size(); i++)
		dataSet[i] = (float)rand() / (float)RAND_MAX;

	return ListSortVisualizer(std::unique_ptr<SortAlgT>(new SortAlgT(dataSet)));
}