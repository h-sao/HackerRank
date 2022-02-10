/*
 * Complete the 'aVeryBigSum' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER_ARRAY ar as parameter.
 */

long aVeryBigSum(vector<long> ar) {
    long total = 0;
    for(const auto v: ar){
        total += v;
    }
    return total;
}
