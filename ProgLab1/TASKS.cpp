#include <iostream>
#include <cmath>
#include "funcs.h"
using namespace std;


// TASK 5
void WholeReference (int &whole, double &decimals)
{
    whole = decimals;
    decimals -= whole;
}

void WholePointer (int *pwhole, double *pdecimals)
{
    *pwhole = *pdecimals;
    *pdecimals -= *pwhole;
}

// TASK 8
void ChangeReference(float &variable, float &inverse)
{
    inverse = pow(variable, -1);
}

void ChangePointer(const float *pvariable, float *pinverse)
{
    *pinverse = pow(*pvariable, -1);
}


// TASK 13
void ShiftReference (SQARE &sh, float &vector)
{
    sh.x1 += vector;
    sh.y1 += vector;
    sh.x2 += vector;
    sh.y2 += vector;
    sh.x3 += vector;
    sh.y3 += vector;
    sh.x4 += vector;
    sh.y4 += vector;
}

void ShiftPointer (NEWSQARE *psh, const float *pvector)
{
    psh -> x1 += *pvector;
    psh -> y1 += *pvector;
    psh -> x2 += *pvector;
    psh -> y2 += *pvector;
    psh -> x3 += *pvector;
    psh -> y3 += *pvector;
    psh -> x4 += *pvector;
    psh -> y4 += *pvector;
}


// TASK 16
void MatrixReference(float (&matrix)[3][3])
{
    int string1, string2;
    cout << "Enter the lines you want to swap:" << endl;
    cout << "1)";
    cin >> string1;
    cout << "2)";
    cin >> string2;
    cout << endl;
    float temp;
    for (int j = 0; j < 3; j ++)
    {
        temp = matrix[string1][j];
        matrix[string1][j] = matrix[string2][j];
        matrix[string2][j] = temp;
    }
}

void MatrixPointer(float pmatrix[3][3])
{
    int string1, string2;
    cout << "Enter the lines you want to swap:" << endl;
    cout << "1)";
    cin >> string1;
    cout << "2)";
    cin >> string2;
    cout << endl;
    float temp;
    for (int j = 0; j < 3; j ++)
    {
        temp = pmatrix[string1][j];
        pmatrix[string1][j] = pmatrix[string2][j];
        pmatrix[string2][j] = temp;
    }
}

