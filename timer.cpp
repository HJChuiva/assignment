//--------------------------------------------------------------------
//
//  Laboratory 8
//
//  Implementation of the Timer ADT: timer.cpp
//
//--------------------------------------------------------------------


void Timer::setStartTime ()

// timer ����

{
    startTime = clock();
}

//--------------------------------------------------------------------

void Timer::setStopTime ()

// timer ����

{
    stopTime = clock();
}

//--------------------------------------------------------------------

double Timer::runTime ()

// startTime ���� stopTime������ ����ð��� �ʴ����� ����Ѵ�

{
	return  (double)(stopTime - startTime) / CLOCKS_PER_SEC;
}


