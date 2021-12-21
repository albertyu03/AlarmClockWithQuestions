#ifndef ALARM_H
#define ALARM_H
using namespace std;

struct qa {
  string q, a;
};

class Alarm {
  public:
    Alarm();
    Alarm(bool active);
    Alarm(string time, int dayArray[], bool active);
    string GetTime();
    int* GetDayArray();
    bool GetActive();
    void SetTime(string time);
    void SetDayArray(int newArray[]);
    void SetActive(bool active);
    bool CheckActive();
  private:
    int dayArray[7] = {0};
    string time = "";
    bool active = false;
    void initializeDA();
};
#endif