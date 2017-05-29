#include <iostream>
#include <string>
using namespace std;

bool matchCore(char *str, char *pattern) {
    if (*str=='\0' && *pattern=='\0') return true;
    if (*str!='\0' && *pattern=='\0') return false;

    if (*(pattern+1) == '*') {
        if (*str==*pattern || (*str!='\0' && *pattern=='.')) {
            // the pattern only appear once, or the pattern appear more than once, or the pattern is ignored
            return matchCore(str+1, pattern+2) || matchCore(str+1, pattern) || matchCore(str, pattern+2);
        } else return matchCore(str, pattern+2); // the patter has to be ignored
    }

    if (*str==*pattern || (*str!='\0' && *pattern=='.')) return matchCore(str+1, pattern+1);

    return false;
}



bool match(char *str, char *pattern) {
    if (!str || !pattern) return false;
    return matchCore(str, pattern);
}

int main(int argc, char **argv) {
    string str, pattern;
    while (1) {
        cin >> str >> pattern;
        if (match((char *)str.c_str(), (char *)pattern.c_str())) cout << "match" << endl;
        else cout << "not match" << endl;
    }
    return 0;
}
