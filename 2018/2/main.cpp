#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, const char** argv) {

    string line;
    int doubles = 0;
    int triples = 0;
    int res = 0;
    bool doubleFound = 0;
    bool tripleFound = 0;

    std::ifstream file("input.txt", std::ifstream::in); //input file

    while(getline(file, line)) { //read one line at a time
        doubleFound = 0;
        tripleFound = 0;

        for(auto& c : line) { //looking at each character in string
            res = 0;

            for(auto& d : line) { //searching for number of occurances of c
                if(c == d)
                    res++;
            }

            if(res == 2 && !doubleFound) { //if double found
                doubles++;
                doubleFound = 1;
            }

            else if(res == 3 && !tripleFound) { //if triple found
                triples++;
                tripleFound = 1;
            }
        }
        line.clear();
    }

    cout << doubles*triples << endl; //checksum
}