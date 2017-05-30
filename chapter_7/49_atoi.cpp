#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

bool is_valid = false;
long getNumber(const char *&str) {
    long num = 0;
    while (*str!='\0' && *str>='0' && *str<='9') {
        num = num*10 + *str-'0';
        str++;
    }
    return num;
}
int atoiMy(const char *str) {
    is_valid = true;

    if (!str) {
        is_valid = false;
        return 0;
    }
    int sign = 1;
    if (*str == '+') str++;
    else if (*str == '-') {
        sign = -1;
        str++;
    }

    if (*str == '\0') {
        is_valid = false;
        return 0;
    }

    char *tmp = (char *)str;
    long res = getNumber(str);
    if (tmp == str) {
        is_valid = false;
        return 0;
    }
    res *= sign;
    if (res > INT_MAX || res < INT_MIN) is_valid = false;
    return (int)res;
}


int main(int argc, char **argv) {
    string a;
    while (1) {
        cin >> a;
        cout << "atoi: " << atoi(a.c_str()) << endl;
        cout << "my atoi: " << atoiMy(a.c_str()) << endl;
        cout << "valid: " << is_valid << endl;
    }
    return 0;
}
