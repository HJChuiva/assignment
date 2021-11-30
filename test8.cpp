//
//  Test program for Lab8 
//
#include <time.h>	  // clock(), CLOCKS_PER_SEC	
#include <limits.h>   // INT_MAX
#include <math.h>	  // pow()	
#include <windows.h>

#include <iomanip>  // setw()
#include <iostream>
using namespace std;

const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // �ڵ鰪

COORD  Pos;                                              // ��ġ

//-----------------------------------------------------
//  ȭ����� ������ ��ġ�� Ŀ�� �̵�

void gotoXY(int x, int y)
{
   Pos.X = x - 1;
   Pos.Y = y - 1;
   SetConsoleCursorPosition(hConsole, Pos);
}

// ���� ���� �� ����, 0�� �ؽ�Ʈ ����, 1�̻��� ��� ���� ���� ����
// GetColor(0) => �ؽ�Ʈ ���� ��ȯ, GetColor(1) => ��� ���� ��ȯ
//
int GetColor(int area)
{
	CONSOLE_SCREEN_BUFFER_INFO info;

	int color;
	GetConsoleScreenBufferInfo(hConsole, &info);

	if(area) 
		color = (info.wAttributes & 0xf0) >> 4;
	else 
		color = info.wAttributes & 0xf;
	return color;
}

//�ؽ�Ʈ, ��� �� ����
void SetColor(int txtcolor, int bgcolor)
{
	txtcolor &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(hConsole, (bgcolor << 4) | txtcolor);
}

// �ؽ�Ʈ �� ����
// ��� ���� GetColor(1)�� ���� ������ �������� ����
void SetColor(int txtcolor)
{
	txtcolor &= 0xf;
	int bgcolor = GetColor(1);
	SetConsoleTextAttribute(hConsole, (bgcolor << 4) | txtcolor);
}

#include "timer.h"
#include "timer.cpp"

typedef int Array[100000+2];	// 1..n �� ���ؼ� +1
								// quickSort�� INT_MAX�����ؼ� +1
clock_t start, finish;
Array TestArray, tempArray;
int i, Max;

#include "sorts.cpp"

//---------------------------------------------------------------//
// ������ �߻��Ͽ� �迭�� �ʱ�ȭ �Ѵ�.                           //
//---------------------------------------------------------------//
// rand() �Լ��� 0 ~ RAND_MAX ������ ������ �߻��Ѵ�.
// RAND_MAX: 0x7fff, �� 32767

void initArray (Array L) 
{
	int i;
	srand( (unsigned)time( NULL ) );
	for (i = 1; i <= Max; i++)
		L[i] = rand();			// random
//		L[i] =  i;				// 1, 2, 3, ... , Max-2, Max-1, Max
//		L[i] =  Max + 1 - i;	// Max, Max-1, Max-2, . . , 3, 2, 1
}

//---------------------------------------------------------------//
// �迭�� ���� �Ѵ�.                                             //
//---------------------------------------------------------------//
void copyArray()
{
	for (i=1; i<=Max; i++) 
		tempArray[i] = TestArray[i];
}

//---------------------------------------------------------------//
// ���� ��� Ȯ��                                                //
//---------------------------------------------------------------//
bool isSorted(Array L) 
{
	for (i=1; i<Max-1; i++) 
	{
		if ( L[i] > L[i+1] ) 
		{
			cout << "Order error: " << L[i] << " > " << L[i+1] << " at " << i << endl;
			return false;
		}
	}
	return true;
}

//-------------------  main() -----------------------------------//

int main()
{
    Timer sortTimer;      // Timer for sorting routine
	char c;

	while(1)
	{
		system("cls");
		cout << endl << "Enter number of elements: " ;
		cin >> Max;

		initArray(TestArray);
		cout << endl << "# of elements: " << Max << endl;
		
		//--------------- Bubble  Sort O(N*N) ---------------------------//
		copyArray();
		sortTimer.setStartTime();
		bubbleSort(tempArray);
		sortTimer.setStopTime();
		cout << endl << "bubbleSort:    " << sortTimer.runTime() << "��" << endl;
		if (isSorted(tempArray))
			cout << "OK" << endl;


		//--------------- Selection Sort O(N*N) -------------------------//
		
		copyArray();
		sortTimer.setStartTime();
		selectionSort(tempArray);
		sortTimer.setStopTime();
		cout << "selectionSort:   " << sortTimer.runTime() << "��" << endl;
		if (isSorted(tempArray))
			cout << "OK" << endl;
		
		//-----------------  Insertion  Sort O(N*N) ---------------------//
		
		copyArray();
		sortTimer.setStartTime();
		insertionSort(tempArray);
		sortTimer.setStopTime();
		cout << "insertionSort: " << sortTimer.runTime() << "��" << endl;
		if (isSorted(tempArray))
			cout << "OK" << endl;
		
		//-------------------  Shell Sort O(N*N) ------------------------//
		
		copyArray();
		sortTimer.setStartTime();
		shellSort(tempArray);
		sortTimer.setStopTime();
		cout << "shellSort:     " << sortTimer.runTime() << "��" << endl;
		if (isSorted(tempArray))
			cout << "OK" << endl;
		
		//------------------  quickSort O(NlogN) ------------------------//
		
		copyArray();
		tempArray[Max+1] = INT_MAX;
		sortTimer.setStartTime();
		quickSort(tempArray,1,Max);
		sortTimer.setStopTime();
		cout << "quickSort:     " << sortTimer.runTime() << "��" << endl;
		if (isSorted(tempArray))
			cout << "OK" << endl;
		
		//-------------------  MergeSort O(NlogN) -----------------------//
		
		copyArray();
		sortTimer.setStartTime();
		mergeSort(tempArray,Max+1);
		sortTimer.setStopTime();
		cout << "mergeSort:     " << sortTimer.runTime() << "��" << endl;
		if (isSorted(tempArray))
			cout << "OK" << endl;
		
		//-----------------   Heap Sort O(NlogN) ------------------------//
		
		copyArray();
		sortTimer.setStartTime();
		heapSort(tempArray,Max);
		sortTimer.setStopTime();
		cout << "heapSort:      " << sortTimer.runTime() << "��" << endl;
		if (isSorted(tempArray))
			cout << "OK" << endl;
		
		//-------------   RadixSort O(NlogN) -------------------------//
		
		copyArray();
		sortTimer.setStartTime();
		radixSort(tempArray, 5);
		sortTimer.setStopTime();
		cout << "radixSort:     " << sortTimer.runTime() << "��" << endl;
		if (isSorted(tempArray))
			cout << "OK" << endl;

		cout << endl << "continue(Y/N) ? ";
		cin >> c;
		if (toupper(c) == 'N')
			break;
	} // while

	return 0;
}