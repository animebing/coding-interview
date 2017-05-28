void printZigZagTree(TreeNode *root) {
    if (!root) return;

    stack<TreeNode *> s_level[2];
    int cur = 0, next = 1;
    s_level[cur].push(root);
    while (!s_level[cur].empty() || !s_level[next].empty()) {
        TreeNode *tmp = s_level[cur].top();
        s_level[cur].pop();
        cout << tmp->val << " ";
        if (cur == 0) {
            if (tmp->left) s_level[next].push(tmp->left);
            if (tmp->right) s_level[next].push(tmp->right);
        } else {
            if (tmp->right) s_level[next].push(tmp->right);
            if (tmp->left) s_level[next].push(tmp->left);
        }

        if (s_level[cur].empty()) {
            cout << endl;
            cur = 1 - cur;
            next = 1- next;
        }
    }
}
