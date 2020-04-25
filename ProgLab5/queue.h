#ifndef PROGLAB5_QUEUE_H
#define PROGLAB5_QUEUE_H
using namespace std;


template<class T, size_t MaxSize>
class Queue
{
private:
    vector<T> _elements;
    size_t _size;

public:
    Queue()
    {
        _size = 0;
        _elements = vector<T>(MaxSize);
    }

    void push(T element)
    {
        if (_size == MaxSize)
            throw QueueOverflowException();
        _elements[_size++] = element;
    }

    T pop()
    {
        if (_size == 0)
            throw EmptyQueueException();

        return _elements[--_size];
    }
};


class QueueException: public exception {};


class QueueOverflowException: public QueueException
{
public:
    [[nodiscard]] const char *what() const noexcept override
    {
        return "Queue is overflowed!\n";
    }
};


class EmptyQueueException: public QueueException
{
public:
    [[nodiscard]] const char *what() const noexcept override
    {
        return "Queue is empty!\n";
    }
};

#endif //PROGLAB5_QUEUE_H
