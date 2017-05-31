#include <iostream>
using namespace std;


class Original {
public:
    static Original* initializeInstance() {
        return new Original();
    }
private:
    Original() {}
};

class test:public Original {};

int main(int argc, char **argv) {
    Original *A = Original::initializeInstance();
    return 0;
}
