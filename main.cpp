#include <iostream>
#include <fstream>
#include "alarmFuncs.h"
#include "alarm.h"
#include<time.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <vector>
#include <thread>
using namespace std;


bool continuePrint = false;
bool exitSt = false;
vector<Alarm> curAlarms;
vector<qa> quesAns;

void askInp() { //process inp
  string inp = "";
  cout << "-1 to quit, ! for commands, 1 to proceed: ";
  cin >> inp;
  while(inp.compare("1") != 0) {
    if(inp.compare("-1") == 0) {
      exitSt = true;
      return;
    } else if(inp.compare("!") == 0) {
      printFunctions();
    }
    cout << endl << "-1 to quit, ! for commands, 1 to proceed: ";
    cin >> inp;
  }
  continuePrint = true;
  cin >> inp;
  while(inp.compare("-1") != 0) { //process commands
    if(inp.compare("!") == 0) { //inputting command
      continuePrint = false;
      printFunctions();
      cin >> inp;
      if(inp.compare("showq") == 0) {
        displayQuestions();
        sleep(4);
      } else if(inp.compare("addq") == 0) {
        cout << "write your question!" << endl;
        cout << "question: ";
        string question, answer;
        cin >> question;
        cout << endl << "answer: ";
        cin >> answer;
        cout << endl << endl;
        writeQuestion(question, answer);
        qa temp;
        temp.q = question;
        temp.a = answer;
        quesAns.push_back(temp);
      } else if(inp.compare("delq") == 0) {
        displayQuestions();
        cout << endl << endl << "type the # of the question to delete: ";
        int dLine;
        cin >> dLine;
        delQuestion(dLine);
      } else if(inp.compare("showa") == 0) {
        displayAlarms();
        sleep(4);
      } else if(inp.compare("adda") == 0) {
        cout << "input your new alarm!" << endl;
        string time;
        int dayArray[7];
        bool active;
        cout << "input the time (format: xx:xx:xx): ";
        cin >> time;
        cout << endl << "active on: " << endl;
        string days[] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
        for(int i = 0; i < 7; i++) {
          cout << days[i] << " (1 for yes, otherwise for no): ";
          cin >> dayArray[i];
          cout << endl;
        }
        string tempActive;
        cout << endl << "do you want this to be active? y/n : ";
        cin >> tempActive;
        if(tempActive.compare("y") == 0) {
          active = true;
        } else {
          active = false;
        }
        Alarm temp = Alarm(time, dayArray, active);
        writeAlarm(temp);
        curAlarms.push_back(temp);
      } else if(inp.compare("dela") == 0) {
        displayAlarms();
        cout << endl << endl << "type the # of the alarm to delete: ";
        int dLine;
        cin >> dLine;
        delAlarm(dLine);
      } else {
        cout << "input not recognized";
      }
    } else {
      cout << "input not recognized" << endl;
    }
    continuePrint = true;
    cin >> inp;
  }
  continuePrint = false;
  exitSt = true;
  return;
}

void displayTime() { //alarm clock display
  while(true) {
    while(continuePrint && exitSt == false) {
      for(int i = 0; i < 50; i++) {
        cout << endl;
      }
      cout << getCTime() << endl;
      sleep(1);
    }
    if(!continuePrint && exitSt == true) {
      return;
    }
  }
}

int main() {
  ifstream inFS;
  inFS.open("alarms.txt"); //reads "saved" alarms
  if(!inFS.is_open()) {
    return -1;
  }
  string time;
  int dayArray[7];
  bool active;
  string temp;

  inFS >> time;
  for(int i = 0; i < 7; i++) {
    inFS >> dayArray[i];
  }
  inFS >> temp;
  if(temp.find("ACTIVE")) {
    active = true;
  } else {
    active = false;
  }
  while(!inFS.eof()) {
    Alarm tempAlarm = Alarm(time, dayArray, active);
    curAlarms.push_back(tempAlarm);
    inFS >> time;
    for(int i = 0; i < 7; i++) {
      inFS >> dayArray[i];
    }
    inFS >> temp;
    if(temp.find("ACTIVE")) {
      active = true;
    } else {
      active = false;
    }
  }
  inFS.close();


  inFS.open("questions.txt"); //storing all "saved" questions
  if(!inFS.is_open()) {
    cout << "didn't open questions.txt" << endl;
    return -1;
  }
  string question, answer, curLine;
  getline(inFS, curLine);
  while(!inFS.eof()) {
    qa tempQA;
    int ansInd = curLine.find("A: ");
    tempQA.q = curLine.substr(3, ansInd - 3);
    tempQA.a = curLine.substr(ansInd, curLine.length());
    quesAns.push_back(tempQA);
    getline(inFS, curLine);
  }
  inFS.close();

  displayAlarms();
  displayQuestions();


  //main loop
  thread first (askInp);
  thread second (displayTime);

  first.join();
  second.join();
  cout << "done" << endl;
} 

/*
TODO:
implement setting alarm (for specific day(s)?) DONE
writing to file to save past alarms DONE
  deleting previous alarms DONE
turn alarms on and off DONE
questions.txt
  choose random
actual alarm functionality
  asks a question to turn off
based on response from user?
read in and store existing alarms and questions on startup, on addition
*/

