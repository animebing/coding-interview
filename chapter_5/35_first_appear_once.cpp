#include <iostream>
#include <string>
#include <vector> 
#include <climits>  // for INT_MAX
using namespace std;

// count the occurrance for each character, then access the string again to find the 
// first character who appears only once
char find_0(string str) {
    
    int n = str.size();
    if (n == 0) return '\0';
    vector<int> cnt(128, 0);
    for (char c : str) cnt[c]++;

    for ( char c : str) {
        if (cnt[c] == 1) return c;
    }

    return '\0';
}

// idx here is different from above cnt, here idx will record the index of all characters appearing once, 
// index == -1, not appear; index == -2, appear more than once; index >= 0, appear once
// then find the smallest index from all characters appear once
char find_1(string str) {
    int n = str.size();
    if (n == 0) return '\0';
    vector<int> idx(128, -1);
    for (int i = 0; i < n; i++) {
        if (idx[str[i]] == -1) idx[str[i]] = i;
        else idx[str[i]] = -2;
    }
    
    char res = '\0';
    int min_idx = INT_MAX;
    for (int i = 0; i < 128; i++) {
        if (idx[i] >= 0) {
            if (idx[i] < min_idx) {
                min_idx = idx[i];
                res = (char) i;
            }
        }
    }

    return res;
}

// the first stage of two methods are the same, but in stage 2, the fisrt method needs to access the whole string from the begining, 
// when the string is very long or the string is a stream, it will be time-consuming, but for the second method, no matter how long
// the string is or whether it is a stream, only the length-128 vector is accessed, it will be more efficient.

int main(int argc, char **argv) {
    string str;
    while (1) {
        cin >> str;
        cout << "method 0: " << find_0(str) << ", method 1: " << find_1(str) << endl;
    }
    return 0;
}
