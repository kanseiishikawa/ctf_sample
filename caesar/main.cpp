#include <iostream>
#include <string>

#include "caesar_decrypt.hpp"

int main() {
    std::string file_name = "target.txt";
    std::cout<< "start\n";
    CaesarDecrypt caesar_decrypt;
    caesar_decrypt.decrypt(file_name);
    std::cout<< "finish\n";
    return 1;
}
