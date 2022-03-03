/*
 * Complete the 'staircase' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void staircase(int n) {
    char sp = ' ';
    char sh = '#';
    for(int step = 0; step < n; ++ step){
        auto ck_number = n - step - 1;
        for(int sharp = 0; sharp < n; ++ sharp){
            if( ck_number <= sharp){
                cout << sh;
            }else{
                cout << sp;
            }
        }
        cout << endl;
    }
}
