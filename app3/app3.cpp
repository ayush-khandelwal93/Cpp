#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

mutex m;
void f1()
{
    cout<<"f1"<<endl;
    cout<<"f1"<<endl;
}
void f2()
{
    cout<<"f2"<<endl;
    cout<<"f2"<<endl;
}
int main()
{

    thread t1(f1);

    f2();

    t1.join();


    /*
    No synchronization achieved yet
    2 diff results in 2 executions
    RESULT-1
    f2
    f2
    f1
    f1
    RESULT-2
    f2f1
    f2

    f1
    */


    /*
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
    */
}