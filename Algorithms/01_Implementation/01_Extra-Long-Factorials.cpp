#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

const int DECIMAL = 10;
bool MY_DEBUG = true;


// debug print
void debug_show_calc(int step_number, std::array<long, 0xff> &calc, int keta){
    if(!MY_DEBUG) return;

    std::cout << endl << "i:" << step_number << endl;
    std::cout << "calc:";
    for(int j = (keta-1); j >= 0; --j){
        std::cout << calc[j] << ",";
    }
    std::cout << std::endl;
}

// debug print
void debug_show_sum(std::array<long, 0xff> &sum, int keta, bool show_keta){
    if(!MY_DEBUG) return;

    if(show_keta)
        std::cout << "keta:" << keta << endl;
    
    std::cout << "sum:";
    for(int j = (keta-1); j >= 0; --j){
        std::cout << sum[j] << ",";
    }
    std::cout << std::endl;
}

/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */
 bool separate_value(long val, long& keta0, long& keta1)
 {
    bool fg = false;
    if(val >= DECIMAL){
        keta0 += val % DECIMAL;
        keta1 += val / DECIMAL;

        fg = true;
    }else{
        keta0 += val;
    }
    
    if(keta0 >= DECIMAL){
        keta1 += keta0 / DECIMAL;
        keta0 = keta0 % DECIMAL;
        fg = true;
    }

    return fg;
 }
 
void large_pattern(int n) {
    std::array<long, 0xff> calc = {1}; // need to 159, coz 100! number of digits
    std::array<long, 0xff> sum = calc; // need to 159, coz 100! number of digits
    
    int max_keta = 1;
    for(int i = 0; i < n; ++i){
        int mul = i + 1;

        // do calctlation        
        for(int j = 0; j < max_keta; ++j){
            calc[j] = sum[j] * mul;
            sum[j] = 0;
        }
        debug_show_calc(i, calc, max_keta);  ///////////////
        
        // put array
        for(int j = 0; j < max_keta; ++j){
            if( separate_value(calc[j], sum[j], sum[j+1])){
                if(max_keta <= j+1){
                    ++ max_keta;
                    debug_show_sum(sum, max_keta, true);  ///////////////
                    break;
                }
            }
            debug_show_sum(sum, max_keta, false);  ///////////////
        }
        
        // 
//        if(sum[max_keta -1]){
        std::cout << "keta afure? ";
        std::cout << max_keta << ", ";
        std::cout << sum[max_keta -1] << endl;
        std::cout << "---" << endl;
            if(sum[max_keta -1] >= DECIMAL){
                //////////////////////
            }
//        }
        
    }
    
    for(int j = (max_keta-1); j >= 0; --j){
        std::cout << sum[j];
    }
}

void extraLongFactorials(int n) {
    // large calcration
    //if(n > 20){
        large_pattern(n);
        return;
    //}
    
    // it is noemal calclation
    unsigned int sum = 1;
    for(int i = 1; i < (n+1); ++i){
        sum *= i;
    }
    std::cout << sum;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    extraLongFactorials(n);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
