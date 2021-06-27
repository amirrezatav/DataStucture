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

};
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
    return 2 * index + 1 < arraysize ? 2 * index + 1 : -1;
}
int MinHeap::RightChild(int index)
{
    return 2 * index + 2 < arraysize ? 2 * index + 2 : -1;
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
        if (RightChild(index) != -1 && heap[index] > RightChild(index))
        {
            swap(heap[index], heap[RightChild(index)]);
            MinHeapify(RightChild(index));
        }
        else if (LeftChild(index) != -1 && index > LeftChild(index))
        {
            swap(heap[index], heap[LeftChild(index)]);
            MinHeapify(LeftChild(index));
        }
        else return;
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
    MinHeap heap(11);
    heap.Insert(3);
    heap.Insert(2);
    heap.Insert(1);
    heap.Insert(15);
    heap.Insert(5);
    heap.Insert(4);
    heap.Insert(45);
    cout << heap.ExtractMin() << " ";
    cout << heap.ExtractMin() << " ";
    heap.DecreaseKey(3, -2);
    cout << heap.GetMin();
    return 0;
}
