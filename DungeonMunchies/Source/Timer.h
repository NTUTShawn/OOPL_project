#ifndef __TIMER__
#define __TIMER__

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѭp�ɥ\��													   //
	/////////////////////////////////////////////////////////////////////////////
	class Timer
	{
	public:
		Timer();
		~Timer();
		void SetStartTime(clock_t time);
		void SetFinishTime(clock_t time);
		clock_t GetStartTime();
		clock_t GetFinishTime();
		void Start();
		void Finish();
		clock_t GetTime();
		void CaculateTimeForFalse(bool* b, double time);
		void CaculateTimeForTrue(bool* b, double time);
	private:
		clock_t startTime;
		clock_t finishTime;
	};
}
#endif

