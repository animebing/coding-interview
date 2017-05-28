#include <iostream>
using namespace std;

// go throung an integer
void getNumber(string str, int &idx) {
    for (; idx < str.size(); idx++) {
        if (str[idx]<'0' || str[idx]>'9') break;
    }
}
// check whether there is only sign and integer
bool checkNumber(string str, int idx) {
   if (idx == str.size()) return false;
   if (str[idx]=='+' || str[idx]=='-') idx++;
   if (idx == str.size()) return false;
   getNumber(str, idx);
   if (idx == str.size()) return true;
   else return false;
}

bool isNumber(string str) {
    if (str.size() == 0) return false;
    int idx = 0;
    if (str[idx]=='+' || str[idx]=='-') idx++;
    if (idx == str.size()) return false;
    
    // I add flag_1 and flag_2 to avoid ".e" case, when there is '.', there is at least one integer before '.' or after '.'
    int tmp_idx = idx;
    bool flag_1 = false;
    getNumber(str, idx);
    flag_1 = tmp_idx==idx;
    

    if (idx != str.size()) {
        if (str[idx] == '.') {
            idx++;
            bool flag_2 = false;
            tmp_idx = idx;
            getNumber(str, idx);
            flag_2 = tmp_idx==idx;
            if (flag_1 && flag_2) return false;

            if (idx == str.size()) return true;
            if (str[idx]=='e' || str[idx]=='E') {
                idx++;
                if (checkNumber(str, idx)) return true;
                else return false;
            } else return false;
        }
        else {
            if (flag_1) return false;

            if (str[idx]=='e' || str[idx]=='E') {
                idx++;
                if (checkNumber(str, idx)) return true;
                else return false;
            } else return false;            
        }
    }
    
    return true;
}

int main() {
    string str;
    while (1) {
        cin >> str;
        if (isNumber(str)) cout << "is number" << endl;
        else cout << "not number" << endl;
    }
    return 0;
}
