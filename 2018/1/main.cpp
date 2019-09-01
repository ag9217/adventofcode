#include<iostream>
#include<fstream>
#include<string>
#include<vector>

int main(int argc, const char** argv) {

    std::string inputNum;
    std::vector<int> log;
    int sum;
    std::ifstream file("input.txt", std::ifstream::in);
    
    while(getline(file, inputNum)) {
        sum += std::stoi(inputNum);
        log.push_back(sum);
    }
    std::cout << sum << std::endl;
}
