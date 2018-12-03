#ifndef CODELIB_IMAGE_H
#define CODELIB_IMAGE_H

#include "../math/matrix.h"
#include "filters/filter.h"

namespace codelib {

    template <typename T>
    class image {

    public:
        image();
        image(const unsigned &width, const unsigned &height);

        image(const image<T> &other);
        //image(const image<T> &&other);

        image<T>& operator=(const image<T> &other);
        //image<T>& operator=(const image<T> &&other);

        virtual ~image();

        //access the individual elements
        T& operator()(const unsigned &row, const unsigned &col);
        const T& operator()(const unsigned &row, const unsigned &col) const;

        const unsigned& get_width() const;
        const unsigned& get_height() const;

        //void set_filter(filter<T> *type);

        //void filtered();
        //const image<T>& filtered() const;

        /*void translate(const unsigned &x, const unsigned &y);
        const image<T>& translate(const unsigned &x, const unsigned &y) const;

        void rotate(const unsigned &angle);
        const image<T>& rotate(const unsigned &angle) const;

        void vertical_flip();
        const image<T>& vertical_flip() const;

        void horizontal_flip();
        const image<T>& horizontal_flip() const;*/

/*

        void set_filter(filter *type);

        image<T> filtered();
*/
        //image operations
        image<T>& operator+=(const T &rhs);
        image<T>& operator+=(const image<T> &rhs);
        image<T>& operator-=(const T &rhs);
        image<T>& operator-=(const image<T> &rhs);
        image<T>& operator*=(const T &rhs);
        image<T>& operator*=(const image<T> &rhs);
        image<T>& operator/=(const T &rhs);
        image<T>& operator/=(const image<T> &rhs);

        // A + cte
        friend image<T> operator+(image<T> lhs, const T &rhs) { return lhs += rhs; }
        // cte + A
        friend image<T> operator+(const T &lhs, image<T> rhs) { return rhs += lhs; }
        // A + B
        friend image<T> operator+(image<T> lhs, const image<T> &rhs) { return lhs += rhs; }
        // A - cte
        friend image<T> operator-(image<T> lhs, const T &rhs) { return lhs -= rhs; }
        // cte - A
        friend image<T> operator-(const T &lhs, image<T> rhs) { return rhs -= lhs; }
        // A - B
        friend image<T> operator-(image<T> lhs, const image<T> &rhs) { return lhs -= rhs; }
        // A * cte
        friend image<T> operator*(image<T> lhs, const T &rhs) { return lhs *= rhs; }
        // cte * A
        friend image<T> operator*(const T &lhs, image<T> rhs) { return rhs *= lhs; }
        // A * B
        friend image<T> operator*(image<T> lhs, const image<T> &rhs) { return lhs *= rhs; }
        // A / cte
        friend image<T> operator/(image<T> lhs, const T &rhs) { return lhs /= rhs; }
        // cte / A
        friend image<T> operator/(const T &lhs, image<T> rhs) { return rhs /= lhs; }
        // A / B
        friend image<T> operator/(image<T> lhs, const image<T> &rhs) { return lhs /= rhs; }


    private:
        //filter<T> *_filter;
        matrix<T> _data;

    };

}

#include "image.hpp"

#endif //CODELIB_IMAGE_H
