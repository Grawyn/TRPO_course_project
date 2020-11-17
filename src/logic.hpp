#pragma once
#include <iostream>
#include <string>

using namespace std;

class logic{
public:
    void choise(string *word);
    void menu_head();
    bool check(string prompt, string word, int lives);
    void main_function(string word);
};