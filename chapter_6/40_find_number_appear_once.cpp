void findNumberAppearOnce(vector<int> data) {
    int n = data.size();
    if (n == 0) return;
    int nor_res = 0;
    for (int each : data) nor_res ^= each;
    int judge = nor_res & (-nor_res);
    int a = 0;
    for (int each : data) {
        if (each & judge != 0) a ^= each;
    }

    int b = nor_res ^ a;
    cout << a << " " << b << endl;
}
