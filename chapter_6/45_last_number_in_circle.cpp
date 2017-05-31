#include <iostream>
#include <list>
using namespace std;

int lastOne(int n, int m) {
    if (n < 1 || m < 1) {
        return -1;
    }
    list<int> numbers;
    for (int i = 0; i < n; i++) numbers.push_back(i);
    list<int>::iterator cur = numbers.begin();
    while (numbers.size() != 1) {
        int t = m-1;
        while (t-->0) {
            cur++;
            if (cur == numbers.end()) cur = numbers.begin();
        }
        cur = numbers.erase(cur);
        if (cur == numbers.end()) cur = numbers.begin();
    }
    return *cur;
}

int lastOneNew(int n, int m) {
    if (n < 1 || m < 1) return -1;
    int last = 0;
    for (int i = 2; i <= n; i++) last = (last+m) % i;
    return last;
}
int main(int argc, char **argv) {
    int n, m;
    while (1) {
        cin >> n >> m;
        cout << lastOneNew(n, m) << " " << lastOne(n, m) << endl;
    }
    return 0;
}
