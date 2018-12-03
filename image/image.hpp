#include "image.h"

template<typename T>
codelib::image<T>::image()
{ }


template<typename T>
codelib::image<T>::image(const unsigned &width, const unsigned &height) : _data(width, height)
{ }


template<typename T>
codelib::image<T>::image(const codelib::image<T> &other) : _data(other._data)
{ }


template<typename T>
codelib::image<T>& codelib::image<T>::operator=(const codelib::image<T> &other)
{
    if (this != &other)
        _data = other._data;
    return *this;
}


template<typename T>
codelib::image<T>::~image()
{ }


template<typename T>
T& codelib::image<T>::operator()(const unsigned &row, const unsigned &col)
{
    return _data(row, col);
}


template<typename T>
const T& codelib::image<T>::operator()(const unsigned &row, const unsigned &col) const
{
    return _data(row, col);
}


template<typename T>
const unsigned& codelib::image<T>::get_width() const
{
    return _data.get_num_rows();
}


template<typename T>
const unsigned& codelib::image<T>::get_height() const
{
    return _data.get_num_cols();
}


template<typename T>
codelib::image<T>& codelib::image<T>::operator+=(const T &rhs)
{
    _data += rhs;
    return *this;
}


template<typename T>
codelib::image<T> &codelib::image<T>::operator+=(const codelib::image<T> &rhs)
{
    _data += rhs._data;
    return *this;
}


template<typename T>
codelib::image<T> &codelib::image<T>::operator-=(const T &rhs)
{
    _data -= rhs;
    return *this;
}


template<typename T>
codelib::image<T> &codelib::image<T>::operator-=(const codelib::image<T> &rhs)
{
    _data -= rhs._data;
    return *this;
}


template<typename T>
codelib::image<T> &codelib::image<T>::operator*=(const T &rhs)
{
    _data *= rhs;
    return *this;
}


template<typename T>
codelib::image<T> &codelib::image<T>::operator*=(const codelib::image<T> &rhs)
{
    for (unsigned i = 0; i < _data.get_num_rows() ; ++i)
        for (unsigned j = 0; j < _data.get_num_cols(); ++j)
            _data(i,j) *= rhs._data(i,j);

    return *this;
}


template<typename T>
codelib::image<T> &codelib::image<T>::operator/=(const T &rhs)
{
    _data /= rhs;
    return *this;
}


template<typename T>
codelib::image<T> &codelib::image<T>::operator/=(const codelib::image<T> &rhs)
{
    for (unsigned i = 0; i < _data.get_num_rows() ; ++i)
        for (unsigned j = 0; j < _data.get_num_cols(); ++j)
            _data(i,j) /= rhs._data(i,j);

    return *this;
}
