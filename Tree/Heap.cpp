#include <iostream>
using namespace std;

class MinHeap
{
private:
    int* heap;
    int arraysize;
    int heapsize;
    inline int Parent(int index);
    inline int LeftChild(int index);
    inline int RightChild(int index);
public:
    MinHeap(int arraysize);
    ~MinHeap();
    void Insert(int key);
    void MinHeapify(int index);
    int ExtractMin();
    int Delete(int index);
    void DecreaseKey(int i, int newvalue);
    int GetMin();
    static MinHeap* Merge(MinHeap* heap1, MinHeap* heap2);

};
MinHeap* MinHeap::Merge(MinHeap* heap1 , MinHeap* heap2)
{
    MinHeap* resheap = new MinHeap(heap1->arraysize + heap2->arraysize);
    for (int i = 0; i < heap1->heapsize; i++)
        resheap->heap[i] = heap1->heap[i];
    for (int i = 0; i < heap2->heapsize; i++)
        resheap->heap[heap1->heapsize +i] = heap2->heap[i];
    resheap->heapsize = heap1->heapsize + heap2->heapsize;
   
    for (int i = (resheap->heapsize)/2 ; i >= 0; i--)
        resheap->MinHeapify(i);

    return resheap;
}
int MinHeap::GetMin()
{
    return heap[0];
}
void MinHeap::DecreaseKey(int i, int newvalue)
{
    heap[i] = newvalue;
    while (Parent(i) != -1 && heap[Parent(i)] > heap[i])
    {
        swap(heap[i], heap[Parent(i)]);
        i = Parent(i);
    }
}
int MinHeap::Delete(int index)
{
    int res;
    if (heapsize <= 0)
        throw exception();
    else if (heapsize == 1)
        res = heap[heapsize--];
    else
    {
        res = heap[index];
        swap(heap[index], heap[heapsize]);
        heapsize--;
        MinHeapify(index);
        while (Parent(index) != -1 && heap[index] < heap[Parent(index)])
        {
            swap(heap[index], heap[Parent(index)]);
            index = Parent(index);
        }
    }
    return res;
}
MinHeap::MinHeap(int arraysize) : arraysize(arraysize), heapsize(0)
{
    heap = new int[arraysize];
    memset(heap, 0, arraysize);
}
MinHeap::~MinHeap()
{
    delete heap;
}
int MinHeap::Parent(int index)
{
    return (index - 1) / 2;
}
int MinHeap::LeftChild(int index)
{
    return 2 * index + 1 < heapsize ? 2 * index + 1 : -1;
}
int MinHeap::RightChild(int index)
{
    return 2 * index + 2 < heapsize ? 2 * index + 2 : -1;
}
void MinHeap::Insert(int key)
{
    if (heapsize < arraysize)
    {
        heap[heapsize] = key;
        int current = heapsize;
        int parent = Parent(current);
        while (parent!= -1 && heap[current] < heap[parent] && current > 0)
        {
            swap(heap[current], heap[parent]);
            current = parent;
            parent = Parent(current);
        }
        heapsize++;
    }
    else throw exception();
}
void MinHeap::MinHeapify(int index)
{
    if (heapsize <= 0) throw exception();
    if (heapsize > 1)
    {

        int l = LeftChild(index);
        int r = RightChild(index);
        int smallest = index;
        if (l != -1 && heap[l] < heap[index])
            smallest = l;
        if (r != -1 && heap[r] < heap[smallest])
            smallest = r;
        if (smallest != index)
        {
            swap(heap[index], heap[smallest]);
            MinHeapify(smallest);
        }
    }
}

int MinHeap::ExtractMin()
{
    int res;
    if (heapsize <= 0)
        throw exception();
    else if (heapsize == 1)
        res = heap[heapsize--];
    else
    {
        res = heap[0];
        swap(heap[0], heap[heapsize-1]);
        heapsize--;
        MinHeapify(0);
    }
    return res;
}
int main()
{
    MinHeap heap1(10);
    heap1.Insert(3);
    heap1.Insert(2);
    heap1.Insert(1);
    heap1.Insert(15);
    heap1.Insert(5);
    heap1.Insert(4);
    heap1.Insert(45);
    cout << heap1.ExtractMin() << " ";
    cout << heap1.ExtractMin() << " ";
    heap1.DecreaseKey(3, -2);
    cout << heap1.GetMin() << " ";

    MinHeap heap2(5);
    heap2.Insert(1);
    heap2.Insert(5);
    heap2.Insert(-10);
    heap2.Insert(2);
    MinHeap heapMerge = *MinHeap::Merge(&heap1,&heap2);
    cout << heapMerge.ExtractMin() << " ";
    cout << heapMerge.ExtractMin() << " ";
    return 0;
}
