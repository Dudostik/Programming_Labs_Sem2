#include <iostream>
#include <vector>
#include "min_element.h"
#include "queue.h"
#include "queue_exception.h"
#include "queue_overflow_exception.h"
#include "empty_queue_exception .h"


int main()
{
    std::cout << "\nTASK 1" << std::endl;
    std::cout << "Min element: " << MinElement(5, 6) << std::endl;


    std::cout << "\nTASK 2" << std::endl;
    std::cout << "Queue:\n";
    Queue<int, 1> queue;

    std::cout << "Push 1 in queue" << std::endl;
    queue.push(1);

    std::cout << "Pop " << queue.pop() << " from queue" << std::endl;

    try
    {
        std::cout << "Try pop from empty queue" << std::endl;
        queue.pop();
    }
    catch (EmptyQueueException &error)
    {
        std::cerr << "Error! " << error.what() << std::endl;
    }

    std::cout << "\nPush 1 in queue" << std::endl;
    queue.push(1);

    try
    {
        std::cout << "Try push 2 in full queue" << std::endl;
        queue.push(2);
    }
    catch (QueueOverflowException &error)
    {
        std::cerr << "Error! " << error.what() << std::endl;
    }
    return 0;
}