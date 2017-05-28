#include <queue>

void linebylineTreePrint(TreeNode *root) {
    if (!root) return;

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        while (n-->0) {
            TreeNode *tmp = q.front();
            q.pop();
            cout << tmp->val << " ";
            if (tmp->left) q.push(tmp->left);
            if (tmp->right) q.push(right);
        }
        cout << endl;
    }
}
