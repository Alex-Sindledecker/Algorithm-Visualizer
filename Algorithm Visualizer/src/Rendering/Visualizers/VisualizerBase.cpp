#include "VisualizerBase.h"

#define GAURD(mutex) std::lock_guard _g_(mutex)

VisualizerBase::VisualizerBase() : 
	m_animation(animationUpdateCallback, this)
{
	m_window = nullptr;
}

void VisualizerBase::play()
{
	m_animation.beginAnimation();
}

void VisualizerBase::pause()
{
	m_animation.pauseAnimation();
}

void VisualizerBase::end()
{
	m_animation.endAnimation();
}

void VisualizerBase::render()
{
	GAURD(m_mutex);

	safeRender();
}

AlgStats VisualizerBase::getStats()
{
	GAURD(m_mutex);

	return safeGetStats();
}

void VisualizerBase::setRenderTarget(sf::RenderWindow* window)
{
	m_window = window;
}

void VisualizerBase::animationUpdateCallback(void* arg)
{
	auto self = (VisualizerBase*)arg;

	GAURD(self->m_mutex);
	self->safeUpdate();
}
