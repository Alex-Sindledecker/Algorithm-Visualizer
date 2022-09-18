#include "Animation.h"

#include <mutex>

Animation::Animation(OnAnimationUpdateCallback onUpdate, void* onUpdateParams, double duration, unsigned int steps)
{
	m_updateCallback = onUpdate;
	m_callbackParams = onUpdateParams;

	setAnimationDuration(duration);
	setAnimationSteps(steps);
}

Animation::~Animation()
{
	//Ensures the thread is joined
	endAnimation();
}

void Animation::setAnimationDuration(double duration)
{
	m_duration = duration;
}

void Animation::setAnimationSteps(unsigned int steps)
{
	m_totalSteps = steps;
}

void Animation::beginAnimation()
{
	m_callbackTimerThread = std::thread([&](double timeStep) {
		if (timeStep <= 0)
			return;

		auto time = std::chrono::high_resolution_clock::now();
		int steps = 0;

		while (steps < m_totalSteps && m_animationFinished == false)
		{
			while (m_animationPaused);
			
			m_updateCallback(m_callbackParams);

			auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - time).count();
			while (diff < timeStep * 1000)
			{
				//Checking for a finished animation here also in case there is a large time step
				if (m_animationFinished)
					return;
				diff = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - time).count();
			}
			time = std::chrono::high_resolution_clock::now();

			steps++;
		}

		m_animationFinished = true;


	}, m_duration / (double)m_totalSteps);
}

void Animation::pauseAnimation()
{
	m_animationPaused = true;
}

void Animation::endAnimation()
{
	m_animationFinished = true;
	m_callbackTimerThread.join();
}
