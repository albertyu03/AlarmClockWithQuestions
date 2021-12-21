#include <iostream>
#include <string>
#include <fstream>
#include<time.h>
#include "alarm.h"
using namespace std;

string getCTime() {
  time_t timer;
  time(&timer);
  return asctime(localtime(&timer));
}
string truncDay(string ascString) {
  return ascString.substr(0, 3);
}
string truncTime(string ascString) {
  return ascString.substr(11, 8);
}
void writeAlarm(Alarm newAlarm) {
  ofstream outFS;
  outFS.open("alarms.txt", ios::app);
  if(!outFS.is_open()) {
    cout << "error: alarm.txt not opened" << endl;
    return;
  }
  outFS << newAlarm.GetTime() << " ";
  for(int i = 0; i < 7; i++) {
    outFS << newAlarm.GetDayArray()[i] << " ";
  }
  if(newAlarm.GetActive()) {
    outFS << "ACTIVE"; 
  }
  outFS << endl;
  outFS.close();
}
void displayAlarms() {
  ifstream inFS;
  inFS.open("alarms.txt");
  if(!inFS.is_open()) {
    cout << "error: alarm.txt not opened" << endl;
    return;
  }
  string curLine;
  int numAlarm = 1;
  getline(inFS, curLine);

  while(!inFS.eof()) {
    cout << "Alarm " << numAlarm << ": " << curLine << endl;
    getline(inFS, curLine);
    numAlarm++;
  }
}
void delAlarm(int line) {
  ifstream inFS;
  inFS.open("alarms.txt");
  if(!inFS.is_open()) {
    cout << "error: alarm.txt not opened" << endl;
    return;
  }
  ofstream outFS;
  outFS.open("temp.txt", ios::app);
  outFS.close();
  outFS.open("temp.txt", ios::app);
  if(!outFS.is_open()) {
    cout << "error: temp.txt not opened" << endl;
    return;
  }
  int curLineNum = 1;
  string curLine;
  getline(inFS, curLine);
  while(!inFS.eof()) {
    if(!(curLineNum == line)) {
      outFS << curLine << endl;
    }
    curLineNum++;
    getline(inFS, curLine);

  }
  remove("alarms.txt");
  rename("temp.txt", "alarms.txt");

  inFS.close();
  outFS.close();
  return;
}


void writeQuestion(string question, string answer) {
  ofstream outFS;
  outFS.open("questions.txt", ios::app);
  if(!outFS.is_open()) {
    cout << "error: questions.txt not opened" << endl;
    return;
  }
  outFS << "Q: " << question << " A: " << answer << endl;
  outFS.close();
}
void displayQuestions() {
  ifstream inFS;
  inFS.open("questions.txt");
  if(!inFS.is_open()) {
    cout << "error: questions.txt not opened" << endl;
    return;
  }
  string curLine;
  int numLine = 1;
  getline(inFS, curLine);

  while(!inFS.eof()) {
    int ansInd = curLine.find("A: ");
    cout << numLine << ": " << curLine.substr(3, ansInd - 3) << endl << "   " << curLine.substr(ansInd, curLine.length()) << endl;
    getline(inFS, curLine);
    numLine++;
  }
}
void delQuestion(int line) {
  ifstream inFS;
  inFS.open("questions.txt");
  if(!inFS.is_open()) {
    cout << "error: questions.txt not opened" << endl;
    return;
  }
  ofstream outFS;
  outFS.open("temp.txt", ios::app);
  outFS.close();
  outFS.open("temp.txt", ios::app);
  if(!outFS.is_open()) {
    cout << "error: temp.txt not opened" << endl;
    return;
  }
  int curLineNum = 1;
  string curLine;
  getline(inFS, curLine);
  while(!inFS.eof()) {
    if(!(curLineNum == line)) {
      outFS << curLine << endl;
    }
    curLineNum++;
    getline(inFS, curLine);

  }
  remove("questions.txt");
  rename("temp.txt", "questions.txt");

  inFS.close();
  outFS.close();
  return;
}