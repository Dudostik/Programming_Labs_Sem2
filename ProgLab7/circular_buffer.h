#ifndef PROGLAB7_CIRCULAR_BUFFER_H
#define PROGLAB7_CIRCULAR_BUFFER_H


#include <iterator>
#include <exception>


template <class T>
class circular_buffer
{
public:
    explicit circular_buffer(size_t Capacity)
    {
        capacity_ = Capacity;
        data_ = new T[capacity_ + 1];
        front_ = 0;
        back_ = 0;
    }

    [[nodiscard]] bool empty() const
    {
        return front_ == back_;
    }

    void push_back(const T &Item)
    {
        if (back_ == (front_ - 1 + capacity_ + 1) % (capacity_ + 1))
        {
            front_ = (front_ + 1) % (capacity_ + 1);
        }

        data_[back_] = Item;
        back_ = (back_ + 1) % (capacity_ + 1);
    }

    void push_front(const T &Item)
    {
        if (back_ == (front_ - 1 + capacity_ + 1) % (capacity_ + 1))
        {
            back_ = (back_ - 1 + capacity_ + 1) % (capacity_ + 1);
        }

        front_ = (front_ - 1 + capacity_ + 1) % (capacity_ + 1);
        data_[front_] = Item;
    }

    void resize(size_t NewCapacity)
    {
        T *buffer = new T[NewCapacity + 1];
        copy(buffer, std::min((back_ - front_ + capacity_ + 1) % (capacity_ + 1), NewCapacity));
        delete[] data_;
        data_ = buffer;
        capacity_ = NewCapacity;
        front_ = 0;
        back_ = NewCapacity;
    }

    void pop_back()
    {
        if (empty())
        {
            throw std::runtime_error("Empty buffer error");
        }
        else
        {
            back_ = (back_ - 1 + capacity_ + 1) % (capacity_ + 1);
        }
    }

    void pop_front()
    {
        if (empty())
        {
            throw std::runtime_error("Empty buffer error");
        }
        else
        {
            front_ = (front_ + 1) % (capacity_ + 1);
        }
    }

    T &back()
    {
        return data_[(back_ - 1 + capacity_ + 1) % (capacity_ + 1)];
    }

    T &front() const
    {
        return data_[front_];
    }

    T &operator[](size_t Index)
    {
        return data_[(front_ + Index) % (capacity_ + 1)];
    }

    const T &operator[](size_t Index) const
    {
        return data_[(front_ + Index) % (capacity_ + 1)];
    }

    [[nodiscard]] size_t size() const
    {
        return (back_ - front_ + capacity_ + 1) % (capacity_ + 1);
    }

    class circular_buffer_iterator : public std::iterator <std::random_access_iterator_tag, T>
    {
    private:
        size_t it_position_{};
        circular_buffer <T>* buffer_;

    public:
        circular_buffer_iterator(){}

        circular_buffer_iterator(circular_buffer <T> *Buffer, size_t Position)
        {
            this->it_position_ = Position;
            this->buffer_ = Buffer;
        }

        circular_buffer_iterator(const circular_buffer_iterator &Iterator)
        {
            this->buffer_ = Iterator.buffer_;
            this->it_position_ = Iterator.it_position_;
        }

        T& operator*()
        {
            return (*buffer_)[it_position_];
        }

        circular_buffer_iterator& operator++()
        {
            it_position_ = buffer_->inc(it_position_, 1);
            return *this;
        }

        circular_buffer_iterator& operator+=(int Value)
        {
            it_position_ = buffer_->inc(it_position_, Value);
            return *this;
        }

        circular_buffer_iterator operator+(int Value) const
        {
            return circular_buffer_iterator(buffer_, buffer_->inc(it_position_, Value));
        }

        circular_buffer_iterator operator+(const circular_buffer_iterator &Iterator) const
        {
            return circular_buffer_iterator(buffer_, buffer_->dec(it_position_, Iterator.it_position_));
        }

        circular_buffer_iterator& operator--()
        {
            it_position_ = buffer_->dec(it_position_, 1);
            return *this;
        }

        circular_buffer_iterator& operator-=(int Value)
        {
            it_position_ = buffer_->dec(it_position_, Value);
            return *this;
        }

        circular_buffer_iterator operator-(int Value) const
        {
            return circular_buffer_iterator(buffer_, buffer_->dec(it_position_, Value));
        }

        ptrdiff_t operator-(const circular_buffer_iterator &Iterator) const
        {
            return buffer_->dec(it_position_, Iterator.it_position_);
        }

        bool operator==(const circular_buffer_iterator &Iterator) const
        {
            return it_position_ == Iterator.it_position_;
        }

        bool operator!=(const circular_buffer_iterator &Iterator) const
        {
            return !(*this == Iterator);
        }

        bool operator<(const circular_buffer_iterator &Iterator) const
        {
            if (it_position_ < buffer_->front_ && Iterator.it_position_ < buffer_->front_ ||
                it_position_ >= buffer_->front_ && Iterator.it_position_ >= buffer_->front_)
            {
                return it_position_ < Iterator.it_position_;
            }
            else
            {
                return it_position_ > Iterator.it_position_;
            }
        }

        bool operator>(const circular_buffer_iterator &Iterator) const
        {
            return !(*this < Iterator);
        }

        bool operator<=(const circular_buffer_iterator &Iterator) const
        {
            return *this < Iterator || *this == Iterator;
        }

        bool operator>=(const circular_buffer_iterator &Iterator) const
        {
            return *this > Iterator || *this == Iterator;
        }
    };

    circular_buffer_iterator begin()
    {
        return circular_buffer_iterator(this, 0);
    }

    circular_buffer_iterator end()
    {
        return circular_buffer_iterator(this, back_);
    }

    circular_buffer_iterator insert(const circular_buffer_iterator& Iterator, const T &Item)
    {
        auto it = Iterator;
        T buffer = Item;
        back_ = (back_ + 1) % (capacity_ + 1);
        for (; it != end(); ++it)
        {
            std::swap(*it, buffer);
        }
        if (back_ == front_)
        {
            front_ = (front_ + 1) % (capacity_ + 1);
        }
        return Iterator;
    }

    void erase(circular_buffer_iterator Iterator)
    {
        auto it = end() - 1;
        T buffer = *it;
        for (; Iterator <= it; --it)
        {
            std::swap(*it, buffer);
        }
        back_ = (back_ - 1 + capacity_ + 1) % (capacity_ + 1);
    }

    ~circular_buffer()
    {
        delete[] data_;
    }

private:
    T* data_;
    size_t capacity_;
    size_t front_;
    size_t back_;

    [[nodiscard]] size_t inc(size_t Position, int Value) const
    {
        return (Position + Value) % (capacity_ + 1);
    }

    [[nodiscard]] size_t dec(size_t Position, int Value) const
    {
        return (Position - Value + capacity_ + 1) % (capacity_ + 1);
    }

    void copy(T* Destination, size_t Size) const
    {
        for (int i = 0; i < Size; i++)
        {
            Destination[i] = (*this)[i];
        }
    }
};


template <class Type>
void print(const circular_buffer <Type> &Buffer)
{
    for (int i = 0; i < Buffer.size(); i++)
    {
        std::cout << Buffer[i] << ' ';
    }
    std::cout << std::endl;
}


#endif //PROGLAB7_CIRCULAR_BUFFER_H
