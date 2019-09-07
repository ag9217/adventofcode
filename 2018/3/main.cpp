#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Claim
{
public:
    //variables
    int ID = 0;
    int x = 0;
    int y = 0;
    int width = 0;
    int height = 0;

    //constructor & destructor
    Claim(int ID, int x, int y, int width, int height);
    ~Claim();
};

Claim::Claim(int ID, int x, int y, int width, int height)
{
    this->ID = ID;
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

Claim::~Claim() {}

int main() {
    //--------------------PART 1--------------------//
    vector<Claim> claims;
    int heatMap[1000][1000] = {0};
    string ID;
    string x;
    string y;
    string width;
    string height;
    
    ifstream file("input.txt", std::ifstream::in); //input file

    while(!file.eof()) { //parsing file
        getline(file, ID, '#'); getline(file, ID, ' '); //ID
        getline(file, x, ' '); getline(file, x, ','); //x
        getline(file, y, ':'); //y
        getline(file, width, ' '); getline(file, width, 'x'); //width
        getline(file, height, '\n'); //height

        claims.push_back(Claim(stoi(ID), stoi(x), stoi(y), stoi(width), stoi(height)));
    }

    int commonInches = 0;

    for(auto& i : claims) {
        for(int j = i.x; j < i.x + i.width; j++) {
            for(int k = i.y; k < i.y + i.height; k++) {
                heatMap[j][k]++;
            }
        }
    }

    for(int i = 0; i < 1000; i++) {
        for(int j = 0; j < 1000; j++) {
            if(heatMap[i][j] > 1)
                commonInches++;
        }
    }

    cout << commonInches << endl;

    //--------------------PART 2--------------------//
    for(auto& i : claims) {
    bool overlap = 0;
        for(int j = i.x; j < i.x + i.width; j++) {
            for(int k = i.y; k < i.y + i.height; k++) {
                if(heatMap[j][k] == 1) //no overlap since only +1
                    continue;

                else
                    overlap = 1;
            }
        }

        if(!overlap) { //if no overlap tiles found after looking at entire claim
            cout << "ID:" << i.ID << " does not overlap with other claims" << endl;
        }
    }
}