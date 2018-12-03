#include "matrix.h"

template<typename T>
codelib::matrix<T>::matrix() : _rows(0), _cols(0)
{ }


template<typename T>
codelib::matrix<T>::matrix(const unsigned &rows, const unsigned &cols)
{
    create(rows, cols);
}


template<typename T>
codelib::matrix<T>::matrix(const unsigned &rows, const unsigned &cols, const T &value)
{
    create(rows, cols);
    set_value(value);
}


template<typename T>
codelib::matrix<T>::matrix(const codelib::matrix<T> &other)
{
    create(other._rows, other._cols);

    const unsigned length = _rows * _cols;

    //#pragma omp parallel for
    for(unsigned i = 0; i < length; ++i)
        _matrix[i] = other._matrix[i];
}


template<typename T>
codelib::matrix<T>& codelib::matrix<T>::operator=(const codelib::matrix<T> &other)
{
    if (this != &other)
    {
        if ((_rows != other._rows) || (_cols != other._cols))
        {
            destroy();
            create(other._rows, other._cols);
        }

        const unsigned length = _rows * _cols;

        //#pragma omp parallel for
        for(unsigned i = 0; i < length; ++i)
            _matrix[i] = other._matrix[i];
    }
    return *this;
}


template<typename T>
codelib::matrix<T>::~matrix()
{
    destroy();
}


template<typename T>
T& codelib::matrix<T>::operator()(const unsigned &row, const unsigned &col)
{
    return _matrix[row * _cols + col];
}


template<typename T>
const T& codelib::matrix<T>::operator()(const unsigned &row, const unsigned &col) const
{
    return _matrix[row * _cols + col];
}

template<typename T>
void codelib::matrix<T>::set_value(const T &value)
{
    const unsigned length = _rows * _cols;

    //#pragma omp parallel for
    for(unsigned i = 0; i < length; ++i)
        _matrix[i] = value;
}


template<typename T>
const unsigned& codelib::matrix<T>::get_num_rows() const
{
    return _rows;
}


template<typename T>
const unsigned& codelib::matrix<T>::get_num_cols() const
{
    return _cols;
}


template<typename T>
void codelib::matrix<T>::swap_rows(const unsigned &from, const unsigned &to)
{
    //#pragma omp parallel for
    for(unsigned i = 0; i < _cols; ++i)
    {
        T temp = (*this)(to, i);
        (*this)(to, i) = (*this)(from, i);
        (*this)(from, i) = temp;
    }
}


template<typename T>
void codelib::matrix<T>::swap_cols(const unsigned &from, const unsigned &to)
{
    //#pragma omp parallel for
    for(unsigned i = 0; i < _rows; ++i)
    {
        T temp = (*this)(i, to);
        (*this)(i, to) = (*this)(i, from);
        (*this)(i, from) = temp;
    }
}


template<typename T>
codelib::matrix<T>& codelib::matrix<T>::operator+=(const T &rhs)
{
    const unsigned length = _rows * _cols;

    for(unsigned i = 0; i < length; ++i)
        _matrix[i] += rhs;

    return *this;
}


template<typename T>
codelib::matrix<T>& codelib::matrix<T>::operator+=(const codelib::matrix<T> &rhs)
{
    const unsigned length = _rows * _cols;

    for(unsigned i = 0; i < length; ++i)
        _matrix[i] += rhs._matrix[i];

    return *this;
}


template<typename T>
codelib::matrix<T>& codelib::matrix<T>::operator-=(const T &rhs)
{
    const unsigned length = _rows * _cols;

    for(unsigned i = 0; i < length; ++i)
        _matrix[i] -= rhs;

    return *this;
}


template<typename T>
codelib::matrix<T>& codelib::matrix<T>::operator-=(const codelib::matrix<T> &rhs)
{
    const unsigned length = _rows * _cols;

    for(unsigned i = 0; i < length; ++i)
        _matrix[i] -= rhs._matrix[i];

    return *this;
}


template<typename T>
codelib::matrix<T>& codelib::matrix<T>::operator*=(const T &rhs)
{
    const unsigned length = _rows * _cols;

    for(unsigned i = 0; i < length; ++i)
        _matrix[i] *= rhs;

    return *this;
}


template<typename T>
codelib::matrix<T>& codelib::matrix<T>::operator*=(const codelib::matrix<T> &rhs)
{
    //assert (!(_cols == rhs._rows) && "Wrong dimension!");
    codelib::matrix<T> result(_rows, rhs._cols, T());

    unsigned i, j, k;

    //#pragma omp parallel for private(i,j,k) schedule (static)
    for(i = 0; i < _rows; ++i)
        for(j = 0; j < rhs._cols; ++j)
            for (k = 0; k < rhs._rows; ++k)
                result(i, j) += ((*this)(i, k) * rhs(k, j));

    (*this) = result;
    return *this;
}


template<typename T>
codelib::matrix<T>& codelib::matrix<T>::operator/=(const T &rhs)
{
    return *this *= (1/rhs);
}


template <typename T>
void codelib::matrix<T>::create(const unsigned &rows, const unsigned &cols)
{
    _rows   = rows;
    _cols   = cols;
    _matrix = new T[rows * cols];
}


template<typename T>
void codelib::matrix<T>::destroy()
{
    if (_rows != 0 || _cols != 0)
        delete[] _matrix;

    _rows = _cols = 0;
}
