#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Date
{
    int month;
    int day;
};

struct Guard
{
    int id;
    int startShift; //minus for before 00:00
    int sleep;
    int wakeup;
    vector<Date> shifts; //dates when guard works
};


int main() {
    ifstream file("test.txt", std::ifstream::in); //input file
    string line;
    string tempid;
    int hour = 0;
    int min = 0;

    vector<Guard*> sortedLog;

    while(getline(file, line)) {
        std::size_t foundID = line.find('#');
        if(foundID != std::string::npos) {
            sortedLog.push_back(new Guard);

            Date date;
            date.month = stoi(line.substr(6,2));
            date.day = stoi(line.substr(9,2));
            sortedLog[sortedLog.size() - 1]->shifts.push_back(date);

            hour = stoi(line.substr(12,2));
            min = stoi(line.substr(15,2));

            if(hour == 23)
                sortedLog[sortedLog.size() - 1]->startShift = min - 60;

            else
                sortedLog[sortedLog.size() - 1]->startShift = min;

            tempid = line.substr(26, 4);
            if(tempid.at(3) == ' ')
                tempid = tempid.substr(0, tempid.size() - 1);

            sortedLog[sortedLog.size() - 1]->id = stoi(tempid);
        }
    }
}
