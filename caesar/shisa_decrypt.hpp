#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#ifndef SHISA_DECRYPT_HPP
#define SHISA_DECRYPT_HPP

class ShisaDecrypt {
public:
    ShisaDecrypt() {
	char al = 'a';
	for( int i = 0; i < alphabet_length; i++ ) {
	    small_alphabet += al;
	    al += 1;
	}

	big_conversion_alphabet(small_alphabet, big_alphabet);
    }

    void decrypt(std::string file_name);
private:
    int alphabet_length = 26;
    std::string small_alphabet;
    std::string big_alphabet;
    std::vector<std::string> dict_word_list = {"is", "are"};

    void big_conversion_alphabet(std::string small, std::string big);
    void small_conversion_alphabet(std::string big, std::string small);
    bool check_word(std::string word);
    int check_point(char w);
    std::string move_word(std::string word, int move_point);
};

#endif
