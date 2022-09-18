#include "ListSortVisualizer.h"

#include <iostream>

constexpr double DEFAULT_ANIMATION_DURATION = 10;
constexpr int MAX_BLOCK_HEIGHT = 200;

ListSortVisualizer::ListSortVisualizer(std::unique_ptr<ListSortBase> algorithm)
{
	algorithm.swap(m_algorithm);

	m_algorithm->sort();
	m_animation.setAnimationSteps(m_algorithm->statesRemaining());
	m_animation.setAnimationDuration(DEFAULT_ANIMATION_DURATION);
}

ListSortVisualizer::ListSortVisualizer(ListSortVisualizer&& old) noexcept
{
	old.m_algorithm.swap(m_algorithm);

	m_algorithm->sort();
}

void ListSortVisualizer::safeRender()
{
	if (m_algorithm->statesRemaining() > 0)
	{
		auto state = m_algorithm->peek();

		for (int i = 0; i < state.data.size(); i++)
		{
			const int blockWidth = 8;
			const int blockHeight = state.data[i] * MAX_BLOCK_HEIGHT + 10;

			if (state.activeIndices.find(i) != state.activeIndices.end())
			{
				switch (state.activeIndices[i])
				{
				case ActiveElementState::PRIMARY:
					m_rect.setFillColor(sf::Color::Green);
					break;
				case ActiveElementState::SECONDARY:
					m_rect.setFillColor(sf::Color::Red);
					break;
				case ActiveElementState::ALTERNATE:
					m_rect.setFillColor(sf::Color(127, 127, 127));
					break;
				default:
					m_rect.setFillColor(sf::Color::White);
				}
			}
			else
				m_rect.setFillColor(sf::Color::White);

			m_rect.setPosition(sf::Vector2f(i * 10 + 1, m_window->getSize().y - blockHeight));
			m_rect.setSize(sf::Vector2f(blockWidth, blockHeight));

			m_window->draw(m_rect);
		}
	}
}

void ListSortVisualizer::safeUpdate()
{
	if (m_algorithm->statesRemaining() > 1)
		m_algorithm->dequeueState();
}

AlgStats ListSortVisualizer::safeGetStats()
{
	AlgStats stats;

	stats.steps = m_algorithm->queueLength();
	stats.dataPoints = m_algorithm->dataSetSize();
	stats.spaceComplexity = m_algorithm->getSpaceComplexity();
	stats.timeComplexity = m_algorithm->getTimeComplexity();

	return stats;
}
