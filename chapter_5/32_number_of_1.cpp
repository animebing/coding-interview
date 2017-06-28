#include <iostream>
#include <string>
#include <cmath>

using namespace std;
int One(int num) {
    int res = 0;
    while (num) {
        int tmp = num % 10;
        if (tmp == 1) res++;
        num /= 10;
    }
    return res;
}

// time complexity O(n)
long findNumberOfOne(int n) {
    if (n <= 0) return 0;
    long res = 1;
    for (int i = 2; i <= n; i++) res += One(i);
    return res;
}

// time complexity O(1)
long findNumberOfOneCore(string str) {
    int n = str.size();
    if (n == 0) return 0;
    if (n == 1 && str[0] == 0) return 0;
    if (n == 1 && str[0] != 0) return 1;
    int first = str[0] - '0';
    long num_0;
    if (first == 1) num_0 = stol(str.substr(1)) + 1;
    else num_0 = int(pow(10, n-1));

    long num_1 = first * (n-1) * int(pow(10, n-2));
    long num_2 = findNumberOfOneCore(str.substr(1));
    return num_0 + num_1 + num_2;
}

long findNumberOfOne_1(int n) {
    if (n <= 0) return 0;
    string n_str = to_string(n);
    return findNumberOfOneCore(n_str);
}

int main(int argc, char **argv) {
    int n;
    while (1) {
        cin >> n;
        long res_1 = findNumberOfOne_1(n);
        cout << res_1 << endl;
        long res_0 = findNumberOfOne(n);
        cout << res_0 << endl;
    }
    return 0;
}
