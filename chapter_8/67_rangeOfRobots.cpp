int getSum(int num) {
    int sum = 0;
    while (num) {
        sum += num%10;
        num /= 10;
    }
    return sum;
}

int movingCountsCore(int rows, int cols, int row, int col, bool *visited, int threshold) {
    int cnt = 0;
    if (row>=0 && row<rows && col>=0 && col<cols && !visited[row*cols+col] && getSum(row)+getSum(col)<=threshold) {
        visited[row*cols+col] = true;
        cnt = 1+ movingCountsCore(rows, cols, row, col-1, visited, threshold) + movingCountsCore(rows, cols, row-1, col, visited, threshold) + 
            movingCountsCore(rows, cols, row, col+1, visited, threshold) + movingCountsCore(rows, cols, row+1, col, visited, threshold);
    }
    return cnt;
}

int movingCounts(int rows, int cols, int threshold) {
    bool *visited = new bool[rows*cols];
    for (int i = 0; i < rows*cols; i++) visited[i] = false;
    int cnt = movingCountsCore(rows, cols, 0, 0, visited, threshold);
    delete[] visited;
    return cnt;
}
