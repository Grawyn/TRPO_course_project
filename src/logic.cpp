#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "logic.hpp"

using namespace std;

void logic::choise(string *word)
{
    srand((unsigned)time(NULL));
    int n = 6; // Количество слов в файле
    int random = rand() % n + 1;
    ifstream file("themes/professions.txt");
    for(int i = 0; i < random; i++){
        getline(file,*word);
    }
}

void logic::menu_head()
{
    cout << "Welcome to Hangman." << endl;
    cout << "Choose a menu item:" << endl;
    cout << "1. Play" << endl;
    cout << "2. Exit" << endl; 
}

void logic::main_function(string word)
{
    menu_head();
    int choose;
    char letter;
    cin >> choose;
    switch(choose)
    {
        case 1:
        {
            cout << "Let's play! Try to guess the word!" << endl;
            string prompt(word.size(),'-');
            int lives = 6; // Максимальное количество попыток
            cout << prompt << endl;
            while(lives > 0 && prompt != word)
            {
                cout << "Enter the letter" << endl;
                cin >> letter;
                letter = toupper(letter); //Перевод буквы в верхний регистр
                int position = word.find(letter);
                if(word.find(letter) != string::npos){
                    cout << "You are right!" << endl;
                    cout << word[position];
                    for(unsigned int i = 0; i < word.size(); i++){
                        if(word[i] == letter){
                            prompt[i] = word[position];
                        }
                    }
                } else {
                    lives--;
                    cout << "Didn't guess! You have " << lives << "lives" << endl; 
                }
                cout << prompt << endl;
            }
        }
        case 2:
            exit(0);
    }
}