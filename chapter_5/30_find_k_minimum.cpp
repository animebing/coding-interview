#include <iostream>
#include <vector>
#include <set>

using namespace std;

int partition(vector<int> &data, int left, int right) {
    if (left >= right) return left;
    int middle = left + (right - left) / 2;
    swap(data[left], data[middle]);
    int pivot = left + 1;
    for (int i = left+1; i <= right; i++) {
        if (data[i] < data[left]) {
            swap(data[i], data[pivot]);
            pivot++;
        }
    }
    swap(data[left], data[pivot-1]);
    return pivot - 1;
}

vector<int> findKMinimum_0(vector<int> &data, int k) {
    int n = data.size();
    if (n == 0 || k <= 0 || n < k) return vector<int>();
    int left = 0, right = n-1;
    while (1) {
        int idx = partition(data, left, right);
        if (idx == k-1) break;
        else if (idx < k-1) left = idx + 1;
        else right = idx - 1;
    }
    return vector<int>(data.begin(), data.begin()+k);
}

// .end() is not the last element, but follow the last element
vector<int> findKMinimum_1(vector<int> &data, int k) {
    int n = data.size();
    if (n == 0 || k <= 0 || n < k) return vector<int>();
    multiset<int, greater<int>> k_set; // I can use greater<int>, then the first element is the largest one
    for (int i = 0; i < n; i++) {
        if (k_set.size() < k) k_set.insert(data[i]);
        else {
            if (data[i] < *k_set.begin()) { // the condition can be deleted here
                k_set.insert(data[i]);
                k_set.erase(k_set.begin());
            }
        }
    }
    return vector<int>(k_set.begin(), k_set.end());
}

int main(int argc, char **argv) {
    vector<int> data_0 = {4, 5, 1, 6, 2, 7, 3, 8};
    int k = 4;
    vector<int> res_0 = findKMinimum_0(data_0, k);
    for (int i = 0; i < k; i++) cout << res_0[i] << " ";
    cout << endl;
    
    
    vector<int> data_1 = {4, 5, 1, 6, 2, 7, 3, 8};
    vector<int> res_1 = findKMinimum_1(data_1, k);


    for (int i = 0; i < k; i++) cout << res_1[i] << " ";
    cout << endl;

    return 0;
}
