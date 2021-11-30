//
// ���α׷� ����: �͹̳� ��带 ������ ��� ��尡 ������ �� ������ subtree�� ���� ���� ���� Ʈ���̴�. 
//�ڽ��� key���� child���� ũ��.
//�迭�� �̿��Ͽ� Ʈ���� ǥ���Ͽ���. (root�� Max)
// �й�, �̸�, ����: 2020111301 ������ ����� 12��-15��
// ��¥: 2021/11/24
//

#define SWAP(x, y, t) (t=x, x=y, y=t)
//������
heap:: heap ()
{
	size = 0;
}
//�Ҹ���
heap:: ~heap ()
{
	size = 0;
}

//heap�ȿ� newData ���� ���� ���ο� ��带 �߰��Ѵ�.
void heap:: insert(heapData newData) 
{
   int parent, child;
   heapData temp;

   size++;					//1 ) size ����
   node[size] = newData;	//2) ������ size ��ġ�� newData�� ����
   child = size;			//3) child�� size�� // ����
   parent = child / 2;		//4) size/2�� �����ϳ� �ǹ̻� child/2 ����;
   while (node[parent].key<=node[child].key && parent>0)	//parent����� ���̱��� + 0��°�� �����ʹ� �� ����	//5,6,7 �ݺ�	//parent>0 or child>1
   {	
	   SWAP(node[child], node[parent],temp);	//5) child�� parent ����
	   child = parent;							//6) child�� �ϳ� �ö�
	   parent = parent / 2;						//7) parent�� parent�� �ö�
   }
}
//file�� �о� data�� insert�Ѵ�.
void heap:: read ( ifstream &input_file ) 
{
	heapData inputData;

	while ( input_file >> inputData.key ) 
          insert(inputData);
}
//heap�� ù ��° ��� (Root node)�� �����ϰ� �� �����͸� ��ȯ
heapData heap:: removeMax() 
{
   int parent, child;
   heapData maxData, temp;

   maxData = node[1];					//1) maxData�� ��尪(�ִ밪) ����

   SWAP(node[1], node[size], temp);		//2) ù��° ���� ������ ��� ����
   size--;								//3) size ����

   parent = 1;							//4) parent ���� 1 ���� 
   //loop �ð��� ���̿� ���
   do
   {
	   child = largerChild(parent);		//5) largerChild �̿�
	   if (parent == child)				// child�� ���ٸ� �߰� ����
		   break;						
	   SWAP(node[child], node[parent], temp);	//6) child��°�� parent��° ����
		parent = child;							//7) parent�� child�� �i�ư�
   } while (parent <= child);

   return maxData;
}
//heap���� ��� ������ ����
void heap:: clear ()
{
	size = 0;
}
//heap�� empty�̸� True �ƴϸ� False���� ��ȯ(������)
bool heap:: isEmpty ()
{
	return(size == 0);		//size�� 0����
}
// heap�� full�̸� True �ƴϸ� False���� ��ȯ(������)
bool heap:: isFull ()
{
	return(size == Max);	//size�� Max����
}
//heap���� ��� ������ Key���� ���� ������������ ���
void heap:: sort() 
{
	heap temp;
	int i, oldSize = size;
	heapData data;


	while (!isEmpty())		//isEmpty�� �ƴ� ����
	{
		data = removeMax();
		showSort(oldSize); getchar();//�߰��ܰ� ����
	}

	cout << endl;
	for (i=1; i<= oldSize; i++)
		cout << node[i].key << endl;
}

int heap:: height ()
{
	return (int)ceil(log((double)(size + 1) )/ log(2.0));
}
//heap�� �ܸ������ ������ ��ȯ
//ceil�� ��ȯ���� double
int  heap:: leafCount()
{
	return (int)ceil(size / 2.0);
}
//heap�� ��ܸ������ ������ ��ȯ
//floor�� ��ȯ���� double
int  heap::nonLeafCount()
{
	return (int)floor(size / 2.0);
}

//heap�� ��� ����� ������ ��ȯ
int  heap::totalCount()
{
	return size;
}
//heap�� ��� �� �� ���� �ڽĸ��� ���� ����� ������ ��ȯ
int  heap::singleCount()
{
	if ((size % 2) == 0)	
		return 1;			//¦���� 1 ��ȯ
	else
		return 0;			
}

//heap�� level���� ���
void heap::levelOrder()
{
	int newLine,   // ���� ������ ������ ���� ��ȣ
		j;         // loop counter
	newLine = 1;	//newLine�� �ʱⰪ 1
	
	system("cls");
	cout << endl << endl;

	for (j = 1; j <= size; j++)			//loop counter ��ŭ �ݺ�
	{
		cout << node[j].key << "  ";	//�� ���
		if (newLine == j)				//���� ������ ������ ���Ұ� j�� �� ��
		{
			cout << endl; // �ٹٲ� 
			newLine = 2 * newLine + 1;		//2�� n�� or 2*n+1	//1, 3, 7, 15 ...	//j ����
		}
		
	}

}

//---------------   < largerChild(int index) >----------------------------------
// index�� �ڽ��� index ���� ū ��� ū �ڽ��� ��ġ�� ��ȯ�ϸ�
// �׷��� �ڽ��� �������� ���� ��� index ��ü�� ��ȯ�Ѵ�
//
int heap::largerChild(int index)
{
	int left = 2 * index;
	int right = 2 * index + 1;

	if (left > size)									// index has no children
		return index;
	else
		if (left == size)								// index has left child only
			if (node[index].key < node[left].key)		// index < left child
				return left;
			else										// index >= left child
				return index;
		else
			if (node[left].key < node[right].key)		// index has two children 
				if (node[index].key < node[right].key) 	// index < right child								
					return right;
				else									// index >= right child
					return index;
			else										// left child >= right child
				if (node[index].key < node[left].key)	// index < left child
					return left;
				else									// index >= left child
					return index;
}

//------------------<  SiftDown() >--------------------------
// �ڽ� ���� ū Ű���� ���� �ڽİ� ��ȯ�Ѵ�.
void heap:: siftDown (int bottom, int top) 
{
	int i;
	heapData temp;

    for (i = top; i >= bottom; i--) 
	{
       if (node[i].key < node[i*2].key)				// �ڽ��� �����ڽĺ��� ������ 
            if (node[i*2].key > node[i*2 + 1].key)	// �����ڽ��� ������ �ڽĺ��� ũ�� 
				SWAP(node[i], node[i*2], temp);		// �ڽ� <-> �����ڽ� 
            else
				SWAP(node[i], node[i*2+1], temp);	// �ڽ� <-> �������ڽ� 
	   else if (node[i].key < node[i*2+1].key)		// �ڽ��� �������ڽĺ��� ������ 
			SWAP(node[i], node[i*2+1], temp);		// �ڽ� <-> �������ڽ� 
    }
}

//------------------<  convert() >--------------------------
// complete banary tree => heap ��ȯ
void heap:: convert()
{ 
	int top = (int)(size / 2);	   // top <- �ڽ��� ������ ������ ��� 
	int bottom;

	for (bottom = 1; bottom <= top; bottom++) 
	{
		system("cls");
		// cout << "bottom = " << bottom << endl << endl;
		siftDown(bottom, top);
		showConvert(bottom);		// 1���� bottom���� ���������� ���
		getchar();
	}
}

//
/****************************************************/
/*													*/
/*       heap �� ����ϱ� ���� �������� �Լ�        */
/*													*/
/****************************************************/
//

//--------------------------------------------------------------------
// heap�� �ݽð�������� 90�� ���� Ʈ���������� ���δ�. 

void heap:: showStructure () 
{
    int j;   // loop counter

    cout << endl << endl;
    if ( isEmpty() )
       cout << "Empty heap" << endl;
    else
    {
       cout << endl << "size = " << size << endl;  // �迭 �������� ���
	   cout.setf(ios::right); 
	   for ( j = 1 ; j <= size ; j++ ) 
	   {
		   cout.width(5);
           cout << j << " : " << node[j].key << endl;
	   }
	   cout.unsetf(ios::right); 
       cout << endl;
       showSubtree(1,0);                        // Ʈ�� �������� ���
    }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Recursive partner of the showStructure()

void heap:: showSubtree ( int index, int level ) 
{
     int j;   // Loop counter

     if ( index <= size )
     {
        showSubtree(2*index+1,level+1);		// R
        for ( j = 1 ; j <= level ; j++ )	// tab 
            cout << "\t";
        cout << " " << node[index].key;		// D
        if ( 2*index+1 <= size )			// ������ ���
           cout << "<";
        else if ( 2*index <= size )
           cout << "\\";
        cout << endl;
        showSubtree(2*index, level+1);		// L
    }
}

//------------------< showSortSubtree >--------------------------
// Recursive partner of the showSort() function. 
//
void heap:: showSortSubtree (int index, int level, int sortSize)
{
     int j, oldTextColor;   
     if ( index <= sortSize )
     {
        showSortSubtree(2*index+1, level+1, sortSize);	// R
        for ( j = 1 ; j <= level ; j++ )        
            cout << '\t';
		oldTextColor = GetColor(0);
		if (index > size) 
				SetColor(12);							// ������
        cout << node[index].key;						// D
		SetColor(oldTextColor);							// ����������! 
		if ( 2*index+1 <= sortSize )                
           cout << '<';									// branch ���
        else if ( 2*index <= sortSize )
           cout << '\\';								// branch ���
        cout << endl;
        showSortSubtree(2*index, level+1, sortSize);	// L
    }
}

//------------------< heapSortTree >--------------------------
// heap sort ������ �ݽð�������� 90�� ���� Ʈ���������� ���δ�. 
//
void heap:: showSort(int size) 
{
    if ( isEmpty() )
		cout << "Empty heap" << endl;
	else
	{
		clrScr();								 //system("cls");	
		cout << "size = " << size << endl;       // �迭 �������� ���
		cout.setf(ios::right); 
		for ( int j = 1 ; j <= size ; j++ ) 
		{
			cout.width(5);
			cout << j << " : " << node[j].key << endl;
		}
		cout.unsetf(ios::right); 
		cout << endl;
		showSortSubtree(1, 0, size);
	}
}

//------------------< showSortSubtree >--------------------------
// Recursive partner of the showSort() function. 
//
void heap:: showConvertSubtree (int index, int level, int sortSize, int bottom)
{
    int j, oldTextColor; ;   
	if ( index <= sortSize )
	{
        showConvertSubtree(2*index+1, level+1, sortSize, bottom);	// R
        for ( j = 1 ; j <= level ; j++ )        
            cout << '\t';
		oldTextColor = GetColor(0);
		if (index <= bottom) 
			SetColor(12);								// ������
		cout << node[index].key;						// D
		SetColor(oldTextColor);							// ����������! 
		if ( 2*index+1 <= sortSize )                
			cout << '<';								// branch ���
        else if ( 2*index <= sortSize )
			cout << '\\';								// branch ���
        cout << endl;
        showConvertSubtree(2*index, level+1, sortSize, bottom);	// L
    }
}

//------------------< showConvert >--------------------------
// ��ȯ ������ �ݽð�������� 90�� ���� Ʈ���������� ���δ�. 
//
void heap:: showConvert(int bottom) 
{
    cout << endl;
    if ( isEmpty() )
		cout << "Empty heap" << endl;
	else
	{
		clrScr();								//system("cls");	
		cout << "size = " << size << endl;      // �迭 �������� ���
		cout.setf(ios::right); 
		for ( int j = 1 ; j <= size ; j++ ) 
		{
			cout.width(5);
			cout << j << " : " << node[j].key << endl;
		}
		cout.unsetf(ios::right); 
		cout << endl;
		showConvertSubtree(1, 0, size, bottom);
	}
}