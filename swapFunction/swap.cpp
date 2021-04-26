// swap 
#include<iostream>
using namespace std;
template<class T>
void InplaceSwap(T& input1 , T& input2)
{
    input1 = input1 + input2;
    input2 = input1 - input2;  // intput2 = (input1 + input2) - input2
    input1 = input1 - input2;  // intput2 = (input1 + input2) - input1
}
template<class T>
void OutInplaceSwap(T& input1 , T& input2)
{
    T Auxiliary;
    Auxiliary = input1;
    input1 = input2;
    input2 = Auxiliary;
}
int main()
{
    int a = 2;
    int b = 5;
    cout << "Initial a = " << a << endl;
    cout << "Initial b = " << b << endl;
    cout << "In-place Swap : "  << endl;
    InplaceSwap(a,b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "Out-In-place Swap : "  << endl;
    OutInplaceSwap(a,b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return 0;
}
