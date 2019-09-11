#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Date
{
    int month;
    int day;
    int startShift; //minus for before 00:00
    int startSleep = 0;
    int endSleep = 0;
};

struct Schedule
{
    int sleepDuration;
    vector<Date> shifts;
};

int main() {
    //--------------------PART 1--------------------//
    ifstream file("input.txt", std::ifstream::in); //input file

    string line;
    vector<string> sortedLog;
    map<int, Schedule> guards;
    map<int,int>minuteSleep;
    int guardID;
    int sleepCount;
    int sleepTime;
    int minuteWithMaxSleep = 0;

    //sorting input
    while(getline(file, line)) {
        sortedLog.push_back(line);
    }
    sort(sortedLog.begin(), sortedLog.end());

    for(auto& i : sortedLog) {
        Date date;
        date.month = stoi(i.substr(6,2));
        date.day = stoi(i.substr(9,2));

        if(i.find('#') != string::npos) {//line contains guard ID
            guardID = 0;
            sleepCount = 0;

            Schedule schedule;

            int hour = stoi(i.substr(12,2));
            int min = stoi(i.substr(15,2));
            if(hour == 23)
                min = min - 60;

            date.startShift = min;

            guardID = stoi(i.substr(26, 4));

            guards[guardID].shifts.push_back(date);
        }
        if(i.find('l') != string::npos) {//line when guard falls asleep
            sleepTime = stoi(i.substr(15,2));
        }
        if(i.find('w') != string::npos) {//line when guard wakes up
            sleepCount = stoi(i.substr(15,2)) - sleepTime;
            guards[guardID].sleepDuration += sleepCount;

            date.startSleep = sleepTime;
            date.endSleep = stoi(i.substr(15,2));
            guards[guardID].shifts.push_back(date);

            sleepTime = 0;
        }
    }

    int currentMaxSleep = 0;
    for(auto it = guards.cbegin(); it != guards.end(); it++) {
        if(it->second.sleepDuration > currentMaxSleep) {
            currentMaxSleep = it->second.sleepDuration;
            guardID = it->first;
        }
    }

    for(auto& i : guards[guardID].shifts) {
        if(i.startSleep || i.endSleep) {
            for(int j = i.startSleep; j < i.endSleep; j++) {
                minuteSleep[j]++;
            }
        }
    }

    for(auto it = minuteSleep.cbegin(); it != minuteSleep.cend(); it++) {
        if(it->second > minuteWithMaxSleep)
            minuteWithMaxSleep = it->first;
    }
    cout << "ID: " << guardID << " minute: " << minuteWithMaxSleep << endl;
    cout << "1: " << minuteWithMaxSleep*guardID << endl;

    //--------------------PART 2--------------------//
    int minute = 0;
    int sleep = 0;

    for(auto& i : guards) {
        minuteSleep.clear();
        for(auto& j : i.second.shifts) {
            if(j.startSleep || j.endSleep) {
                for(int k = j.startSleep; k < j.endSleep; k++) {
                    minuteSleep[k]++;
                }
            }
        }
        for(auto it = minuteSleep.cbegin(); it != minuteSleep.cend(); it++) {
            if(it->second > sleep) {
                sleep = it->second;
                minute = it->first;
                guardID = i.first;
            }
        }
    }

    cout << "ID: " << guardID << " minute: " << minute << endl;
    cout << "2: " << guardID * minute << endl;
}