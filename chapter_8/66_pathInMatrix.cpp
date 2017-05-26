bool hasPath(char *matrix, int rows, int cols, int row, int col, bool *visited, int cur_pos, char *str) {
    if (str[cur_pos] = '\0') return true;
    bool res = false;
    int idx = row*cols + col;
    if (row>=0 && row<rows && col>=0 && col<cols && !visited[idx] && matrix[idx]==str[cur_pos]) {
        visited[idx] = true;
        res = hasPath(matrix, rows, cols, row, col-1, visited, cur_pos+1, str) || hasPath(matrix, rows, cols, row-1, col, visited, cur_pos+1, str) || 
            hasPath(matrix, rows, cols, row, col+1, visited, cur_pos+1, str) || hasPath(matrix, rows, cols, row+1, col, visited, cur_pos+1, str);

        if (!res) visited[idx] = false;
    }
    return res;
}

bool hasPath(char *matrix, int rows, int cols, char *str) {
    if (!matrix || rows<=0 || cols<=0 || !str) return false;
    bool *visited = new bool[rows*cols];
    for (int i = 0; i < rows*cols; i++) visited[i] = false;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int cur_pos = 0;
            if (hasPath(matrix, rows, cols, i, j, visited, cur_pos, str)) return true;
        }
    }
    return false;
}
