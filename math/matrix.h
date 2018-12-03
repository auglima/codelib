#ifndef CODELIB_MATRIX_H
#define CODELIB_MATRIX_H

#include <assert.h>  // assert
#include <iostream>  // ostream
#include <iomanip>   // setw
#include <omp.h>

namespace codelib {

    /**
     * @see https://eli.thegreenplace.net/2015/memory-layout-of-multi-dimensional-arrays/
     * @see https://en.wikipedia.org/wiki/Matrix_(mathematics)
     * @tparam T
     */
    template<typename T>
    class matrix {
    public:
        matrix();
        matrix(const unsigned &rows, const unsigned &cols);
        matrix(const unsigned &rows, const unsigned &cols, const T &value);

        matrix(const matrix<T> &other);
        //matrix(const matrix<T> &&other) = delete;

        matrix<T>& operator=(const matrix<T> &other);
        //matrix& operator=(const matrix &&other) = delete;

        virtual ~matrix();

        T& operator()(const unsigned &row, const unsigned &col);
        const T& operator()(const unsigned &row, const unsigned &col) const;

        void set_value(const T &value);

        const unsigned& get_num_rows() const;
        const unsigned& get_num_cols() const;

        void swap_rows(const unsigned &from, const unsigned &to);
        void swap_cols(const unsigned &from, const unsigned &to);

        matrix<T>& operator+=(const T &rhs);
        matrix<T>& operator+=(const matrix<T> &rhs);
        matrix<T>& operator-=(const T &rhs);
        matrix<T>& operator-=(const matrix<T> &rhs);
        matrix<T>& operator*=(const T &rhs);
        matrix<T>& operator*=(const matrix<T> &rhs);
        matrix<T>& operator/=(const T &rhs);
        //matrix<T>& operator/=(const matrix<T>  &rhs);




        // A + cte
        friend matrix<T> operator+(matrix<T> lhs, const T &rhs) { return lhs += rhs; }
        // cte + A
        friend matrix<T> operator+(const T &lhs, matrix<T> rhs) { return rhs += lhs; }
        // A + B
        friend matrix<T> operator+(matrix<T> lhs, const matrix<T> &rhs) { return lhs += rhs; }
        // A - cte
        friend matrix<T> operator-(matrix<T> lhs, const T &rhs) { return lhs -= rhs; }
        // cte - A
        friend matrix<T> operator-(const T &lhs, matrix<T> rhs) { return rhs -= lhs; }
        // A - B
        friend matrix<T> operator-(matrix<T> lhs, const matrix<T> &rhs) { return lhs -= rhs; }
        // A * cte
        friend matrix<T> operator*(matrix<T> lhs, const T &rhs) { return lhs *= rhs; }
        // cte * A
        friend matrix<T> operator*(const T &lhs, matrix<T> rhs) { return rhs *= lhs; }
        // A * B
        friend matrix<T> operator*(matrix<T> lhs, const matrix<T> &rhs) { return lhs *= rhs; }


        friend std::ostream& operator<<(std::ostream& stream, const matrix<T>& m)
        {
            for(int i=0; i < m.get_num_rows(); ++i)
            {
                for (int j=0; j < m.get_num_cols(); ++j) {
                    stream << std::setw(4) << m(i, j);
                }
                stream << std::endl;
            }
            return stream;
        }

    private:
        T *_matrix;

        unsigned _rows;
        unsigned _cols;

        void create(const unsigned &rows, const unsigned &cols);
        void destroy();
    };

}

#include "matrix.hpp"

#endif //CODELIB_MATRIX_H
