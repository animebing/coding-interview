#include <iostream> 
#include <vector>

using namespace std;

// the elememnt indexed by right is not included
int inversePairCore(vector<int> &data, int left, int right) {
    if (right - left == 1) return 0;
    
    int res = 0;
    int middle = left + (right - left) / 2;
    
    res += inversePairCore(data, left, middle);
    res += inversePairCore(data, middle, right);

    vector<int> tmp(right - left, 0);
    int idx_tmp = right - left -1;
    int idx_left = middle - 1, idx_right = right - 1;
    while (idx_left >= left && idx_right >= middle) {
        if (data[idx_left] > data[idx_right]) {
            res += idx_right - middle + 1;
            tmp[idx_tmp--] = data[idx_left--];
        } else tmp[idx_tmp--] = data[idx_right--];
    }

    if (idx_left >= left) {
        while (idx_left >= left) tmp[idx_tmp--] = data[idx_left--];
    }

    if (idx_right >= middle) {
        while (idx_right >= middle) tmp[idx_tmp--] = data[idx_right--];
    }
    
    idx_left = left;
    for (int i = 0; idx_left < right; i++, idx_left++) data[idx_left] = tmp[i];
    return res;
}

int inversePair(vector<int> &data) {
    int n = data.size();
    if (n <= 1) return 0;

    return inversePairCore(data, 0, n);
}

int main(int argc, char **argv) {
    vector<int> data = {19, 4, 36, 7, 5, 6, 34, 675, 4, 234, 13};
    cout << "inverse pair: " << inversePair(data) << endl;
    return 0;
}
