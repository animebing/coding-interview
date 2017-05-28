#include <deque>
#include <vecotr>

vector<int> maxInWindows(vector<int> nums, unsigned k) {
    vector<int> res;
    int n = nums.size();
    if (k>0 && n>=k) {
        deque<int> dq_max;
        for (int i = 0; i < k; i++){
            while (!dq_max.empty() && nums[i]>nums[dq_max.back()]) dq_max.pop_back();
            dq_max.push_back(i);
        }
        for (int i = 0; i < n; i++) {
            res.push_back(nums[dq_max.front()]);
            while (!dq_max.empty() && nums[i]>nums[dq_max.back()]) dq_max.pop_back();
            dq_max.push_back(i);
            if (dp_max.front() <= i-k) dp_max.pop_front();
        }
        res.push_back(nums[dp_max.front()]);
    }
    return res;
}
