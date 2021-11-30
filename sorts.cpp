// ���α׷� ���� : ���� ���� �������� ����� �����ϰ� ������ ������� ���� �����͸� �����ϴµ� �ɸ��� ����ð��� ����, ���Ѵ�.
// bubbleSort, minIndex. selectionSort. insertionSort. shellSort, quickSort �ӵ� ��
// �й�: 2020111301 
// �̸�: ������ 
// �й�: 1�й� 12��-15��
// ��¥: 2021/12/01

#define SWAP(x, y, t) (t=x, x=y, y=t)
#define radix 10

//---------------------------------------------------------------//
// ���������� �̿��� �������� ����                               //
//---------------------------------------------------------------//

//���� ������ �� ���Ҹ� �˻��Ͽ� ����
void bubbleSort(Array L) 
{
	int temp;

	for (int i = 1; i <= Max; i++)				//i looping ���鼭  ���� ���Ҹ� ã��
		for (int j = i + 1; j <= Max; j++)		//j looping i+1���� ��
			if (L[i] > L[j])					//i��°���� j��°�� ���� ��
				SWAP(L[i], L[j], temp);			//SWAP

}

//���Ҹ� ó������ Ž���ϸ鼭 ���� ���� ã��
int minIndex(Array L, int from, int to)
{
	int min = from;							//���� ���� ���� ��ġ�� �޾Ƽ� ��ȯ, from���� ���
	for (int i = from + 1; i <= to; i++)	//���� ���� ��ġ�� ã��
		if (L[i] < L[min])					//i��°�� min��°���� ������
			min = i;						//i��°�� �� ���� ��ġ
	return min;								//���� ���� min��° ��ȯ

}

//���� ���� ã�� �� ���� �迭�� ���ʿ� ������ �ٽ� ���� ���� ã�� ����
void selectionSort(Array L)
{
	int temp, min;

	for (int i = 1; i <= Max; i++)
	{
		min = minIndex(L, i, Max);		//L �迭���� i���� Max���� ���� ���� ���� ����ִ��� �޾Ƽ� min�� ����
		SWAP(L[i], L[min], temp);		//i��°�� ���� ���Ҵ� min��°�� ����
	}
}

// 2��° ���Һ��� �����Ͽ� �� ��(����)�� ���ҵ�� ���Ͽ� ������ ��ġ�� ������ ��
//���Ҹ� �ڷ� �ű�� ������ �ڸ��� �ڷḦ ���� �Ͽ� ����
void insertionSort (Array L) 
{
	int j, next;

	for (int i = 1; i <= Max; i++)
	{
		next = L[i];					//i��° ���� ����
		j = i - 1;						
		while (L[j] > next && j>0)		//j��° ���ҿ� next ���Ͽ� '1'������ ������ ������ ũ�ٸ�, 1�� �Ʒ��� �������� �ʵ��� j>0 ���� �߰�
		{
			L[j + 1] = L[j];			//���� ���� ��ȯ
			j--;						//j �ϳ� ������
		}	
		L[j + 1] = next;				//j���� ���� temp ������ ���� ���� �� ���� ū ���� ��ġ i �� ����Ű�� ��
	}

}
//������ ũ�� �������ķ� �ϰ� ������ 1�� �ɶ����� �ݺ��ϴ� ����
void shellSort( Array L ) 
{
	int j, h=1, next;

	//�ִ밣��(h) ����
	while (3 * h + 1 < Max)
		h = 3 * h + 1;
	//������ 1�� �ɶ�����
	while (h > 0)
	{
		//���� h �� �������� 
		for (int i = 1; i <= Max; i++)
		{
			next = L[i];
			j = i - h;
			while (L[j] > next && j > 0)
			{
				L[j + h] = L[j];
				j = j - h;
			}
			L[j + h] = next;
		}

		//h ����
		h = h / 3;
	}//while

}
//������ pivot���� �ΰ�, pivot �� �������� pivot ���� �������� �ΰ� �������� pivot ���� ū ���� �ξ� ��������� �ݺ��ϴ� ����
void quickSort(Array L, int left, int right) 
{
	int i, j, pivot, temp;

	if (left < right)							//��������
	{
		i = left;
		j = right + 1;
		pivot = L[left];
		do
		{
			do i++; while (L[i] < pivot);		//i�� pivot���� ���� ���� �ö󰡴ٰ� pivot���� ū ���Ҹ� ������ ����
			do j--; while (L[j] > pivot);		//j�� pivot���� ū ���� �������ٰ� pivot���� ���� ���Ҹ� ������ ����
			if (i < j)							//���� i,j�� �� �������� SWAP
				SWAP(L[i], L[j], temp);
		} while (i < j);						//�ѹ��� �������� �ݺ�

		SWAP(L[left], L[j], temp);				//pivot�� �ڱ� ��ġ�� ã��
		quickSort(L, left, j - 1);				//j��°�� pivot�� �� �����Ƿ� left���� j-1������ ���ȣ��
		quickSort(L, j + 1, right);				//j+1���� right���� ���ȣ��
	}
}


//---------------------------------------------------------------//
// merge : L1[l..m]+L1[(m+1)..n] => L2[l..m]                     //
//---------------------------------------------------------------//
void merge(Array L1, Array L2, int l, int m, int n)
{
	int i, j, k, t;

	i = l;
	k = l;
	j = m + 1;

	while ((i <= m) && (j <= n))
	{
		if (L1[i] <= L1[j])
			L2[k++] = L1[i++];
		else
			L2[k++] = L1[j++];
	}

	if (i > m)
		for (t = j; t <= n; t++)
			L2[k++] = L1[t];
	else
		for (t = i; t <= m; t++)
			L2[k++] = L1[t];
}

//--------------------------------------------------------------
void Mpass(Array L1, Array L2, int n, int length)
{
	// n: ��ü ������ ����, length: �պ��� subfile�� ����
	int i, t;

	i = 1;
	while (i <= (n - 2 * length + 1))
	{
		merge(L1, L2, i, i + length - 1, i + 2 * length - 1);
		i += 2 * length;
	}

	if (i + length < n)
		merge(L1, L2, i, i + length - 1, n);
	else
		for (t = i; t < n; t++)
			L2[t] = L1[t];
}

//---------------------------------------------------------------//
// �պ������� �̿��� �������� ����                               //
//---------------------------------------------------------------//
void mergeSort(Array L1, int n)
{
	int i, length = 1;   // �պ��� ���������� ����
	Array L2;

	while (length < n) {
		Mpass(L1, L2, n, length);
		length *= 2;
		for (i = 1; i < Max + 1; i++)
			L1[i] = L2[i];
		//Mpass(L2, L1, n, length);
		//length *= 2;
	}
}

//---------------------------------------------------------------//
// ������ ��ȯ                                                   //
//---------------------------------------------------------------//
void adjust(Array L, int root, int n)
{
	int child, rootkey, temp;
	temp = L[root];
	rootkey = L[root];
	child = 2 * root;		   //�����ڽ�
	while (child <= n)
	{
		if ((child<n) && (L[child]<L[child + 1]))
			child++;
		if (rootkey > L[child])
			break;
		else
		{
			L[child / 2] = L[child];
			child *= 2;
		}
	}
	L[child / 2] = temp;
}

//---------------------------------------------------------------//
// �������� �̿��� �������� ����                                 //
//---------------------------------------------------------------//
void heapSort(Array L, int n)
{
	int i, temp;

	// heap���� �����
	for (i = n / 2; i>0; i--)
		adjust(L, i, n);

	// ����ū��(1��° ����)�� ������(n��°)���� �ű�� �������� �ٽ� heap���� �����.
	for (i = n - 1; i>0; i--)
	{
		SWAP(L[1], L[i + 1], temp);
		adjust(L, 1, i);
	}
}

//---------------------------------------------------------------//
// ��������� �̿��� �������� ����                               //
//---------------------------------------------------------------//

// p : �ִ��ڸ��� (RAND_MAX�� ��� �ִ밪�� 32767�̹Ƿ� 5�ڸ�, ���� 5)
void radixSort(Array L, int p)
{
	Array temp;        // �߰� ����� ����
	int counts[radix]; // �� �ڸ��� �� ī��Ʈ
	int index, power, i, j, n;
	int k;

	for (n = 0; n < p; n++)
	{
		for (i = 0; i<radix; i++)
			counts[i] = 0; // �ʱ�ȭ

		power = (int)pow((double)radix, (double)n);  // power = 10^n

													 // ���� �ڸ���(=n) �������� �� ������ �߻�Ƚ���� ����.
		for (j = 1; j <= Max; j++)
		{
			index = (int)(L[j] / power) % radix;
			counts[index]++;
		}

		// ���� ī��Ʈ
		for (i = 1; i<radix; i++)
			counts[i] = counts[i] + counts[i - 1];

		// ���� ī��Ʈ�� ����� �� �׸��� ��ġ�� ����
		for (j = Max; j >= 1; j--) // �ڿ��� ���� ����
		{
			index = (int)(L[j] / power) % radix;
			temp[counts[index]] = L[j];
			counts[index]--;
		}

		for (k = 1; k <= Max; k++)	// �߰� ������� �ٽ� �����ϱ� ���� ����
			L[k] = temp[k];
	}
}
