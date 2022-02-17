void plusMinus(vector<int> arr) {
    int total_cnt = 0;
    int zero_cnt = 0, puls_cnt = 0, minus_cnt = 0;

    for(int val: arr){
        if(val == 0){
            ++zero_cnt;
        }else{
            if(val > 0){
                ++puls_cnt;
            }else{
                ++minus_cnt;
            }
        }
        ++total_cnt;
    }
    float max_number = static_cast<float>(total_cnt);
    cout << (static_cast<float>(puls_cnt)/max_number) << endl;
    cout << (static_cast<float>(minus_cnt)/max_number) << endl;
    cout << (static_cast<float>(zero_cnt)/max_number) << endl;
}
