#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

int main(int argc, const char** argv) {

    std::ifstream file("input.txt", std::ifstream::in); //input file

    vector<string> boxIDs;
    map<char, int> letFreq;
    map<int, int> pairs;
    char temp;
    int tempMax = 0;
    int tempIndex = 0;
    string tempBoxID;
    int i = 2;

    while(file >> tempBoxID) {
        boxIDs.push_back(tempBoxID);
    }

    //looking at each string in vector
    for(int j = 0; j < boxIDs.size(); j++) {

        //check letter frequency in string
        for(int k = 0; k < boxIDs[j].length(); k++) {
            temp = boxIDs[j].at(k);
            std::map<char,int>::iterator it = letFreq.find(temp);

            if(it != letFreq.end()) { //if letter found
                it->second++;
            }

            else { //letter not found
                letFreq.insert(make_pair(temp, 1));
            }
        }

        for(int k = 0; k < letFreq.size(); k++) {
                        
        }
    }
}