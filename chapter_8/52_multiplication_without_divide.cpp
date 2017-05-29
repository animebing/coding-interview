#include <vector>
vector<int> multiply(const vector<int> input) {
    int n = input.size();
    if (n == 0) return vector<int>();
    vector<int> res(n, 0);
    res[0] = 1;
    for (int i = 1; i < n; i++) res[i] = res[i-1] * input[i-1];

    int tmp = 1;
    for (int i = n-2; i >= 0; i++) {
        tmp *= input[i+1];
        res[i] *= tmp;
    }

    return res;
}
