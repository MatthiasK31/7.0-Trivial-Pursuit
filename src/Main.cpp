// 7.0 Trivial Pursuit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "Header.h"

using namespace std;

int main()
{
    //input and output streams
    ifstream fin;
    ofstream fout;

    //variables
    string line;
    char answerChoice;
    string letters = "abcd";
    bool yesOrNo;

    //vectors
    vector<string> questions;
    vector<string> answers;
    vector<char> letter;

    for (int i = 0; i < 4; i++) {
        letter.push_back(letters.at(i));
    }


    fout.open("userAnswers.txt");
    fin.open("Questions.txt");

    

    while (!fin.eof()) {
        getline(fin, line);
        questions.push_back(line);
        //cout << line << endl;
        for (int i = 0; i < 4; i++) {
            getline(fin, line);
            answers.push_back(line);
            //cout << line << endl;
        }

        cout << "Please enter your choice (a, b, c, d): ";
        cin >> answerChoice;
        while (yesOrNo) {
            cout << "\tEnter a valid course number:\t";
            cin >> answerChoice;
            yesOrNo = checkValidNumInput(answerChoice);
        }
        cout << endl;
    }
    
    fout << answerChoice << endl;

    fout.close();
    fin.close();
    return 0;
}
