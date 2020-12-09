#include <iostream>
using std::ostream;
template <typename ElemType>
class Matrix
{
    template <typename ValType>
    friend Matrix<ValType> operator+(const Matrix<ValType> &m1, const Matrix<ValType> &m2);
    template <typename ValType>
    friend Matrix<ValType> operator*(const Matrix<ValType> &m1, const Matrix<ValType> &m2);

public:
    Matrix(int rows, int columns);
    ~Matrix();
    Matrix(const Matrix &rhs);
    Matrix<ElemType> &operator=(const Matrix &rhs);
    void operator+=(const Matrix &rhs);
    ElemType &operator()(int row, int column);
    const ElemType &operator()(int row, int column) const;
    int rows() const;
    int cols() const;
    bool SameSize(const Matrix &m) const;
    bool Comfortable(const Matrix &m) const;
    ostream &print(ostream &os) const;

private:
    int _rows;
    int _cols;
    ElemType *_matrix;
};

template <typename ValType>
Matrix<ValType> operator+(const Matrix<ValType> &m1, const Matrix<ValType> &m2)
{
    if (!m1.SameSize(m2))
    {
        throw;
    }
    Matrix<ValType> res(m1);
    res += m2;
    return res;
}

template <typename ElemType>
Matrix<ElemType>::Matrix(int rows, int columns) : _rows(rows), _cols(columns)
{

    int size = _rows * _cols;
    _matrix = new ElemType[size];
    for (int ix = 0; ix < size; ++ix)
    {
        _matrix[ix] = ElemType();
    }
}

template <typename ElemType>
Matrix<ElemType>::~Matrix()
{
    delete[] _matrix;
}

template <typename ElemType>
Matrix<ElemType>::Matrix(const Matrix &rhs)
{
    _rows = rhs._rows;
    _cols = rhs._cols;
    int mat_size = _rows * _cols;
    _matrix = new ElemType[mat_size];
    for (size_t i = 0; i < mat_size; i++)
    {
        _matrix[i] = rhs._matrix[i];
    }
}

template <typename ElemType>
Matrix<ElemType> &Matrix<ElemType>::operator=(const Matrix &rhs)
{
    if (this != &rhs)
    {
        _rows = rhs._rows;
        _cols = rhs._cols;
        int mat_size = _rows * _cols;
        delete[] _matrix;
        _matrix = new ElemType[mat_size];
        for (size_t i = 0; i < mat_size; i++)
        {
            _matrix[i] = rhs._matrix[i];
        }
    }
    return *this;
}

template <typename ElemType>
ElemType &Matrix<ElemType>::operator()(int row, int column)
{
    return _matrix[row * cols() + column];
}

template <typename ElemType>
const ElemType &Matrix<ElemType>::operator()(int row, int column) const
{
    return _matrix[row * cols() + column];
}

template <typename ValType>
Matrix<ValType> operator*(const Matrix<ValType> &m1, const Matrix<ValType> &m2)
{
    if (!m1.Comfortable(m2))
    {
        throw;
    }
        
    Matrix<ValType> res(m1.rows(), m2.cols());
    for (size_t i = 0; i < m1.rows(); i++)
    {
        for (size_t j = 0; j < m2.cols(); j++)
        {
            res(i, j) = 0;
            for (size_t k = 0; k < m1.cols(); k++)
            {
                res(i, j) += m1(i, k) * m2(k, j);
            }
        }
    }
    return res;
}

template <typename ElemType>
int Matrix<ElemType>::rows() const
{
    return _rows;
}

template <typename ElemType>
int Matrix<ElemType>::cols() const
{
    return _cols;
}

template <typename ElemType>
bool Matrix<ElemType>::SameSize(const Matrix &m) const
{
    return rows() == m.rows() && cols() == m.cols();
}

template <typename ElemType>
bool Matrix<ElemType>::Comfortable(const Matrix &m) const
{
    return cols() == m.rows();
}

template <typename ElemType>
ostream &Matrix<ElemType>::print(ostream &os) const
{
    int col = cols();
    int mat_size = col * rows();
    for (size_t i = 0; i < mat_size; i++)
    {
        if (i % col == 0)
        {
            os << std::endl;
        }
        os << *(_matrix + i) << ' ';
    }
    os << std::endl;
    return os;
}

template <typename ElemType>
void Matrix<ElemType>::operator+=(const Matrix &rhs)
{
    int mat_size = cols() * rows();
    for (size_t i = 0; i < mat_size; i++)
    {
        *(_matrix + i) += *(rhs._matrix + i);
    }
}

template <typename ElemType>
ostream &operator<<(ostream &os, const Matrix<ElemType> &m)
{
    return m.print(os);
}

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream log("log.txt");
    if (!log)
    {
        cerr << "can't open log file!\n";
        return -1;
    }
    Matrix<float> identity(4, 4);
    log << "identity: " << identity << endl;
    float ar[16] = {1, 0, 0, 0, 0, 1, 0, 0,
                    0, 0, 1, 0, 0, 0, 0, 1};
    for (size_t i = 0, k = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            identity(i, j) = ar[k++];
        }
    }
    log << "identity after set: " << identity << endl;

    Matrix<float> m(identity);
    log << "m:memberwise initialized: " << m << endl;

    Matrix<float> m2(8, 12);
    log << "m2: 8x12" << m2 << endl;

    m2 = m;
    log << "m2 after memberwise assigned to m: " << m2 << endl;

    float ar2[16] = {1.3, 0.4, 2.6, 8.2, 6.2, 1.7, 1.3, 8.3, 4.2, 7.4, 2.7, 1.9, 6.3, 8.1, 5.6, 6.6};
    Matrix<float> m3(4, 4);
    for (size_t i = 0, k = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            m3(i, j) = ar2[k++];
        }
    }
    log << "m3: assigned random values " << m3 << endl;

    Matrix<float> m4 = m3 * identity;
    log << m4 << endl;
    Matrix<float> m5 = m3 + m4;
    log << m5 << endl;

    m3 += m4;
    log << m3 << endl;
}