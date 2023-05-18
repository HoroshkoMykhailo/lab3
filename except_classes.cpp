#include "except_classes.h"
void lines_error:: addMessage(string s){
    messages.push_back(s);
}
const char* lines_error:: what() const throw(){
    return "Lines error: ";
}
vector<string>& lines_error::  message(){
    return messages;
}
bool lines_error:: is_empty(){
    return messages.empty();
}