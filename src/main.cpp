#include <iostream>
#include <string>
#include <vector>
#include "logic.hpp"

using namespace std;

int main(){
    string the_word;
    words choise_the_word;
    choise_the_word.choise(&the_word);
    cout << the_word;
    return 0;
}