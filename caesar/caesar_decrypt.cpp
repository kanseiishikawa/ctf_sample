#include "caesar_decrypt.hpp"
#include <cctype>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

void CaesarDecrypt::big_conversion_alphabet(std::string small, std::string big) {
    std::transform( small.begin(), small.end(), big.begin(), [](char c){ return std::toupper( c ); } );
}

void CaesarDecrypt::small_conversion_alphabet(std::string big, std::string small) {
    std::transform( big.begin(), big.end(), small.begin(), [](char c){ return std::tolower( c ); } );
}

std::string CaesarDecrypt::move_word(std::string word, int move_point) {
    std::string result_word;
    
    for(char w: word) {
	int point;
	bool big = false;
	
	if(std::isupper( w )) {
	    big = true;
	    point = big_alphabet.find(w);
	} else {
	    point = small_alphabet.find(w);
	}

	char change_w;
	
	if(point < 0) {
	    change_w = w;
	} else {
	    point = (point + move_point) % alphabet_length;
	    
	    if(big) {
		change_w = big_alphabet[point];
	    } else {
		change_w = small_alphabet[point];
	    }
	}

	result_word += change_w;
    }

    return result_word;
}

bool CaesarDecrypt::check_word(std::string word) {
    bool result = false;
    
    for(std::string dict_word: dict_word_list) {
	if(word == dict_word) {
	    result = true;
	    break;
	}
    }

    return result;
}

void CaesarDecrypt::decrypt(std::string file_name) {
    std::ifstream f(file_name);
    std::string word;
    std::vector<std::string> word_list;
    std::vector<int> correct_index_list;

    while (std::getline(f, word, ' ')) {
	word_list.push_back( word );
    }

    std::string mw;
    f.close();

    for(int i = 0; i < alphabet_length; i++) {
	for(std::string word: word_list) {
	    mw = move_word(word, i);

	    if(check_word(mw)) {
		correct_index_list.push_back(i);
		break;
	    }
	}
    }

    for(int i: correct_index_list) {
	std::cout<< "move_point:" << i << "\n";
	for(std::string word: word_list) {
	    std::cout<< move_word(word, i) << " ";
	}
	std::cout<<"\n";
    }
}
