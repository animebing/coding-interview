#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// staring from the first element, then accumulate each element to tmp, if tmp >= 0, then we can go on accumulate 
// but if not, we need to accumulate from a new element, and keep track of the largest sum
int findGreatestSumOfSubarray_0(vector<int> &data) {
    int res = INT_MIN;
    int tmp = 0;
    for (int i = 0; i < data.size(); i++) {
        tmp += data[i];
        res = max(res, tmp);
        if (tmp < 0) tmp = 0;
    }
    return res;
}

// DP method, cur_max represents the max sum of subarray ending with an element
int findGreatestSumOfSubarray_1(vector<int> &data) {
    int res = INT_MIN;
    int cur_max = 0;
    for (int i = 0; i < data.size(); i++) {
        if (cur_max < 0) cur_max = data[i];
        else cur_max += data[i];
        res = max(res, cur_max);
    }
    return res;
}

int main(int argc, char **argv) {
    vector<int> data = {1, -2, 3, 10, -4, 7, 2, -5};
    int res_0 = findGreatestSumOfSubarray_0(data);
    cout << res_0 << endl;
    int res_1 = findGreatestSumOfSubarray_1(data);
    cout << res_1 << endl;
    return 0;
}
