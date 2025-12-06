/**
 * @file valid_palindrome.h
 * @author Travis-LEE 
 * @brief Valid Palindrome Header File
 * What does a valid palindrome algorithm do?
 * The algorithm checks if a given string is a palindrome after doing two cleaning steps:
 * 1.converting all uppercase letters to lowercase.
 * 2.removing all non-alphanumeric characters (like spaces, punctuation, etc.).
 * After cleaning, the algorithm checks:
 * Does the cleaned string read the same forwards and backwards?    
 * If yes -> return true; else -> return false;
 * 
 * Input:
 * "A man, a plan, a canal: Panama"
 * Output:
 * amanaplanacanalpanama
 * Forward=Backward -> true
 *
 * Input:
 * "race a car"
 * Output:
 * raceacar
 * Forward!=Backward -> false
 *
 * Input:
 * " "
 * Output:
 * " " (empty string after cleaning)
 * An empty string is considered a valid palindrome -> true
 **/

#pragma once
#include <string>   
#include <cctype>    // for std::isalnum and std::tolower

template<typename T>
class ValidPalindrome {
public:
    //consturctor function
    ValidPalindrome(const T& input);
    bool isPalindrome() const;

private:
    T data;

    // Helper function: check if a character is alphanumeric
    bool isAlphanumeric(char c) const ;
};