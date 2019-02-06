//
// Created by mherrmann on 2/6/19.
//

#ifndef BASE64_BASE64_H
#define BASE64_BASE64_H

#include <array>

class Base64Encoder {
public:
    Base64Encoder() = default;
    const std::string encode(const std::string s) const;
private:
    constexpr static std::array<const char, 64> base64_table = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                                                                'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                                                                'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                                                                'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                                                                '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'};
    constexpr static char get_base_64_char(ulong number_of_char) {
        return base64_table.at(number_of_char);
    }
};


#endif //BASE64_BASE64_H
