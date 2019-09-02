#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

int main(int argc, const char** argv) {

    //--------------------PART 1--------------------//

    //vectors 
    std::vector<int> changes; //vector containing all frequency changes

    //variables
    int inputNum;
    int freq = 0;
    bool dupFound = 0;

    //opening input file
    std::ifstream file("input.txt", std::ifstream::in);
    
    //pushing all numbers in input file into vector
    while(!file.eof()) {
       file >> inputNum;
       changes.push_back(inputNum);
    }
    changes.pop_back(); //last number is put in vector twice

    //calculating sum of frequencies
    for(int i = 0; i < changes.size(); i++)
    {
        freq += changes[i];
    }

    cout << freq << endl; //printing final frequency

    //--------------------PART 2--------------------//
    
}
