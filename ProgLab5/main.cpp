#include <iostream>
#include <vector>
#include "queue.h"
#include "MinElement.h"
using namespace std;


int main()
{
    cout << "\nTASK 1" << endl;
    cout << "Min element: " << MinElement(5, 6) << endl;


    cout << "\nTASK 2" << endl;
    cout << "Queue:\n";
    Queue<int, 1> queue;

    cout << "Push 1 in queue" << endl;
    queue.push(1);

    cout << "Pop " << queue.pop() << " from queue" << endl;

    try
    {
        cout << "Try pop from empty queue" << endl;
        queue.pop();
    }
    catch (EmptyQueueException &error)
    {
        cerr << "Error! " << error.what() << endl;
    }

    cout << "\nPush 1 in queue" << endl;
    queue.push(1);

    try
    {
        cout << "Try push 2 in full queue" << endl;
        queue.push(2);
    }
    catch (QueueOverflowException &error)
    {
        cerr << "Error! " << error.what() << endl;
    }
    return 0;
}