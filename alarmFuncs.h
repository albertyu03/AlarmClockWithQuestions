#ifndef ALARMFUNCS_H
#define ALARMFUNCS_H

#include "alarm.h"

std::string getCTime();
std::string truncDay(std::string ascString);
std::string truncTime(std::string ascString);
void writeAlarm(Alarm newAlarm);
void displayAlarms();
void delAlarm(int line);
void writeQuestion(string question, string answer);
void displayQuestions();
void delQuestion(int line);
void printFunctions();
#endif