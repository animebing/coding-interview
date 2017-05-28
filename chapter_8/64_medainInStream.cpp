#include <algorithm>
#include <exception>

template <typename T>
class DynamicsArray {
public:
    void Insert(T value);
    T getMedian();
private:
    vector<T> min;
    vector<T> max;
};


void DynamicsArray<T>::Insert(T value) {
    int cur_size = min.size() + max.size();
    if (cur_size & 1 == 0) {
        if (max.size()>0 && value<max[0]) {
            // the order of push_heap or pop_heap is not fixed, the order can be changed
            max.push_back(value);
            push_heap(max.begin(), max.end(), less<T>());
            int tmp = max[0];
            pop_heap(max.begin(), max.end(), less<T>());
            max.pop_back();
        }

        min.push_back(tmp);
        push_heap(min.begin(), min.end(), greater<T>());
    } else {
        if (min.size() && value > min[0]) {
            min.push_back(value);
            push_heap(min.begin(), min.end(), greater<T>());
            int tmp = min[0];
            pop_heap(min.begin(), min.end(), greater<T>());
            min.pop_back();
        }
        max.push_back(tmp);
        push_heap(max.begin(), max.end(), less<T>());
    }
}

T DynamicsArray<T>::getMedian() {
    int cur_size = min.size() + max.size();
    if (cur_size == 0) throw exception("no value is available"); 

    if (cur_size & 1 == 0) return max[0] + (min[0]-max[0])/2;
    else min[0];
}


