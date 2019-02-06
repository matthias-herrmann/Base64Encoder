#include <iostream>
#include "base64encoder.h"

int main() {
    Base64Encoder b;
    const std::string s("Man is distinguished");
    b.encode(s);
}