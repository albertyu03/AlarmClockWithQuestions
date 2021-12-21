#include <iostream>
#include <vector>
#include "alarmFuncs.h"
#include "alarm.h"
using namespace std;

Alarm::Alarm() {
}
Alarm::Alarm(bool active) {
  this->active = active;
}
Alarm::Alarm(string time, int dayArray[], bool active) {
  this->time = time;
  for(int i = 0; i < 7; i++) {
    this->dayArray[i] = dayArray[i];
  }
  this->active = active;
}
string Alarm::GetTime() {
  return time;
}
int* Alarm::GetDayArray() {
  return dayArray;
}
bool Alarm::GetActive() {
  return active;
}
void Alarm::SetDayArray(int newArray[]) {
  for(int i = 0; i < 7; i++) {
    dayArray[i] = newArray[i];
  }
}
void Alarm::SetTime(string time) {
  this->time = time;
}
void Alarm::SetActive(bool active) {
  this->active = active;
}

bool Alarm::CheckActive() {
  if(this->active == 0) {
    return false;
  }
  if(time.compare(truncTime(getCTime())) == 0) {
    string curDay = truncDay(getCTime());
    cout << "time compare worked!" << endl;
    cout << this->dayArray[1] << endl;
    if(curDay.compare("Mon") == 0 && this->dayArray[0] == 1) {
      return true;
    } else if(curDay.compare("Tue") == 0 && this->dayArray[1] == 1) {
      cout << "should return true!" << endl;
      return true;
    } else if(curDay.compare("Wed") == 0 && this->dayArray[2] == 1) {
      return true;
    } else if(curDay.compare("Thu") == 0 && this->dayArray[3] == 1) {
      return true;
    } else if(curDay.compare("Fri") == 0 && this->dayArray[4] == 1) {
      return true;
    } else if(curDay.compare("Sat") == 0 && this->dayArray[5] == 1) {
      return true;
    } else if(curDay.compare("Sun") == 0 && this->dayArray[6] == 1) {
      return true;
    }
  }
  return false;
}


