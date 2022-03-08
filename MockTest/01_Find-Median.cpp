/*
 * Complete the 'findMedian' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int findMedian(vector<int> arr) {
    std::sort(arr.begin(), arr.end());
    auto num = arr.size() / 2;
    return arr.at(num);
}
