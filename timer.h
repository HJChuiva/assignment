//--------------------------------------------------------------------
//
//  Laboratory 8
//
//  timer.h
//
//--------------------------------------------------------------------

// SystemTime�� type ����
typedef long SystemTime;

class Timer
{
public:

	// ��ȯ��
	void setStartTime ();
	void setStopTime ();

	// ���� �ð� ���
	double runTime ();

private:

	SystemTime	startTime,   // ���۽ð�
				stopTime;    // ����ð�
};
