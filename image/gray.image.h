#ifndef CODELIB_GRAY_IMAGE_H
#define CODELIB_GRAY_IMAGE_H

#include <cstdint>   // uint8_t
#include <cmath>
#include "image.h"
#include "binary.image.h"

namespace codelib {

    class gray_image : public image<uint8_t> {
    public:
        //constructor
        gray_image() : image<uint8_t>() { }
        gray_image(const unsigned &width, const unsigned &height) : image<uint8_t>(width, height) { }

        //copy & move constructor
        gray_image(const gray_image &other) : image<uint8_t>(other) { }
        //image(const gray_image &&other) = delete;

        //copy & move assignment operator
        gray_image& operator=(const gray_image &other) {
            image<uint8_t>::operator=(other);
            return *this;
        }
        //gray_image& operator=(const gray_image &&other) = delete;

        //destructor
        virtual ~gray_image(){}

        /**
         * @see https://en.wikipedia.org/wiki/Otsu%27s_method
         * @see https://www.ipol.im/pub/art/2016/158/article_lr.pdf
         * @param threshold
         * @return
         */
        binary_image to_binary(unsigned threshold = 0) {
            binary_image binary = binary_image(get_width(), get_height());

            unsigned histogram[255];
            unsigned max, sum, sumb, q1, q2, u1, u2 = 0;
            unsigned max_intensity = 255;

            // iniciando histograma
            for(unsigned i = 0; i < get_width(); ++i) {
                for (unsigned j = 0; j < get_height(); ++j) {
                    histogram[(*this)(i,j)] += 1;
                }
            }

            if (threshold == 0) {

                for (unsigned i = 0; i < max_intensity; ++i) {
                    sum += i * histogram[i];
                }

                for (unsigned i = 0; i <= max_intensity; ++i) {
                    q1 += histogram[i];

                    if (q1 == 0)
                        continue;

                    q2 = (get_width() * get_height()) - q1;


                    sumb += i * histogram[i];

                    u1 = sumb / q1;
                    u2 = (sum - sumb) / q2;

                    unsigned const variance = q1 * q2 * pow((u1 - u2), 2);

                    if (variance > max) {
                        threshold = i;
                        max = variance;
                    }
                }

            }

            // criando imagem binária
            for(unsigned i = 0; i < get_width(); ++i) {
                for (unsigned j = 0; j < get_height(); ++j) {
                    if ((*this)(i,j) > threshold)
                        binary(i,j) = 1;
                    else
                        binary(i,j) = 0;
                }
            }

            return binary;

        }


    };

}

#endif //CODELIB_GRAY_IMAGE_H
