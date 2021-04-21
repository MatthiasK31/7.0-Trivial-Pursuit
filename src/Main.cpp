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
    string line, letters = "abcd", name, answerCluster = "", continueOrNo;
    int questionCount = 0, duplicateTimes = 0;
    string answerChoice;
    bool yesOrNo = true;
    bool stillRunning = true;

    //vectors
    vector<string> questions;
    vector<string> answers;
    vector<char> letter;
    vector<string> playerNames;
    vector<int> outOfFive;
    vector<double> scoring;

    //add letter variables to vector for easy printing of answer choices
    for (int i = 0; i < 4; i++) {
        letter.push_back(letters.at(i));
    }


    fout.open("userAnswers.txt");

    //run this loop while the boolean controlling whether the users want to continue or not
    do {
        continueOrNo = "";
        name = "";

        //open file
        fin.open("Questions.txt");

        //ask user(s) his/her name and then append to the end of name vector
        cout << "\nWhat is your name? ";
        cin >> name;

        /*
        cin.ignore(INT_MAX, '\n');
        cin.clear();
        getline(cin, name);
        */
        for (int i = 0; i < playerNames.size(); i++) {
            if (name == playerNames.at(i)) {
                ++duplicateTimes;
                name = name + "_" + to_string(duplicateTimes);
            }
        }
        playerNames.push_back(name);
        cout << endl;

        //running loop while the end of the file is not reached
        while (!fin.eof()) {
            getline(fin, line);
            cout << "Question " << questionCount + 1 << ": " << line << endl;
            for (int i = 0; i < 4; i++) {
                fin.clear();
                getline(fin, line);
                cout << "\t" << letter.at(i) << ": " << line << endl;
            }

            cout << "Please enter your choice (a, b, c, d):\t";
            cin >> answerChoice;
            while (true) {
                if (answerChoice.length() > 1) {
                    cout << "Please enter a single character answer:\t" << endl;
                    cin >> answerChoice;
                }
                else {
                    break;
                }
            }
            answerChoice = tolower(answerChoice.at(0));
            //switch-case statement to check that the input satisfies the conditions of being a letter from a to d
            switch (answerChoice.at(0)) {
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
                    answerChoice = tolower(answerChoice.at(0));
                    yesOrNo = checkValidLetterInput(answerChoice.at(0));
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
        
        //prompt user and ask if there is someone else who is going to play
        string e;
        cout << "Is there another person that wants to play? Enter a Y if so and any other letter to break. ";
        cin >> continueOrNo;
        for (int i = 0; i < continueOrNo.length(); i++) {
            e += tolower(continueOrNo.at(i));
        }
        continueOrNo = e;
        questionCount = 0;
        answerCluster = "";
        fin.close();
        //will break the loop if the user enters anything other than a derivative of "y" or "yes"
    } while (continueOrNo.at(0) == 'y' || continueOrNo == "yes");
    //continueOrNo is a string


    //nested for loop
    int numberCorrect = 0;
    char temporary;
    double tempScore = 0;
    //first one loops through every player and prints the name at the for loops position
    for (int i = 0; i < playerNames.size(); i++) {
        fin.open("Answers.txt");
        fout << playerNames.at(i) << endl;
        //sets the temporary string to be the string of clustered answers at the designated person's name position
        string temp = answers.at(i);
        //loops through that cluster and prints out each individual character on a separate line
        for (int j = 0; j < 5; j++) {
            fout << temp.at(j) << endl;
            fin >> temporary;
            if (temporary == temp.at(j)) {
                ++numberCorrect;
            }
        }

        //print the user's score into the file
        fout << "Score: " << numberCorrect << "/5" << endl;
        tempScore = double(numberCorrect) / double(5) * 100;
        scoring.push_back(tempScore);

        //creates a clean line of space to distinguish between each person's answers        
        numberCorrect = 0;
        fin.close();
        fout << endl;
    }

    //close output stream
    fout.close();

    //print a formatted chart displaying each user's name and score on a separate line
    printf("\n%-s\t\t%-s\n", "Name:", "Score");
    for (int i = 0; i < playerNames.size(); i++) {
        printf("%-s\t\t%-.0f%s\n", playerNames.at(i).c_str(), scoring.at(i), "%");
    }

    return 0;
}