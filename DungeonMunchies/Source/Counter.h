
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
		void Reset();
		clock_t GetTime();					//�]�w���媺��q
	private:
		clock_t startTime;			//���P���ת����
		clock_t finishTime;			//���P���ת����
	};
}

