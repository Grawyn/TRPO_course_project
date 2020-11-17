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

void menu_head()
{
    cout << "Welcome to Hangman." << endl;
    cout << "Choose a menu item:" << endl;
    cout << "1. Play" << endl;
    cout << "2. Exit" << endl; 
}

void main_function(string word)
{
    menu_head();
    int choose;
    cin >> choose;
    switch(choose)
    {
        case 1:
        {
            cout << "Let's play! Try to guess the word!" << endl;
            string prompt(word.size(),'-');
            int lives = 6; // Максимальное количество попыток
            cout << prompt << endl;
        }
        case 2:
            exit(0);
    }
}