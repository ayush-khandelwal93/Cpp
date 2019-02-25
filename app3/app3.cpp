#include<iostream>
#include<thread>
using namespace std;
int main()
{
    //// Main Thread creates t1 object and calls its ctor.
	//// In the ctro secondary thread is created.
	//// Main thread comes out of the ctor and goes to next instruction
    thread t1( [] () {
        while(true) //Secondary thread
        {
            cout<<"W1"<<endl;
        }
    });
    while(true) //Main thread
    {
        cout<<"W2"<<endl;
    }
}