#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

int main(int argc, const char** argv) {

    //--------------------PART 1--------------------//

    std::vector<int> changes; //vector containing all frequency changes
    int inputNum;
    int freq = 0;

    std::ifstream file("input.txt", std::ifstream::in);
    
    //pushing all numbers in input file into vector
    while(file >> inputNum) {
       changes.push_back(inputNum);
    }

    //calculating sum of frequencies
    for(int i = 0; i < changes.size(); i++)
    {
        freq += changes[i];
    }

    cout << freq << endl;

    //--------------------PART 2--------------------//
    std::vector<int> newFreqs; //vector containing new frequencies

    //variables
    bool dupFound = 0;
    freq = 0;

    while(!dupFound) { //while no duplicated freq is found
        for(auto i : changes) {
            freq += i;

            if(std::find(newFreqs.begin(), newFreqs.end(), freq) != newFreqs.end()) {
                dupFound = 1;
                break;
            }
            newFreqs.push_back(freq);
        }
    }

    cout << freq << endl;
}
