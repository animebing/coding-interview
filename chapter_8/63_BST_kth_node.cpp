struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int num):val(num), left(NULL), right(NULL) {}
};


TreeNode *kthNodeCore(TreeNode *node, int &k) {
    if (!node) return NULL;
    TreeNode *res = NULL;
    res = kthNodeCore(node->left, k);
    if (!res) {
        if (k == 1) return node;
        k--;
        res = kthNodeCore(node->right, k);
    }
    return res;
}

TreeNode *KthNode(TreeNode *root, int k) {
    if (!root || k<=0) return NULL;
    return kthNodeCore(root, k);
}
