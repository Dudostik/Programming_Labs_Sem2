#include <iostream>
#include <vector>
#include <set>
using namespace std;


bool predicate_function(int x)
{
    return x < 0;
}


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


int main()
{
    vector<int> A = {1, 2, 3};
    set<double> B = {-1, -2, -3};
    set<double> C = {1, -2, 3};
    cout << "\nA) " << all_of(A.begin(), A.end(), predicate_function) << "\tB) " << all_of(B.begin(), B.end(), predicate_function) << endl;
    cout << "A) " << one_of(A.begin(), A.end(), predicate_function) << "\tB) " << one_of(B.begin(), B.end(), predicate_function)
                                                   << "\tC) " << one_of(C.begin(), C.end(), predicate_function) << endl;
    cout << "A) " << find_backward(A.end(), A.begin(), 1) << "\tB) " << find_backward(B.end(), B.begin(), 1)
                                                           << "\tC) " << find_backward(C.end(), C.begin(), -2) <<endl;
}