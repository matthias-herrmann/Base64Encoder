//
// Created by mherrmann on 2/6/19.
//

#include <iostream>
#include "base64encoder.h"

const std::string Base64Encoder::encode(const std::string s) const {
    const size_t length_of_s = s.length();
    uint8_t cut_off_bits = 0;
    uint8_t next_cut_off_bits = 0;
    int number_of_cut_off_bits = 0;

    for(size_t i=0; i < length_of_s; ++i) {

        // Because an ASCII Character with 8 bits doesn't fit in a 6bit base64 encoding 2, 4 or 6 bits from the
                // original character are cut off dependent on the position of the character.
        if(number_of_cut_off_bits < 6) {
            number_of_cut_off_bits += 2;
        } else {
            number_of_cut_off_bits = 2;
        }

        char c = s.at(i);

        // We need the cut off bits of the last preceding character.
        if(number_of_cut_off_bits > 2) {
            next_cut_off_bits = c << number_of_cut_off_bits;
            // cutting off the bits we don't need to encode this character but for the next one
            c = c >> number_of_cut_off_bits;
            // Adding the cut off bits of the last character
            c = (cut_off_bits >> 2) | c;
            cut_off_bits = next_cut_off_bits;
        } else {
            cut_off_bits = c << 6;
            // The ASCII character contains all information we need. We don't need to know anything about the preceding
            // character.
            c = c >> 2;
        }
        std::cout << c;
    }
}
