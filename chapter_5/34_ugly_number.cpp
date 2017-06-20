#include <iostream>
#include <vector>
#include <algorithm> // for min
using namespace std;

bool isUgly(int num) {
    while (num % 2 == 0) num /= 2;
    while (num % 3 == 0) num /= 3;
    while (num % 5 == 0) num /= 5;
    return num == 1;
}

int getIndexedUgly(int idx) {
    if (idx <= 0) return 0;

    int num = 0;
    int ugly_num = 0;

    while (ugly_num < idx) {
        num++;
        if (isUgly(num)) ugly_num++;
    }
    return num;
}

int getIndexedUgly_1(int idx) {
    if (idx <= 0) return 0;

    vector<int> ugly_vec(idx, 1);
    int idx_2 = 0, idx_3 = 0, idx_5 = 0;
    for (int i = 1; i < idx; i++) {
        int tmp = min(min(ugly_vec[idx_2] * 2, ugly_vec[idx_3] * 3), ugly_vec[idx_5] * 5);
        ugly_vec[i] = tmp;
        if (ugly_vec[idx_2] * 2 == tmp) idx_2++;
        if (ugly_vec[idx_3] * 3 == tmp) idx_3++;
        if (ugly_vec[idx_5] * 5 == tmp) idx_5++;
    }
    return ugly_vec[idx-1];
}

int main(int argc, char **argv) {
    int idx;
    while (1) {
        cin >> idx;
        cout << "efficient method: " << getIndexedUgly_1(idx) << endl;
        cout << "slow method: " << getIndexedUgly(idx) << endl;
    }
    return 0;
}
