#ifndef PROGLAB5_QUEUE_OVERFLOW_EXCEPTION_H
#define PROGLAB5_QUEUE_OVERFLOW_EXCEPTION_H


class QueueOverflowException: public QueueException
{
public:
    [[nodiscard]] const char *what() const noexcept override
    {
        return "Queue is overflowed!\n";
    }
};


#endif //PROGLAB5_QUEUE_OVERFLOW_EXCEPTION_H
