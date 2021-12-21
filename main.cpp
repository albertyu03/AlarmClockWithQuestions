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
using namespace std;



int main() {
  vector<Alarm> curAlarms;
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
  vector<qa> quesAns;
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

