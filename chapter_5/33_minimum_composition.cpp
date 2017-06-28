#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;
string findMinimumComposition(vector<int> &data) {
    if (data.size() == 0) return "";
    sort(data.begin(), data.end(), [](int a, int b) {return to_string(a)+to_string(b) < to_string(b) + to_string(a);});
    string res;
    for ( int num : data) res += to_string(num);
    return res;
}

void quickSort(vector<int> &data, int left, int right) {
    if (left >= right) return;
    int middle = left + (right - left) / 2;
    swap(data[left], data[middle]);

    int pivot = left + 1;
    for (int i = left + 1; i <= right; i++) {
        if (to_string(data[i]) + to_string(data[left]) < to_string(data[left]) + to_string(data[i])) {
            swap(data[pivot], data[i]);
            pivot++;
        }
    }

    swap(data[left], data[pivot-1]);
    quickSort(data, left, pivot-2);
    quickSort(data, pivot, right);
}

string findMinimumComposition_1(vector<int> &data) {
    if (data.size() == 0) return "";
    quickSort(data, 0, data.size() - 1);
    string res;
    for (int num : data) res += to_string(num);
    return res;
}

// the order of original data array will be changed, if not, I need to copy the original data
int main(int argc, char **argv) {
    vector<int> data_0 = {23};
    vector<int> data_1 = {23};
    string str_0 = findMinimumComposition(data_0);
    string str_1 = findMinimumComposition_1(data_1);
    cout << str_0 << endl;
    cout << str_1 << endl;
    return 0;
}
