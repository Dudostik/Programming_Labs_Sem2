#include <iostream>
#include "funcs.h"
using namespace std;


int main()
{
    int whole;
    double decimals;

    float variable;
    float inverse;

    float vector;
    SQARE sh = {1, 1, 3, 1, 1, 3, 3, 3};
    NEWSQARE psh = {1, 1, 3, 1, 1, 3, 3, 3};

    const int ROW = 3;
    const int COL = 3;
    float matrix[ROW][COL];
    int i, j;

    // Discards from the material number of it's whole part
    cout << "\n/*TASK 5*/" << endl;
    cout << "Enter the number:";
    cin  >> decimals;
    cout << "decimals = " << decimals << endl;

    cout << "\nWholeReference" << endl;
    WholeReference (whole, decimals);
    cout << "decimals = " << decimals << endl;

    cout << "\nWholePointer" << endl;
    WholePointer (&whole, &decimals);
    cout << "decimals = " << decimals << endl;

    // Changes the physical variable to the reverse number
    cout << "\n/*TASK 8*/" << endl;
    cout << "Enter the number:";
    cin  >> variable;
    cout << "variable = " << variable << endl;

    cout << "\nChangeReference" << endl;
    ChangeReference(variable, inverse);
    cout << "inverse = " << inverse << endl;

    cout << "\nChangePointer" << endl;
    ChangePointer(&variable, &inverse);
    cout << "inverse = " << inverse << endl;

    // Moves the square to a given vector
    cout << "\n/*TASK 13*/" << endl;
    cout << "Enter the vector: ";
    cin >> vector;
    cout << "vector = " << vector << endl;

    cout << "\nShiftReference" << endl;
    ShiftReference (sh, vector);
    cout << "(" << sh.x1 << "; " << sh.y1 << ")" << " " << "(" <<  sh.x2 << "; " << sh.y2 << ")" << " " << "(" << sh.x3 << "; " << sh.y3 << ")" << " " << "(" << sh.x4 << "; " << sh.y4 << ")" << endl;

    cout << "\nShiftPointer" << endl;
    ShiftPointer (&psh, &vector);
    cout << "(" << sh.x1 << "; " << sh.y1 << ")" << " " << "(" <<  sh.x2 << "; " << sh.y2 << ")" << " " << "(" << sh.x3 << "; " << sh.y3 << ")" << " " << "(" << sh.x4 << "; " << sh.y4 << ")" << endl;

    // Changes two specified rows in the matrix
    cout << "\n/*TASK 16*/" << endl;
    cout << "Enter the firs row:" << endl;
    cin >> matrix[0][0] >> matrix[0][1] >> matrix[0][2];
    cout << "Enter the second row:" << endl;
    cin >> matrix[1][0] >> matrix[1][1] >> matrix[1][2];
    cout << "Enter the third row:" << endl;
    cin >> matrix[2][0] >> matrix[2][1] >> matrix[2][2];

    cout << "\nMatrix:" << endl;
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            cout << matrix[i][j] << '\t';
        }
        cout << endl;
    }

    cout << "\nMatrixReference" << endl;
    MatrixReference (matrix);
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            cout << matrix[i][j] << '\t';
        }
        cout << endl;
    }

    cout << "\nMatrixPointer" << endl;
    MatrixPointer (matrix);
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            cout << matrix[i][j] << '\t';
        }
        cout << endl;
    }
    return 0;
}