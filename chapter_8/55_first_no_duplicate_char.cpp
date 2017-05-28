#include <climits>

class CharStatistics {
public:
    CharStatistics():idx(0) {
        for (int i = 0; i < 128; i++) char_stat[i] = -1;
    }

    void insert(char ch) {
        if (char_stat[ch] == -1) char_stat[ch] = idx;
        else if (char_stat[ch] >= 0) char_stat[ch] = -2;
        idx++;
    }

    char firstAppearOnce() {
        char res = '';
        char min_idx = INT_MAX;
        for (int i = 0; i < 128; i++) {
            if (char_stat[i] >= 0) {
                if (char_stat[i] < min_idx) {
                    min_idx = char_stat[ch];
                    res = (char)i;
                }
            }
        }
        return res;
    }
private:
    int char_stat[128];
    int idx;
}
