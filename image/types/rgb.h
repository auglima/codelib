#ifndef CODELIB_RGB_H
#define CODELIB_RGB_H

#include <cstdint>   // uint8_t
#include <assert.h>  // assert
#include <iostream>  // ostream
#include <iomanip>   // setw


namespace codelib {
    
    class rgb {
    public:
        //constructor
        rgb();
        rgb(const uint8_t &red, const uint8_t &green, const uint8_t &blue);
        //rgb(const uint8_t &red, const uint8_t &green, const uint8_t &blue, const uint8_t &alpha);

        //copy & move constructor
        rgb(const rgb &other);
        //rgb(const rgb &&other) = delete;

        //copy & move assignment operator
        rgb& operator=(const rgb &other);
        //rgb& operator=(const rgb &&other) = delete;

        //destructor
        virtual ~rgb();

        //getter & setter
        const uint8_t& get_red() const;
        const uint8_t& get_green() const;
        const uint8_t& get_blue() const;
        //const uint8_t& get_alpha() const;
        void set_red(const uint8_t &red);
        void set_green(const uint8_t &green);
        void set_blue(const uint8_t &blue);
        //void set_alpha(const uint8_t &alpha);
        void set_rgb(const uint8_t &red, const uint8_t &green, const uint8_t &blue);
        //void set_rgb(const uint8_t &red, const uint8_t &green, const uint8_t &blue, const uint8_t &alpha);

        //rgb operations
        rgb& operator+=(const uint8_t &rhs);
        rgb& operator+=(const rgb &rhs);
        rgb& operator-=(const uint8_t &rhs);
        rgb& operator-=(const rgb &rhs);
        rgb& operator*=(const uint8_t &rhs);
        rgb& operator*=(const rgb &rhs);
        rgb& operator/=(const uint8_t &rhs);
        rgb& operator/=(const rgb &rhs);

        // A + cte
        friend rgb operator+(rgb lhs, const uint8_t &rhs) { return lhs += rhs; }
        // cte + A
        friend rgb operator+(const uint8_t &lhs, rgb rhs) { return rhs += lhs; }
        // A + B
        friend rgb operator+(rgb lhs, const rgb &rhs) { return lhs += rhs; }
        // A - cte
        friend rgb operator-(rgb lhs, const uint8_t &rhs) { return lhs -= rhs; }
        // cte - A
        friend rgb operator-(const uint8_t &lhs, rgb rhs) { return rhs -= lhs; }
        // A - B
        friend rgb operator-(rgb lhs, const rgb &rhs) { return lhs -= rhs; }
        // A * cte
        friend rgb operator*(rgb lhs, const uint8_t &rhs) { return lhs *= rhs; }
        // cte * A
        friend rgb operator*(const uint8_t &lhs, rgb rhs) { return rhs *= lhs; }
        // A * B
        friend rgb operator*(rgb lhs, const rgb &rhs) { return lhs *= rhs; }
        // A / cte
        friend rgb operator/(rgb lhs, const uint8_t &rhs) { return lhs /= rhs; }
        // cte / A
        friend rgb operator/(const uint8_t &lhs, rgb rhs) { return rhs /= lhs; }
        // A / B
        friend rgb operator/(rgb lhs, const rgb &rhs) { return lhs /= rhs; }

        // print matrix
        friend std::ostream& operator<<(std::ostream& stream, const rgb& m)
        {
                stream << " r: " << std::setw(2) << (unsigned)m._red;
                stream << " g: " << std::setw(2) << (unsigned)m._green;
                stream << " b: " << std::setw(2) << (unsigned)m._blue;
                //stream << " b: " << std::setw(2) << (unsigned)m._alpha;
                return stream;
        }

    private:
        uint8_t _red;
        uint8_t _green;
        uint8_t _blue;
        //uint8_t _alpha;
    };

#include "rgb.hpp"

}

#endif //CODELIB_RGB_H
