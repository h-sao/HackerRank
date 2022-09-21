#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

std::vector<unsigned long> get_data(){
    std::vector<unsigned long> data;

    std::string line;
    std::getline(cin, line);
    auto separator = std::string(" ");
    auto separator_length = separator.length();
    
    auto list = std::vector<std::string>();
    auto offset = std::string::size_type(0);
    while (true) {
        auto pos = line.find(separator, offset);
        if (pos == std::string::npos) {
            list.push_back(line.substr(offset));
            break;
        }
        list.push_back(line.substr(offset, pos - offset));
        offset = pos + separator_length;
    }
    std::for_each(list.begin(), list.end(), 
    [&data](std::string s){
        data.push_back(std::stoi(s));
    });

    return data;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    auto init_data = get_data();
    auto n = init_data.at(0);
    auto q = init_data.at(1);
    
    int max_num = -1;
    int input_count = 0;
    while((!std::cin.eof())||(n >= input_count)){
        ++input_count;
        auto numbers = get_data();

    }

    //std::cout << input_count << std::endl;
    //std::cout << max_num << std::endl;
      
    return 0;
}
