#include <iostream>
#include <vector>
using namespace std;

bool findDuplicate(vector<int> &input, int &res) {
    int n = input.size();
    if (n == 0) return false;
    for (int i = 0; i < n; i++) {
        while (input[i] != i) {
            if (input[i] == input[input[i]]) {   
                res = input[i];
                return true;
            }
            swap(input[i], input[input[i]]);
        }
    }
    return false;
}

int main(int argc, char **argv) {
    vector<int> input;
    int res;
    if (findDuplicate(input, res)) cout << res << endl;
    else cout << "no duplicate" << endl;
    return 0;
}
