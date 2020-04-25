#ifndef PROGLAB6_ALGORITHMS_H
#define PROGLAB6_ALGORITHMS_H


bool predicate_function(int x);


template <typename I, typename Predicate>
bool all_of(const I &begin, const I &end, Predicate pred)
{
    for (auto iterator = begin; iterator != end; iterator = next(iterator))
    {
        if (pred(*iterator)) return true;
    }
    return false;
}


template<class I, class Predicate>
bool one_of(const I &begin, const I &end, Predicate pred)
{
    int count = 0;
    for (auto iterator = begin; iterator != end; iterator = next(iterator))
    {
        if (pred(*iterator)) count++;
    }
    return count == 1;
}


template <typename I, typename object>
object  find_backward(const I &begin, const I &end, const object v)
{
    for (auto iterator = end; iterator != begin; iterator = prev(iterator))
    {
        if (*iterator == v) return *iterator;
    }
    return object();
}


#endif //PROGLAB6_ALGORITHMS_H
