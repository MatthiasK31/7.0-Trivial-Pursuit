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
    string line, letters = "abcd", name, answerCluster = "", continueOrNo = "";
    int questionCount = 0;
    char answerChoice;
    bool yesOrNo = true;
    bool stillRunning = true;

    //vectors
    vector<string> questions;
    vector<string> answers;
    vector<char> letter;
    vector<string> playerNames;
    vector<int> outOfFive;

    for (int i = 0; i < 4; i++) {
        letter.push_back(letters.at(i));
    }


    fout.open("userAnswers.txt");

    //run this loop while the boolean controlling whether the users want to continue or not
    do {
        continueOrNo = "";
        //open file
        fin.open("Questions.txt");

        //ask user(s) his/her name and then append to the end of name vector
        cout << "What is your name? ";
        cin >> name;
        
        /*
        cin.ignore(INT_MAX, '\n');
        cin.clear(); 
        getline(cin, name);
        */
        for (int i = 0; i < playerNames.size(); i++) {
            if (name == playerNames.at(i)) {
                name = name + "_" + to_string(i+1);
            }
        }
        playerNames.push_back(name);
        cout << endl;

        //running loop while the end of the file is not reached
        while (!fin.eof()) {
            //
            getline(fin, line);
            cout << "Question " << questionCount + 1 << ": " << line << endl;
            for (int i = 0; i < 4; i++) {
                fin.clear();
                getline(fin, line);
                cout << "\t" << letter.at(i) << ": " << line << endl;
            }

            cout << "Please enter your choice (a, b, c, d):\t";
            cin >> answerChoice;
            answerChoice = tolower(answerChoice);
            //switch-case statement to check that the input satisfies the conditions of being a letter from a to d
            switch (answerChoice) {
                case 'a':
                    break;
                case 'b':
                    break;
                case 'c':
                    break;
                case 'd':
                    break;
                default: {
                    while (yesOrNo) {
                        cout << "\tEnter a valid answer choice:\t";
                        cin >> answerChoice;
                        answerChoice = tolower(answerChoice);
                        yesOrNo = checkValidLetterInput(answerChoice);
                        if (yesOrNo == false) {
                            break;
                        }
                    }
                }
            }
            answerCluster += answerChoice;
            
            yesOrNo = true;
            questionCount++;
            cout << endl;
        }
        answers.push_back(answerCluster);

        string e;   
        cout << "Is there another person that wants to play? Enter a Y if so and any other letter to break. ";
        cin >> continueOrNo;
        for (int i = 0; i < continueOrNo.length(); i++) {
            e += tolower(continueOrNo.at(i));
        }
        continueOrNo = e;
        fin.close();
    } while (continueOrNo.at(0) == 'y' || continueOrNo == "yes");
    //continueOrNo is a string
    

    //nested for loop
    int numberCorrect = 0;
    string temporary;
    //first one loops through every player and prints the name at the for loops position
    fin.open("Answers.txt");
    for (int i = 0; i < playerNames.size(); i++) {
        fout << playerNames.at(i) << endl;
        //sets the temporary string to be the string of clustered answers at the designated person's name position
        string temp = answers.at(i);
        //loops through that cluster and prints out each individual character on a separate line
        for (int j = 0; j < 5; j++) {
            fout << temp.at(j) << endl;
            fin >> temporary;
            if (temporary.at(0) == temp.at(j)) {
                numberCorrect++;
            }
        }
        //creates a clean line of space to distinguish between each person's answers
        fout << endl;
    }
    cout << numberCorrect << "/5";
    
    //close output stream
    fout.close();
    return 0;
}
