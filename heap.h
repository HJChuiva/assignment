//--------------------------------------------------------------------
//
//  Laboratory 7                                             heap.h
//
//  Class declaration for the array implementation of the heap ADT
//
//--------------------------------------------------------------------

class heapData
{
  public:

    void setKey ( int newKey )
    { key = newKey; }   

    int getKey () const
    { return key; }     

  private:
    int key;           

  friend class heap;
};

class heap
{
  public:

    // Constructor
    heap ();

    // Destructor
    ~heap ();

    // ��ȯ��
    void insert(heapData newData);			// insert data
    heapData removeMax();					// remove and return max data
    void clear ();                          // clear heap
	void read (ifstream &input_file ) ;		// read data from file => heap 
	void tempRead (ifstream &input_file ) ;	// read data from file => binary tree (����ȯ�� ���)
	void copy (heap &);						// copy heap (�����Ŀ� ���)
	void siftDown (int bottom, int top);	// parent <-> child (convert ���� ȣ��)
	void convert();							// complete binary tree => heap (����ȯ�� ���)

    // ������
    bool isEmpty () ;			            // heap is empty
    bool isFull () ;				        // heap is full

	int leafCount () ;						// # of leaf nodes
	int nonLeafCount () ;					// # of nonleaf nodes
	int totalCount () ;						// # of nodes
	int singleCount () ;					// # of single child nodes   
	int height() ;							// height of heap 

	//  heap �� ����ϱ� ���� �������� �Լ�: ������
    void showStructure () ;
	void showSort(int size) ;
	void showConvert(int bottom);

	void levelOrder();						// ���� 212
	void sort();

private:

    // Recursive partner of the showStructure() function
    void showSubtree ( int index, int level ) ;
	void showSortSubtree (int index, int level, int sortSize);
	void showConvertSubtree (int index, int level, int sortSize, int bottom);
	int  largerChild(int hole);

    // Data members
    int size;								// Actual number of elements in the heap
    heapData node[Max+1];					// Array containing the heap elements
};