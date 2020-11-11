#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
using std::ostream;

class Matrix;
ostream &operator<<(ostream &os, const Matrix &m);
Matrix operator+(const Matrix &m1, const Matrix &m2);
Matrix operator*(const Matrix &m1, const Matrix &m2);

typedef float ElemType;
class Matrix
{
public:
    // ctor
    Matrix(const ElemType *array);
    Matrix(ElemType a11 = 0, ElemType a12 = 0, ElemType a13 = 0, ElemType a14 = 0,
           ElemType a21 = 0, ElemType a22 = 0, ElemType a23 = 0, ElemType a24 = 0,
           ElemType a31 = 0, ElemType a32 = 0, ElemType a33 = 0, ElemType a34 = 0,
           ElemType a41 = 0, ElemType a42 = 0, ElemType a43 = 0, ElemType a44 = 0);
    // rows cols
    int rows() const
    {
        return 4;
    }
    int cols() const { return 4; }

    ElemType operator()(int row, int col) const
    {
        return matrix_[row][col];
    }

    ElemType &operator()(int row, int col)
    {
        return matrix_[row][col];
    }

    // show
    ostream &print(ostream &os) const;
    void operator+=(const Matrix &rhs);

private:
    ElemType matrix_[4][4];

    friend ostream &operator<<(ostream &os, const Matrix &m);
    friend Matrix operator+(const Matrix &m1, const Matrix &m2);
    friend Matrix operator*(const Matrix &m1, const Matrix &m2);
};

#endif // __MATRIX_H__