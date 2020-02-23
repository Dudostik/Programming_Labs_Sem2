#ifndef PROGLAB1_FUNCS_H
#define PROGLAB1_FUNCS_H

struct SQARE
{
    float x1;
    float y1;
    float x2;
    float y2;
    float x3;
    float y3;
    float x4;
    float y4;
};

struct NEWSQARE
{
    float x1;
    float y1;
    float x2;
    float y2;
    float x3;
    float y3;
    float x4;
    float y4;
};

// TASK 5
void WholeReference (int &whole, double &decimals);
void WholePointer (int *pwhole, double *pdecimals);

// TASK 8
void ChangeReference(float &variable, float &inverse);
void ChangePointer(const float *pvariable, float *pinverse);

// TASK 13
void ShiftReference (SQARE &sh, float &vector);
void ShiftPointer (NEWSQARE *psh, const float *pvector);

// TASK 16
void MatrixReference(float (&matrix)[3][3]);
void MatrixPointer(float pmatrix[3][3]);

#endif //PROGLAB1_FUNCS_H
