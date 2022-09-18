#pragma once

#include <type_traits>
#include <SFML/Graphics.hpp>
#include <random>
#include <memory>

#include "../../Algorithms/Lists/ListSortBase.h"
#include "../../Algorithms/Lists/BubbleSort.h"
#include "VisualizerBase.h"

#define _CREATE_VISUALIZER_FUNC_DEF_(VisualizerT, FuncName, AlgTBase, DataSetT) template<class AlgT, typename = std::enable_if_t<std::is_base_of<AlgTBase, AlgT>::value, bool>>\
VisualizerT FuncName(DataSetT dataSet)\
{\
	return VisualizerT(std::unique_ptr<AlgT>(new AlgT(dataSet)));\
}

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

//_CREATE_VISUALIZER_FUNC_DEF_1_(ListSortVisualizer, createListVisualizer, ListSortBase, std::vector<float>)

//Creates a list sort visualizer from a random dataset
template<class SortAlgT, typename = std::enable_if_t<std::is_base_of<ListSortBase, SortAlgT>::value, bool>>
ListSortVisualizer createListVisualizer(int dataPoints)
{
	std::vector<float> dataSet(dataPoints);
	for (int i = 0; i < dataSet.size(); i++)
		dataSet[i] = (float)rand() / (float)RAND_MAX;

	return ListSortVisualizer(std::unique_ptr<SortAlgT>(new SortAlgT(dataSet)));
}