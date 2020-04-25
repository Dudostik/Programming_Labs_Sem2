#include <iostream>
#include <vector>
#include "queue.h"
#include "MinElement.h"
using namespace std;


/*
template<class T1, size_t MaxSize>
class Queue
{
private:
    T1 *QueuePointer;  // указатель на очередь
    int BeginQueue, EndQueue;  // начало и конец очереди
    size_t size;  // максимальное количество элементов в очереди
    int ElementCounter;  // счетчик элементов

public:
    // конструктор по умолчанию
    explicit Queue(int SizeQueue = 1):
            size(SizeQueue),  // инициализация константы
            BeginQueue(0), EndQueue(0), ElementCounter(0)
    {
        // дополнительная позици поможет нам различать конец и начало очереди
        QueuePointer = new T1[size + 1];
    }

    // функция добавления элемента в очередь
    T1 push(const T1 &NewElement)
    {
        // очередь начинает заполняться с 0 индекса
        QueuePointer[EndQueue++] = NewElement;
        ElementCounter++;

        if (size == MaxSize)
            throw QueueOverflowException();

        // проверка кругового заполнения очереди
        if (EndQueue > size)
            EndQueue -= size + 1; // возвращаем end на начало очереди

        return NewElement;
    }

    // функция удаления элемента из очереди
    T1 pop()
    {
        T1 returnValue = QueuePointer[BeginQueue++];
        ElementCounter--;

        if (size == 0)
            throw EmptyQueueException();


        // проверка кругового заполнения очереди
        if (BeginQueue > size)
            BeginQueue -= size + 1; // возвращаем begin на начало очереди

        return returnValue;
    }

    // деструктор
    ~Queue()
    {
        delete [] QueuePointer;
    }
};
*/


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