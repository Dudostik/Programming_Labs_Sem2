#include <iostream>
#include <vector>
#include <set>
#include "algorithms.h"
using namespace std;


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