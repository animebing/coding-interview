vector<int> findNumbersWithSum(vector<int> data, int s) {
    int n = data.size();
    vector<int> res;
    if (n == 0) return res;
    int left = 0, right = n-1;
    while (left < right) {
        int sum = data[left] + data[right];
        if (sum == s) {
            res.push_back(data[left]);
            res.push_back(data[right]);
            break;
        } else if (sum < s) left++;
        else right--;
    }
    return res;
}

void printContinuousSequence(int small, int big) {
    for (int i = small; i <= big; i++) cout << i << " ";
    cout << endl;
}

void findContinuousSequence(int s) {
    if (s < 3) return;
    int small = 1, big = 2;
    int sum = small + big;
    int middle = (1 + s) / 2;
    while (small < middle) {
        if (sum == s) printContinuousSequence(small, big);
        while (sum > s && small < middle) {
            sum -= small;
            small++;
            if (sum == s) printContinuousSequence(small, big);
        }
        big++;
        sum += big;
    }
}
