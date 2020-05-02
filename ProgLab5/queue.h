#ifndef PROGLAB5_QUEUE_H
#define PROGLAB5_QUEUE_H


template<class T, size_t MaxSize>
class Queue
{
private:
    std::vector<T> _elements;
    size_t _size;

public:
    Queue()
    {
        _size = 0;
        _elements = std::vector<T>(MaxSize);
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


#endif //PROGLAB5_QUEUE_H
