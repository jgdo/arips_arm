//
// This file is part of the GNU ARM Eclipse distribution.
// Copyright (c) 2014 Liviu Ionescu.
//

#include "Timer.h"

#include <stm32f1xx_hal.h>

uint32_t SysTickTimer::sLastProcessedTick = 0xFFFFFFFFu;
SysTickTimer* SysTickTimer::sTimerQueue = nullptr;

SysTickTimer::SysTickTimer(uint32_t period) :
		mPeriod(period > 0 ? period : 1) {
	insertSelfIntoQueue();
}

void SysTickTimer::handleTimers() {
	uint32_t currentTick = HAL_GetTick();
	
	while (sLastProcessedTick != currentTick) {
		sLastProcessedTick++;
		
		for (SysTickTimer* timer = sTimerQueue; timer != nullptr; timer = timer->mNextTimer) {
			if (timer->isRunning() && timer->mNextTick == sLastProcessedTick) {
				timer->fire();
				timer->mNextTick += timer->mPeriod;
			}
		}
	}
}

void SysTickTimer::insertSelfIntoQueue() {
	mNextTimer = sTimerQueue;
	sTimerQueue = this;
	if (mNextTimer) {
		mNextTimer->mPrevTimer = this;
	}
}

SysTickTimer::~SysTickTimer() {
	if (mNextTimer) {
		mNextTimer->mPrevTimer = this->mPrevTimer;
	}
	
	if (mPrevTimer) {
		mPrevTimer->mNextTimer = this->mNextTimer;
	} else if (sTimerQueue == this) { // should be always true if previous was false
		sTimerQueue = mNextTimer;
	}
}

void SysTickTimer::start() {
	if (!mActive) {
		mNextTick = HAL_GetTick() + mPeriod;
		mActive = true;
	} // else do nothing since already running
}
