#ifndef __COUNT__
#define __COUNT__

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѭp�ɥ\��													   //
	/////////////////////////////////////////////////////////////////////////////
	class Counter
	{
	public:
		Counter();
		~Counter();
		void Start();
		void Finish();
		clock_t GetTime();
	private:
		clock_t startTime;
		clock_t finishTime;
	};
}

#endif

