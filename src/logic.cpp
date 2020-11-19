#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "logic.hpp"

using namespace std;

void logic::choise(string *word)
{
    srand((unsigned)time(NULL));
    int n = 18; // Количество слов в файле
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

bool logic::check(string prompt, string word, int lives)
{
    int answer;
    if(prompt == word){
        cout << "Congratulations! You won!\nDo you want to exit to menu?" << endl;
    } else if(lives <= 0){
        cout << "You lose!\nDo you want to exit to menu?" << endl;
    }
    cout << "1. Yes.\n2. No." << endl;
    cin >> answer;
    switch(answer){
        case 1:
        {
            return true;
            break;
        }
        case 2:
        {
            return false;
            break;
        }
        default:
        {
            cout << "Warning! Choose 1 or 2!" << endl;
            return false;
            check(prompt, word, lives);
            break;
        }
    }
}

void match_letter(string& word, char& letter, string& prompt, int& position, int& lives)
{
    if(word.find(letter) != string::npos){
        cout << "You are right!" << endl;
        cout << word[position] << endl;
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
                match_letter(word, letter, prompt, position, lives);
            }
            if(check(prompt, word, lives)){
                choise(&word);
                main_function(word);
            } else {
                 cout << "Goodbye!" << endl;
                 exit(0);
            }
        break;
        }
        case 2:
        {
            exit(0);
            break;
        }
        default:
        {
            cout << "Warning! Choose 1 or 2!" << endl;
            main_function(word);
        }
    }
}