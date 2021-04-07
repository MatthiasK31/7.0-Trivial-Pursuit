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
    string line, letters = "abcd";
    int questionCount = 1;
    char answerChoice;
    bool yesOrNo = true;

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
        cout << "Question " << questionCount << ": " << line << endl;
        for (int i = 0; i < 4; i++) {
            getline(fin, line);
            answers.push_back(line);
            cout << "\t" << letter.at(i) << ": " << line << endl;
        }

        cout << "Please enter your choice (a, b, c, d): ";
        cin >> answerChoice;
        while (yesOrNo) {
            cout << "\tEnter a valid answer choice:\t";
            cin >> answerChoice;
            yesOrNo = checkValidLetterInput(answerChoice);
            if (yesOrNo == false) {
                break;
            }
        }
        yesOrNo = true;
        cout << endl;
    }
    
    fout << answerChoice << endl;

    fout.close();
    fin.close();
    return 0;
}
