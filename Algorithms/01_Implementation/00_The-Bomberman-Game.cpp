#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int DETONATE_TIME = 3;
int PLANT_1ST_TIME = 1;
int INITIAL_TIME = -1;
int UNINITIALIZES_TIME = 9;
int COMPARE_SAVE_TIME = 2;

bool MY_DEBUG = true;
unsigned int CHECK_ARRAY_MAX = 16;

void debug_print_bomtimer(vector<vector<int>> &bomTimer)
{
    if(!MY_DEBUG) return;
    
    for(auto v0: bomTimer){
        for(auto v1: v0){
            if(v1 == INITIAL_TIME){
                cout << 9;
            }else{
                cout << v1;
            }
        }
        cout << endl;
    }
    cout << "-----" << endl;
}

void elapse_ont_second(vector<vector<int>> &bomTimer)
{
    unsigned int row = bomTimer.size();
    for(unsigned int i = 0; i < row; ++i){
        auto &box = bomTimer.at(i);
        unsigned int col = box.size();
        for(unsigned int j = 0; j < col; ++j){
            ++ box.at(j);
        }
    }
}

void reset_neighbour_value(vector<vector<int>> &v, unsigned int check_row, unsigned int check_col)
{
    if(check_row >= 0 && check_row < v.size() ){
        if(check_col >= 0 && check_col < v.at(check_row).size() ){
            if(v.at(check_row).at(check_col) != DETONATE_TIME){
               v.at(check_row).at(check_col) = INITIAL_TIME; 
            }
        }
    }
}

void check_detonate(vector<vector<int>> &bomTimer)
{
    unsigned int row = bomTimer.size();
    for(unsigned int i = 0; i < row; ++i){
        auto &box = bomTimer.at(i);
        unsigned int col = box.size();
        for(unsigned int j = 0; j < col; ++j){
            auto &ck_data = bomTimer.at(i).at(j);
            // check detonate
            if(ck_data != 0){
                if( ck_data >= DETONATE_TIME){
                    ck_data = INITIAL_TIME;
                    reset_neighbour_value(bomTimer, i-1, j);
                    reset_neighbour_value(bomTimer, i+1, j);
                    reset_neighbour_value(bomTimer, i, j-1);
                    reset_neighbour_value(bomTimer, i, j+1);
                }
            }
        }
    }
}

unsigned int pass_time(vector<vector<int>> &bomTimer, vector<vector<int>> &iniTimer, int all_time, bool does_compare)
{
    unsigned int timer = 0;

    if(all_time <= COMPARE_SAVE_TIME) does_compare = false;

    while(timer < all_time){
        if(MY_DEBUG){
            cout << "===" << endl;
            cout << timer << endl;
        }

        check_detonate(bomTimer);
        //debug_print_bomtimer(bom_timer);
        
        elapse_ont_second(bomTimer);
        debug_print_bomtimer(bomTimer);

        if(does_compare){
            // save compare init pattern
            if((timer == COMPARE_SAVE_TIME)&&(iniTimer.at(0).at(0) == UNINITIALIZES_TIME)){
                if(MY_DEBUG){
                    cout << "= get init pattern" << endl;
                }
                for(unsigned int i = 0; i < iniTimer.size(); ++i){
                    for(unsigned int j = 0; j < iniTimer.at(i).size(); ++j){
                        iniTimer.at(i).at(j) = bomTimer.at(i).at(j);
                    }
                }
            }else{
                // ckeck repeat pattern
                if(iniTimer.at(0).at(0) != UNINITIALIZES_TIME){
                    auto same_fg = true;
                    for(unsigned int i = 0; i < iniTimer.size(); ++i){
                        for(unsigned int j = 0; j < iniTimer.at(i).size(); ++j){
                            if(bomTimer.at(i).at(j) != iniTimer.at(i).at(j)){
                                if(MY_DEBUG){
                                
                                    cout << bomTimer.at(i).at(j) << ":" << iniTimer.at(i).at(j)<<endl;
                                }
                                same_fg = false;
                                break;
                            }
                        }
                        if(!same_fg){
                            break;
                        }
                    }
                    if(same_fg){
                        if(MY_DEBUG){
                            cout << "= exist pattern: " << timer << endl;
                        }
                        break;
                    }
                }
            }
        }
        ++timer;
    }
    return timer;
}

/*
 * Complete the 'bomberMan' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING_ARRAY grid
 */

vector<string> bomberMan(int n, vector<string> grid) {
    if(!n) return grid;    
    if(!(n-1)) return grid;

    //---------------------------------
    // prepare time array
    unsigned int row_time_array = grid.size();
    unsigned int col_time_array = grid.at(0).length();
    // save initial status
    unsigned int row_ini_array = std::min(row_time_array, CHECK_ARRAY_MAX);
    unsigned int col_ini_array = std::min(col_time_array, CHECK_ARRAY_MAX);
    vector<vector<int>> bom_timer(row_time_array, vector<int>(col_time_array));
    vector<vector<int>> ini_timer(row_ini_array, vector<int>(col_ini_array));
    ini_timer.at(0).at(0) = UNINITIALIZES_TIME;    // no yet use
    {
        for(unsigned int i = 0; i < row_time_array; ++i){
            for(unsigned int j = 0; j < col_time_array; ++j){
                if(grid.at(i).at(j) == 'O'){
                    bom_timer.at(i).at(j) = PLANT_1ST_TIME;
                }else{
                    bom_timer.at(i).at(j) = INITIAL_TIME;
                }
            }
        }
    }
    
    //---------------------------------
    // time pass
    unsigned int total_time = n;
    auto seek_time = pass_time( bom_timer, ini_timer, total_time, true );
    if(seek_time < total_time){
        // exist same pattern
        total_time = (total_time - COMPARE_SAVE_TIME)% (seek_time - COMPARE_SAVE_TIME);
        total_time += (COMPARE_SAVE_TIME + 1);
        if(MY_DEBUG){
            cout << "===until seek time: ";
            cout << total_time << endl;
        }
        pass_time( bom_timer, ini_timer, total_time, false );
    }

    //---------------------------------
    // update output
    unsigned int row = bom_timer.size();
    for(unsigned int i = 0; i < row; ++i){
        string out = "";
        auto &ck_row = bom_timer.at(i);
        unsigned int col = ck_row.size();
        for(unsigned int j = 0; j < col; ++j){
            if(ck_row.at(j) >= PLANT_1ST_TIME){
                out += "O";
            }else{
                out += ".";       // IMITIAL_TIME
            }
        }
        grid.at(i) = out;
    }
        

    return grid;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int r = stoi(first_multiple_input[0]);

    int c = stoi(first_multiple_input[1]);

    int n = stoi(first_multiple_input[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
