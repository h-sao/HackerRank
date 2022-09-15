#include <iostream>
#include <cstdio>
using namespace std;

int get_number(std::string number){
    int ret;
//    try {
        ret = std::stoi(number);
//    } catch (std::invalid_argument e) {
//        cout << e.what() << endl;
//    } catch (std::out_of_range e) {
//        cout << e.what() << endl;
//    }
    return ret;
}

std::string get_anser(int n){
    std::string number[] ={ "", "one", "two", "three", "four", "five", 
                "six", "seven", "eight", "nine" }; 
    if(n < 10){
        return number[n];        
    }
    if(n % 2){
        return "odd";
    }else{
        return "even";
    }
}

int main() {
    // Complete the code.
    string first_number, end_number;

    cin >> first_number;
    auto start = get_number(first_number);
    cin >> end_number;
    auto end = get_number(end_number);
    
    for(int i = start; i <= end; ++i){
        cout << get_anser(i) << endl;
    }    
        
    return 0;
}
