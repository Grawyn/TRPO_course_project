#include "logic.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string the_word;
    logic logic;
    logic.choise(&the_word);
    logic.main_function(the_word);
    return 0;
}