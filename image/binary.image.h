#ifndef CODELIB_BINARY_IMAGE_H
#define CODELIB_BINARY_IMAGE_H

#include <cstdint>   // bool
#include "image.h"


namespace codelib {

    class binary_image : public image<bool> {
    public:
        //constructor
        binary_image(): image<bool>() { }
        binary_image(const unsigned &width, const unsigned &height) : image<bool>(width, height) { }

        //copy & move constructor
        binary_image(const binary_image &other) : image<bool>(other) { }
        //image(const binary_image &&other) = delete;

        //copy & move assignment operator
        binary_image& operator=(const binary_image &other) {
            image<bool>::operator=(other);
            return *this;
        }
        //binary_image& operator=(const binary_image &&other) = delete;

        //destructor
        virtual ~binary_image(){}


    };

}

#endif //CODELIB_BINARY_IMAGE_H
