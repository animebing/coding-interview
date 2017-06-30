#include <iostream>
#include <string>
#include <vector>

using namespace std;

void findAllPermutationCore(string str, string tmp, vector<bool> &visit) {
    if (tmp.size() == str.size()) {
        cout << tmp << endl;
        return;
    }

    for (int i = 0; i < str.size(); i++) {
        if (visit[i]) continue;
        tmp.push_back(str[i]);
        visit[i] = true;
        findAllPermutationCore(str, tmp, visit);
        tmp.pop_back();
        visit[i] = false;
    }
}

void findAllPermutation(string str) {
    if (str.size() == 0) return;
    string tmp;
    vector<bool> visit(str.size(), false);

    findAllPermutationCore(str, tmp, visit);
}

void findAllPermutationCore_1(string &str, int idx) {
    if (idx == str.size()) {
        cout << str << endl;
        return;
    }

    for (int i = idx; i < str.size(); i++) {
        swap(str[i], str[idx]);
        findAllPermutationCore_1(str, idx+1);
        swap(str[i], str[idx]);
    }
}
void findAllPermutation_1(string str) {
    if (str.size() == 0) return;
    findAllPermutationCore_1(str, 0);
}
int main(int argc, char **argv) {
    string str;
    while (1) {
        cin >> str;
        findAllPermutation_1(str);
    }
    return 0;
}
