#pragma once

#include "../Animation.h"
#include "../../Algorithms/IAlgBase.h"
#include <SFML/Graphics.hpp>
#include <mutex>

struct AlgStats
{
	Complexity timeComplexity;
	Complexity spaceComplexity;
	int dataPoints;
	int steps;
};

class VisualizerBase
{
public:
	VisualizerBase();
	virtual ~VisualizerBase() = 0 {}

	virtual void play();
	virtual void pause();
	virtual void end();

	//Called every frame
	void render();
	AlgStats getStats();

	void setRenderTarget(sf::RenderWindow* window);

protected:
	//Impliment this method in a children classes
	virtual void safeRender() = 0;
	virtual void safeUpdate() = 0;
	virtual AlgStats safeGetStats() = 0;

private:
	static void animationUpdateCallback(void* arg);

protected:
	sf::RenderWindow* m_window;
	Animation m_animation;

private:
	std::mutex m_mutex;
};