// 1+2+...+n without for, while, if else, swicth, ?
#include <iostream>
using namespace std;

class accumulate {
public:
    accumulate() {
        n++;
        sum += n;
    }
    static void reset() {
        n = 0;
        sum = 0;
    }
    static int getSum() {
        return sum;
    }
private: 
    static int n, sum;
};
// here is the static member initailization
int accumulate::n = 0;
int accumulate::sum = 0;

int main(int argc, char **argv) {
    int t = 10;
    //accumulate::reset();
    accumulate *tmp = new accumulate[t];
    cout << accumulate::getSum() << endl;
    return 0;
}
