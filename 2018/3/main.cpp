#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

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

Claim::~Claim()
{
}

int findCommon(Claim a, Claim b) {
    Claim furthest(0,0,0,0,0);
    Claim shortest(0,0,0,0,0);
    bool overlapping = 0;
    int h = 0;
    int w = 0;
    float d1 = 0;
    float d2 = 0;

    //checking which claim is furthest from origin
    d1 = sqrt((a.x) * (a.x) + (a.y) * (a.y));
    d2 = sqrt((b.x) * (b.x) + (b.y) * (b.y));

    if(d1 > d2) {
        furthest = a;
        shortest = b;
    }
    else {
        furthest = b;
        shortest = a;
    }

    //check if claims are overlapping
    if((furthest.y < shortest.y + shortest.height) && (furthest.x < shortest.x + shortest.width))
        overlapping = 1;
    
    if(overlapping)
        return (shortest.height - (furthest.y - shortest.y)) * (shortest.width - (furthest.x - shortest.x));

    if(!overlapping)
        return 0;
}

int main() {
    vector<Claim> claims;
    string ID;
    string x;
    string y;
    string width;
    string height;
    
    ifstream file("input.txt", std::ifstream::in); //input file

    while(!file.eof()) {
        getline(file, ID, '#'); getline(file, ID, ' '); //ID
        getline(file, x, ' '); getline(file, x, ','); //x
        getline(file, y, ':'); //y
        getline(file, width, ' '); getline(file, width, 'x'); //width
        getline(file, height, '\n'); //height

        //cout << "ID: " << ID << endl << "x: " << x << endl << "y: " << y << endl << "width: " << width << endl << "height: " << height  << endl;
        claims.push_back(Claim(stoi(ID), stoi(x), stoi(y), stoi(width), stoi(height)));
    }

    cout << "Done loading claims" << endl;

    int commonInches = 0;
    float percentFinished = 0;

    cout << "Comparing claims" << endl;
    for(int i = 0; i < claims.size(); i++) {
        percentFinished = (float)i / claims.size();
        cout << percentFinished*100 << "%" << endl;
        
        for(int j = i + 1; j < claims.size(); j++) {
            commonInches += findCommon(claims[i], claims[j]);
        }
    }

    cout << commonInches << endl;
}