#pragma once

#include <chrono>
#include <functional>
#include <thread>
#include <atomic>
#include <queue>

using OnAnimationUpdateCallback = std::function<void(void*)>;

class Animation
{
public:
	Animation(OnAnimationUpdateCallback onUpdate, void* onUpdateParams, double duration = 0, unsigned int steps = 0);
	~Animation();

	void setAnimationDuration(double duration);
	void setAnimationSteps(unsigned int steps);
	void beginAnimation();
	void pauseAnimation();
	void endAnimation();

private:
	OnAnimationUpdateCallback m_updateCallback;
	void* m_callbackParams;
	double m_duration;
	unsigned int m_totalSteps;

	std::thread m_callbackTimerThread;
	std::atomic<bool> m_animationFinished;
	std::atomic<bool> m_animationPaused;
};

/*
 * TODO: For now i'm using a thread per instance of 'Animation'. However this would need to change if we started to have many animations at once.
 *       My current idea is maybe using a thread pool of n threads where each thread stores a min heap (priority queue) for upcoming callbacks
*/