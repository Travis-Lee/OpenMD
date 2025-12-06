#include "valid_palindrome.h"

template<typename T>
ValidPalindrome<T>::ValidPalindrome(const T& input) : data(input) {}


template<typename T>
bool ValidPalindrome<T>::isAlphanumeric(char c) const {
    return std::isalnum(static_cast<unsigned char>(c));
}

template<typename T>
bool ValidPalindrome<T>::isPalindrome() const {

    int left = 0;
    int right = data.size() - 1;

    while (left < right) {
        //jump non-alphanumeric characters
        while (left < right && !isAlphanumeric(data[left])) {
            left++;
        }
        while (left < right && !isAlphanumeric(data[right])) {
            right--;
        }

        // Compare characters in a case-insensitive manner
        if (std::tolower(static_cast<unsigned char>(data[left])) != 
            std::tolower(static_cast<unsigned char>(data[right]))) {
            return false; // Mismatch found
        }

        left++;
        right--;
    }

    return true; // No mismatches found, it's a palindrome
}



template class ValidPalindrome<std::string>;
