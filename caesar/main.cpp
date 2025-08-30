#include <iostream>
#include <string>

#include "shisa_decrypt.hpp"

int main() {
    std::string file_name = "target.txt";
    std::cout<< "start\n";
    ShisaDecrypt shisa_decrypt;
    shisa_decrypt.decrypt(file_name);
    std::cout<< "finish\n";
    return 1;
}
