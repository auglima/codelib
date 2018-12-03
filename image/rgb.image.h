#ifndef CODELIB_RGB_IMAGE_H
#define CODELIB_RGB_IMAGE_H

#include <cmath>
#include "image.h"
#include "types/rgb.h"
#include "gray.image.h"

namespace codelib {

    class rgb_image : public image<rgb> {
    public:
        //constructor
        rgb_image() : image<rgb>() { }
        //rgb_image(const matrix<rgb> &data) { image(&data); }
        rgb_image(const unsigned &width, const unsigned &height) : image<rgb>(width, height) { }

        //copy & move constructor
        rgb_image(const rgb_image &other) : image<rgb>(other) { }
        //image(const rgb_image &&other) = delete;

        //copy & move assignment operator
        rgb_image& operator=(const rgb_image &other) {
            image<rgb>::operator=(other);
            return *this;
        }
        //rgb_image& operator=(const rgb_image &&other) = delete;

        //destructor
        virtual ~rgb_image() { }

        /**
         * @see https://en.wikipedia.org/wiki/Grayscale
         * @return
         */
        gray_image to_gray() {
            gray_image gray(get_width(), get_height());

            for (unsigned i = 0; i < get_width(); ++i) {
                for (unsigned j = 0; j < get_height(); ++j) {
                    double const r = srgbtolinear((*this)(i,j).get_red()   / 255.0);
                    double const g = srgbtolinear((*this)(i,j).get_green() / 255.0);
                    double const b = srgbtolinear((*this)(i,j).get_blue()  / 255.0);

                    double const c_linear = 0.2126 * r + 0.7152 * g + 0.0722 * b;

                    if (c_linear <= 0.0031308) {
                        gray(i,j) = round((12.92 * c_linear) * 255);
                    } else {
                        gray(i,j) = round((1.055 * pow(c_linear, 1/2.4) - 0.055) * 255);
                    }
                }
            }

            return gray;
        }
    private:
        double srgbtolinear(const double &x) {
            if (x < 0.04045) {
                return x/12.92;
            }
            return pow((x+0.055)/1.055, 2.4);
        }

    };

}

#endif //CODELIB_RGB_IMAGE_H
