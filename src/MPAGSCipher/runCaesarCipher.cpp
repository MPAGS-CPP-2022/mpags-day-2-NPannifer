#include<iostream>
#include<string>
#include<vector>
#include <algorithm>

#include "runCaesarCipher.hpp"

std::string runCaesarCipher(std::string input_, const int shift_){
    std::string alphabet{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    std::string output_{""};
    std::vector<int> letterNumbers;
    std::vector<int> shiftedLetterNumbers;

    for (char& c : input_){
        letterNumbers.push_back(alphabet.find(c));
    }

    for (int i : letterNumbers){
        if(shift_ > 0){
            shiftedLetterNumbers.push_back((i+shift_)%26);
        }else if(shift_ < 0){
            shiftedLetterNumbers.push_back(25-(25-(i+shift_))%26);
        }else{
            shiftedLetterNumbers.push_back(i);
        }

    }

    for (int j : shiftedLetterNumbers){
        output_ += alphabet[j];
    }

    return output_;
    
}
