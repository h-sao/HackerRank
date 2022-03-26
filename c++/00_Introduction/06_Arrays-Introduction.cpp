#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    // input total number
    std::string input_num;
    std::getline(cin, input_num);

    std::string input_data;
    std::getline(cin, input_data);
    
    std::istringstream iss(input_data);
    
    int MAX_SIZE = 1000;
    int array[MAX_SIZE];    
    std::string s;
    int num = 0;
    while(iss >> s){
        array[num] = std::stoi(s);
        ++num;
    }
    
    for(int j = (num-1); j >= 0; --j){
        std::cout << array[j];
        std::cout << " ";        
    }
    
  
    return 0;
}
