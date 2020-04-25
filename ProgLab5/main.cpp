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
    T1 *QueuePointer;  // 㪠��⥫� �� ��।�
    int BeginQueue, EndQueue;  // ��砫� � ����� ��।�
    size_t size;  // ���ᨬ��쭮� ������⢮ ����⮢ � ��।�
    int ElementCounter;  // ���稪 ����⮢

public:
    // ��������� �� 㬮�砭��
    explicit Queue(int SizeQueue = 1):
            size(SizeQueue),  // ���樠������ ����⠭��
            BeginQueue(0), EndQueue(0), ElementCounter(0)
    {
        // �������⥫쭠� ����� ������� ��� ࠧ����� ����� � ��砫� ��।�
        QueuePointer = new T1[size + 1];
    }

    // �㭪�� ���������� ����� � ��।�
    T1 push(const T1 &NewElement)
    {
        // ��।� ��稭��� ����������� � 0 ������
        QueuePointer[EndQueue++] = NewElement;
        ElementCounter++;

        if (size == MaxSize)
            throw QueueOverflowException();

        // �஢�ઠ ��㣮���� ���������� ��।�
        if (EndQueue > size)
            EndQueue -= size + 1; // �����頥� end �� ��砫� ��।�

        return NewElement;
    }

    // �㭪�� 㤠����� ����� �� ��।�
    T1 pop()
    {
        T1 returnValue = QueuePointer[BeginQueue++];
        ElementCounter--;

        if (size == 0)
            throw EmptyQueueException();


        // �஢�ઠ ��㣮���� ���������� ��।�
        if (BeginQueue > size)
            BeginQueue -= size + 1; // �����頥� begin �� ��砫� ��।�

        return returnValue;
    }

    // ��������
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