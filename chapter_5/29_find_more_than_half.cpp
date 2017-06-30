#include <unordered_map>  // for unordered_map
#include <vector> 

bool is_valid_input = false;
bool is_more_than_half = false;
int findMoreThanHalf_0(vector<int> &data) {
    int n = data.size();
    if (n == 0) {
        is_valid_input = false;
        return -1;
    }

    unordered_map<int, int> cnt;
    for (int num : data) {
        cnt[num]++;
        if (cnt[num] > n/2) {
            is_more_than_half = true;
            return num;
        }
    }

    is_more_than_half = false;
    return -1;
}


int partition(vector<int> &data, int left, int right) {
    if (left >= right) return left;
    int middle = left + (right - left) / 2;
    swap(data[middle], data[left]);
    int pivot = left + 1;
    int (int i = left + 1; i <= right; i++) {
        if (data[i] < data[left]) {
            swap(data[i], data[pivot]);
            pivot++;
        }
    }

    swap(data[left], data[pivot-1]);
    return pivot - 1;
}

bool checkMoreThanHalf(vector<int> &data, int num) {
    int cnt = 0;
    int n = data.size();
    for (int each : data) {
        if (each == num) cnt++;
    }

    if (cnt > n / 2) return true;
    else return false;
}

int findMoreThanHalf_1(vector<int> &data) {
    int n = data.size();
    if (n == 0) {
        is_valid_input = false;
        return -1;
    }

    int middle = n / 2;
    int left = 0, right = n-1;
    while (1) {
        int idx = partition(data, left, right);
        if (idx == middle) break;
        else if (idx > middle) right = idx - 1;
        else left = idx + 1;
    }

    if (checkMoreThanHalf(data, data[middle])) {
        is_more_than_half = true;
        return data[middle];
    } else {
        is_more_than_half = false;
        return -1;
    }
}

int findMoreThanHalf(vector<int> &data) {
    int n = data.size();
    if (n == 0) {
        is_valid_input = false;
        return -1;
    }

    int res = data[0];
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (cnt == 0) {
            res = data[i];
            cnt = 1;
            continue;
        }

        if (data[i] == res) cnt++;
        else cnt--;
    }

    if (checkMoreThanHalf(data, res)) {
        is_more_than_half = true;
        return res;
    } else {
        is_more_than_half = false;
        return -1
    }
}

// during computation, first consider is_valid_input, then is_more_than_half, 
// if they both are true, then the returning value is the once more than half
