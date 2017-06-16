#include <iostream>
#include <vector>

using namespace std;

int firstKIndex(vector<int> &data, int val) {
    int n = data.size();
    int left = 0, right = n-1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        int tmp = data[middle];
        if (tmp == val) {
            if ((middle > 0 && data[middle-1] != val) || middle == 0) return middle;
            else right = middle - 1;
        } else if (tmp > val) right = middle - 1;
        else left = middle + 1;
    }
    return -1; // val is not existed in data
}

int lastKIndex(vector<int> &data, int val) {
    int n = data.size();
    int left = 0, right = n-1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        int tmp = data[middle];
        if (tmp == val) {
            if ((middle < n-1 && data[middle+1] != val) || middle == n-1) return middle;
            else left = middle + 1;
        } else if (tmp > val) right = middle - 1;
        else left = middle + 1;
    }
    return -1;
}

int getNumOfK(vector<int> data, int val) {
    if (data.size() == 0) return -1;
    int left = firstKIndex(data, val);
    if (left == -1) return -1; 
    int right = lastKIndex(data, val);
    return right - left + 1;
}

// the lowerBound is to find the first element that is larger than or equal to val, which is not perfectly proper here
int lowerBound(vector<int> &data, int val) {
    int n = data.size();
    int left = 0, right = n-1;
    while (left < right) {
        int middle = left + (right - left) / 2;
        int tmp = data[middle];
        if (tmp < val) left = middle+1;
        else right = middle;
    }
    if (data[left] < val) return -1;
    else return left;
}

int getNumOfKMe(vector<int> &data, int val) {
    if (data.size() == 0) return -1;
    int left = lowerBound(data, val);
    if (left == -1 || data[left] != val) return -1; // when left == -1, all elements are less than val, when data[left] != val, then all elements are larger than val or val is not existed
    int right = lowerBound(data, val+1); // right is the index of the elements following val, but larger than val
    if (right == -1) right = data.size(); // the last element is val, so all elements are less than val+1
    return right - left;
}

int main(int argc, char **argv) {
    vector<int> data = {1, 2, 3, 3, 3, 6};
    int val = 4;
    int num_0 = getNumOfK(data, val);
    if (num_0 == -1) cout << "there is no " << val << endl;
    else cout << "method 0: " << num_0 << endl;
    
    int num_1 = getNumOfKMe(data, val);
    if (num_1 == -1) cout << "there is no " << val << endl;
    else cout << "method 1: " << num_1 << endl;
    return 0;
}
