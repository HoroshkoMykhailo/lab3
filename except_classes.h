#pragma once
#include <stdexcept>
#include <vector>
#include <exception>
using namespace std;

class lines_error: public exception{
    vector<string> messages;
public:
    void addMessage(string);
    const char* what() const throw() override;
    vector<string>& message();
    bool is_empty();
};