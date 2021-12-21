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
  string time;
  int active;
  int dayArray[7] = {0};
  cin >> time >> active;
  Alarm testAlarm = Alarm(time, dayArray, active);
  writeAlarm(testAlarm);
  displayAlarms();
  /*
  cout << "set your alarm!" << endl << "what time?";
  string time;
  cin >> time;
  int days[7] = {0};
  for(int i = 0; i < 7; i++) {
    cout << "Day " << i+1 << ": ";
    cin >> days[i];
    cout << endl;
  }

  Alarm firstAlarm = Alarm(time, days, true);
  cout << "Alarm has been set for " << firstAlarm.GetTime() << endl;
  cout << "Alarm is active on these days: ";
  for(int i = 0; i < 7; i++) {
    cout << firstAlarm.GetDayArray()[i] << " ";
  }
  cout << endl;
  if(firstAlarm.GetActive()) { cout << "Alarm is active" << endl; }
  writeAlarm(firstAlarm);
  */
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

