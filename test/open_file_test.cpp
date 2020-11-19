#define CATCH_CONFIG_MAIN
#include "logic.hpp"
#include <catch.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

TEST_CASE("Instuction test", "instruction")
{
    GIVEN("file")
    {
        string temp;
        string word;
        vector<string> words;
        ifstream test_file("themes/professions.txt");
        while (!test_file.eof()) {
            getline(test_file, temp);
            words.push_back(temp);
        }
        WHEN("file function")
        {
            logic logic;
            logic.choise(&word);
            for (long unsigned int i = 0; i < words.size(); i++) {
                if (word == words[i]) {
                    temp = words[i];
                    break;
                }
            }
            THEN("Changed word")
            {
                REQUIRE(word == temp);
            }
        }
    }
}