#include "valid_parentheses.h"

template<typename T>
bool ValidParentheses<T>::isValid(const std::basic_string<T>& s) {
    if (s.length() % 2 != 0) {
        return false; // Odd length strings cannot be valid
    }

    //Define the matching rules:Right bracket -> Require left bracket 
    std::map<T, T> matching_brackets = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    //Stack: Stores all open brackets waiting to be closed(LIFO principle)
    std::stack<T> waiting_left_brackets;

    for(T curr_char : s){
        if(matching_brackets.count(curr_char)){
            if(waiting_left_brackets.empty())
                return false; //No matching left bracket found
            
            T top_left_bracket = waiting_left_brackets.top();
            waiting_left_brackets.pop();

            if(top_left_bracket != matching_brackets[curr_char]){
                return false; //Mismatched brackets
            }
        }else{
            // Process left brackets: push onto the stack
            waiting_left_brackets.push(curr_char);
        }
    }

    // Final check: the stack must be empty.
    return waiting_left_brackets.empty();
}   

template class ValidParentheses<char>;
