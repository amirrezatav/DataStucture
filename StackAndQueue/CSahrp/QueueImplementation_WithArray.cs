using System;
using System.Collections.Generic;

namespace StackAndQueue
{
    public class CircularQueue<T> : IQueue<T>
    {
        T[] Buffer;
        readonly uint BufferLen;
        // Shows the first full cell
        int _front;
        // Shows the first Empty cell
        int _rear;
        // Contorl _front for be Circular
        int Front {
            get { return _front; }
            set{_front = (value == BufferLen) ? 0 : value; }
        }
        // Contorl _rear for be Circular
        int Rear
        {
            get { return _rear; }
            set { _rear = (value == BufferLen) ? 0 : value; }
        }
        // return Queue Empty Cells Number
        public int EmptySize { get { return ((int)BufferLen - FullSize); } }
        // return Queue Full Cells Number
        public int FullSize { get { return (((int)BufferLen + (_rear - _front)) % (int)BufferLen); } }
        // this Constructor Get Queue MaxSize - 1
        public CircularQueue(uint bufferLen)
        {
            BufferLen = bufferLen;
            Buffer = new T[BufferLen];
            Front = 0;
            Rear = 0;
        }
        //remove all the objects from the stack.
        public void Clear()
        {
            Buffer = new T[BufferLen];
            Front = 0;
            Rear = 0;
        }
        public T Dequeue()
        {
            T res = (!IsEmpty()) ? Buffer[Front] : throw new OverflowException("Queue is Empty");
            Front++;
            return res;
        }
        public void Enqueue(T item)
        {
            Buffer[Rear] = (!IsFull()) ? item : throw new OverflowException ("Queue is full!");
            Rear++;

        }
        // return True if Front = Rear
        public bool IsEmpty()
        {
            return Front == Rear;
        }
        // return True If only one cell is empty
        public bool IsFull()
        {
            return Front == (Rear + 1)%BufferLen;
        }
        // returns the object at the beginning of the Queue without removing it.
        public T Peek()
        {
            return (!IsEmpty()) ? Buffer[Front] : throw new OverflowException("Queue is Empty");
        }
    }
