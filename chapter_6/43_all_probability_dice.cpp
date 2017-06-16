#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void helper(vector<long> &res, int sum, int left_dice, int dice) {
    if (left_dice == 0) {
        res[sum-dice]++;
        return;
    }

    for (int i = 1; i <= 6; i++) helper(res, sum+i, left_dice-1, dice);
}

void func1(int s) {
    if (s <= 0) return;
    vector<long> res(5*s+1, 0);
    helper(res, 0, s, s);
    long sum = 0;
    for (int i = 0; i <= 5*s; i++) sum += res[i];
    for (int i = 0; i <= 5*s; i++) cout << "value: " << i+s << ", prob: " << res[i]*1.0/sum << endl;
}

// dynamic method, use two arrays, the first one to store the result for n-1 dices, then the result for dice n can be got from previous one 
// like Fibonacci array
void func2(int s) {
    if (s <= 0) return;
    int max_value = 6;
    vector<vector<long>> res(2, vector<long>(s*max_value+1));
    int flag = 0;
    for (int i = 1; i <= max_value; i++) res[flag][i] = 1;

    for (int k = 2; k <= s; k++) {
        for (int i = k; i <= k*max_value; i++) {
            res[1-flag][i] = 0;
            for (int j = 1; j < i && j <= max_value; j++) res[1-flag][i] += res[flag][i-j];
        }
        flag = 1-flag;
    }

    double sum = pow((double)max_value, (double)s);
    for (int i = s; i <= max_value*s; i++) cout << "value: " << i << ", prob: " << res[flag][i]/sum << endl;
}
// the recursive method is much slower than the dynamic one, and when i output them together, the result of DP one will be outputed slowly
int main(int argc, char **argv) {
    int s;
    while (1) {
        cin >> s;
        func2(s);
        cout << "------------------------------------------------------" << endl;
        //func1(s);
    }
    return 0;
}
