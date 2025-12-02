/**
 *************************************************************************************
 *
 *  The goal is to determine if a string made up of left brackets ((, [, {) and right brackets (), ], }) is valid.
 *  
 *  Example 1:
 *  Input: s = "()"
 *  Output: true
 *  
 *  Example 2:
 *  Input: s = "()[]{}"
 *  Output: true
 * 
 *  Example 3:
 *  Input: s = "(]"
 *  Output: false
 *   
 *  Example 4:
 *  Input: s = "([])"
 *  Output: true
 *  
 *  Example 5:
 *  Input: s = "([)]"
 *  Output: false
 *
 *************************************************************************************
 */
#pragma once
#include <string>
#include <stack>    
#include <map>
#include <iostream>

//Template class for check the validity of a Parentheses string
template<typename T>
class ValidParentheses {
public:
    //Check if the input string contains valid parentheses sequence of  brackets
    bool isValid(const std::basic_string<T>& s);
};
