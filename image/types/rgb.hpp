#include "rgb.h"

codelib::rgb::rgb() : _red(0), _green(0), _blue(0)
{ }


codelib::rgb::rgb(const uint8_t &red, const uint8_t &green, const uint8_t &blue) :
    _red(red), _green(green), _blue(blue)
{ }


codelib::rgb::rgb(const rgb &other) : _red(other._red), _green(other._green), _blue(other._blue)
{ }


codelib::rgb& codelib::rgb::operator=(const rgb &other) {
    if (this != &other)
    {
        _red   = other._red;
        _green = other._green;
        _blue  = other._blue;
    }
    return *this;
}


codelib::rgb::~rgb()
{ }


const uint8_t& codelib::rgb::get_red() const {
    return _red;
}


const uint8_t& codelib::rgb::get_green() const {
    return _green;
}


const uint8_t& codelib::rgb::get_blue() const {
    return _blue;
}


void codelib::rgb::set_red(const uint8_t &red) {
    _red = red;
}


void codelib::rgb::set_green(const uint8_t &green) {
    _green = green;
}


void codelib::rgb::set_blue(const uint8_t &blue) {
    _blue = blue;
}


void codelib::rgb::set_rgb(const uint8_t &red, const uint8_t &green, const uint8_t &blue) {
    _red = red;
    _green = green;
    _blue = blue;
}


codelib::rgb& codelib::rgb::operator+=(const uint8_t &rhs) {
    _red   += rhs;
    _green += rhs;
    _blue  += rhs;
    return *this;
}


codelib::rgb& codelib::rgb::operator+=(const rgb &rhs) {
    _red   += rhs._red;
    _green += rhs._green;
    _blue  += rhs._blue;
    return *this;
}


codelib::rgb& codelib::rgb::operator-=(const uint8_t &rhs) {
    _red   -= rhs;
    _green -= rhs;
    _blue  -= rhs;
    return *this;
}


codelib::rgb& codelib::rgb::operator-=(const rgb &rhs) {
    _red   -= rhs._red;
    _green -= rhs._green;
    _blue  -= rhs._blue;
    return *this;
}


codelib::rgb& codelib::rgb::operator*=(const uint8_t &rhs) {
    _red   *= rhs;
    _green *= rhs;
    _blue  *= rhs;
    return *this;
}


codelib::rgb& codelib::rgb::operator*=(const rgb &rhs) {
    _red   *= rhs._red;
    _green *= rhs._green;
    _blue  *= rhs._blue;
    return *this;
}


codelib::rgb& codelib::rgb::operator/=(const uint8_t &rhs) {
    _red   /= rhs;
    _green /= rhs;
    _blue  /= rhs;
    return *this;;
}


codelib::rgb& codelib::rgb::operator/=(const rgb &rhs) {
    _red   /= rhs._red;
    _green /= rhs._green;
    _blue  /= rhs._blue;
    return *this;
}