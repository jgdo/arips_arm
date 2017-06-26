#ifndef TIMER_H_
#define TIMER_H_

#include <cstdint>
#include <memory>

class SysTickTimer;

typedef std::unique_ptr<SysTickTimer> SysTickTimerHandle;

class SysTickTimer {
public:
	SysTickTimer(uint32_t period);
	virtual ~SysTickTimer();

	template<class T>
	static SysTickTimerHandle createTimer(uint32_t period, T callback, bool autostart=true);

	void start();

	inline bool isRunning() const {
		return mActive;
	}
	
	/**
	 * call from main loop periodically
	 */
	static void handleTimers();

protected:
	virtual void fire() = 0;

private:
	static uint32_t sLastProcessedTick;
	static SysTickTimer* sTimerQueue;

	SysTickTimer* mNextTimer = nullptr;
	SysTickTimer* mPrevTimer = nullptr;

	uint32_t mPeriod;
	uint32_t mNextTick = 0;
	bool mActive = false;

	void insertSelfIntoQueue();
};

template<class T>
SysTickTimerHandle SysTickTimer::createTimer(uint32_t period, T callback, bool autostart) {
	
	class SysTickTimerImpl: public SysTickTimer {
	public:
		inline SysTickTimerImpl(uint32_t period, T runable, bool autostart) :
				SysTickTimer(period), mRunable(runable) {
			if(autostart)
				start();
		}
		
	protected:
		virtual void fire() override {
			mRunable();
		}
		
	private:
		T mRunable;
	};
	
	return SysTickTimerHandle(new SysTickTimerImpl(period, callback, autostart));
}

// ----------------------------------------------------------------------------

#endif // TIMER_H_
