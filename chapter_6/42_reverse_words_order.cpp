#include <iostream>
#include <string>
using namespace std;

void myReverse(char *p_begin, char *p_end) {
    char tmp;
    while (p_begin < p_end) {
        tmp = *p_begin;
        *p_begin = *p_end;
        *p_end = tmp;
        p_begin++;
        p_end--;
    }
}

void reverseWordsOrder(char *p_data) {
    if (!p_data) return;
    
    char *p_begin = p_data, *p_end = p_data;
    while (*p_end != '\0') p_end++;
    p_end--;
    myReverse(p_begin, p_end); 
    p_begin = p_end = p_data;
    while (*p_begin != '\0') {
        if (*p_begin == ' ') {
            p_begin++;
            p_end++;
        } else if (*p_end == ' ' || *p_end =='\0' ) {
            myReverse(p_begin, p_end-1);
            p_begin = p_end;
        } else p_end++;
    }
}

void printStr(char *str) {
    while (*str != '\0') {
        cout << *str;
        str++;
    }
    cout << endl;
}

void stringLeftRotate(char *str, int step) {
    if (!str || step <= 0) return;
    int length = 0;
    char *tmp = str;
    while (*tmp != '\0') {
        length++;
        tmp++;
    }
    int actual_step = step % length;
    if (actual_step == 0) return;
    myReverse(str, str+actual_step-1);
    myReverse(str+actual_step, str+length-1);
    myReverse(str, str+length-1);
}

int main(int argc, char **argv) {

    char str[] = "hello world";
    stringLeftRotate(str, 15);
    //reverseWordsOrder(str);
    printStr(str);
    return 0;
}
