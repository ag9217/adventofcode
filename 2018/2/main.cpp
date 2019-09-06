#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, const char** argv) {

    //--------------------PART 1--------------------//
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

    cout << "Checksum: " << doubles*triples << endl; //checksum

    //--------------------PART 2--------------------//
    int diff = 0;
    int index = 0;
    vector<string> IDs;

    file.clear();
    file.seekg(0, ios::beg);

    while(getline(file, line)) {
        IDs.push_back(line);
    }

    for(auto& l1 : IDs) {
        for(auto& l2 : IDs) {
            for(int i = 0; i < l1.size(); i++) {
                if(diff > 1) { //more than 1 difference, go to next line
                    diff = 0;
                    break;
                }
                
                if(l1.at(i) != l2.at(i)) {
                    diff++;
                    index = i;
                }    
            }
            if(diff == 1) { //if there is only 1 difference
                cout << "ID1: " << l1 << endl << "ID2: " << l2 << endl;
                l1.erase(index, 1);
                cout << "Common ID: " << l1 << endl;
                break;
            }
        }
        if(diff = 1)
            break;
    } 
}