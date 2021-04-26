#include<iostream>
using namespace std;
#define MAXSIZE 1000
template <class T>
class Stack {
    int top;
public:
    T a[MAXSIZE];

    Stack() 
    { 
        top = -1;
    }
    bool push(int x)
    {
        if (isfull()) {
            throw ( "Stack Overflow");
        }
        else {
            a[++top] = x;
            cout << x << " pushed into stack\n";
            return true;
        }
    }
    int pop()
    {
        if (isEmpty()) {
            throw ("Stack Underflow");
        }
        else {
            int x = a[top--];
            return x;
        }
    }
    int peek()
    {
        if (isEmpty()) {
            throw ("Stack is Empty");
        }
        else {
            int x = a[top];
            return x;
        }
    }
    bool isEmpty()
    {
        return (top == -1);
    }
    bool isfull() {
        return top == MAXSIZE;
    }
};
// Driver program to test above functions
int main()
{
    class Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    // print top element in stack and remove it
    cout << s.pop() << " Popped from stack\n";
    //print all elements in stack :
    cout << "Elements present in stack : ";
    while (!s.isEmpty())
    {
        // print top element in stack
        cout << s.peek() << " ";
        // remove top element in stack
        s.pop();
    }
    return 0;
}
