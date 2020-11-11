#include "matrix.h"

// ctor
Matrix::Matrix(const ElemType *arr)
{
    int arr_ix = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            matrix_[i][j] = arr[arr_ix++];
        }
    }
}
Matrix::Matrix(ElemType a11, ElemType a12, ElemType a13, ElemType a14,
               ElemType a21, ElemType a22, ElemType a23, ElemType a24,
               ElemType a31, ElemType a32, ElemType a33, ElemType a34,
               ElemType a41, ElemType a42, ElemType a43, ElemType a44)
{
    matrix_[0][0] = a11;
    matrix_[0][1] = a12;
    matrix_[0][2] = a13;
    matrix_[0][3] = a14;
    matrix_[1][0] = a21;
    matrix_[1][1] = a22;
    matrix_[1][2] = a23;
    matrix_[1][3] = a24;
    matrix_[2][0] = a31;
    matrix_[2][1] = a32;
    matrix_[2][2] = a33;
    matrix_[2][3] = a34;
    matrix_[3][0] = a41;
    matrix_[3][1] = a42;
    matrix_[3][2] = a43;
    matrix_[3][3] = a44;
}

ostream &Matrix::print(ostream &os) const
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            os << matrix_[i][j] << ' ';
        }
        os << '\n';
    }
    return os;
}
void Matrix::operator+=(const Matrix &rhs)
{
    for (int i = 0; i < rhs.rows(); i++)
    {
        for (int j = 0; j < rhs.cols(); ++j)
        {
            matrix_[i][j] += rhs.matrix_[i][j];
        }
    }
}

ostream &operator<<(ostream &os, const Matrix &m)
{
    return m.print(os);
}

Matrix operator+(const Matrix &m1, const Matrix &m2)
{
    Matrix result(m1);
    result += m2;
    return result;
}

Matrix operator*(const Matrix &m1, const Matrix &m2)
{
    Matrix result;
    for (int i = 0; i < m1.rows(); i++)
    {
        for (int j = 0; j < m1.cols(); j++)
        {
            result(i, j) = 0;
            for (int k = 0; k < m1.cols(); ++k)
            {
                result(i, j) += m1(i, k) * m2(k, j);
            }
        }
    }
    return result;
}