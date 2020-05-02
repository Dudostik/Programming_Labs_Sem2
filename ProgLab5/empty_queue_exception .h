#ifndef PROGLAB5_EMPTY_QUEUE_EXCEPTION_H
#define PROGLAB5_EMPTY_QUEUE_EXCEPTION_H


class EmptyQueueException: public QueueException
{
public:
    [[nodiscard]] const char *what() const noexcept override
    {
        return "Queue is empty!\n";
    }
};


#endif //PROGLAB5_EMPTY_QUEUE_EXCEPTION_H
