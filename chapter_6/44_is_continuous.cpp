bool isContinuous(vector<int> cards) {
    sort(cards.begin(), cards.end());
    int num_zero = 0;
    int i = 0;
    for (; i < cards.size(); i++) {
        if (cards[i] == 0) num_zero++;
        else break;
    }
    int step = 0;
    for (; i < cards.size()-1; i++) {
        if (cards[i] == cards[i+1]) return false;
        else step += cards[i+1] - cards[i] - 1;
    }

    if (step <= num_zero) return true;
    else return false;
}
