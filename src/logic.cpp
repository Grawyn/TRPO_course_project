#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "logic.hpp"

using namespace std;

void words::choise(string *word)
{
    srand((unsigned)time(NULL));
    int n = 6; // Количество слов в файле
    int random = rand() % n + 1;
    ifstream file("themes/professions.txt");
    for(int i = 0; i < random; i++){
        getline(file,*word);
    }
}
