#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

const int DECIMAL = 10;

/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */
void large_pattern(int n) {
    int calc[0xff];     // need to 159, coz 100! number of digits
    int sum[0xff];     // need to 159, coz 100! number of digits
    
    calc[0] = 1;
    sum[0] = 0;
    int max_pos = 1;
    for(int i = 0; i < n; ++i){
        int mul = i + 2;

        // do calctlation        
        for(int j = 0; j < max_pos; ++j){
            calc[j] *= mul;
        }

        // put array  ??????????????????
        for(int j = 0; j < max_pos; ++j){
            if(calc[j] >= DECIMAL){
                sum[j] = calc[j] % DECIMAL;
                sum[j+1] = calc[j] / DECIMAL;
                if(max_pos <= j+1){
                    ++ max_pos;
                }
            }else{
                sum[j] = calc[j];
            }
        }
        
        
        

#if 0
            if(calc[now] >= DECIMAL){
                calc[next] += calc[now] / DECIMAL;
                calc[now]    = calc[now] % DECIMAL;
                if(max_pos <= next){
                    ++ max_pos;
                    break;
                }
            }else{
                calc[j+1] = 0;     // init next value
            }

#endif


        
    }
}

void extraLongFactorials(int n) {
    // large calcration
    if(n > 20){
        large_pattern(n);
        return;
    }
    
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
