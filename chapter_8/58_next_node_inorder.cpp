struct TreeNode {
    int val;
    TreeNode *left, *right, *parent;
    TreeNode(int num):val(num), left(NULL), right(NULL), parent(NULL) {}
}


TreeNode *nextNode(TreeNode *node) {
    if (!node) return NULL;

    if (node->right) {
        TreeNode *tmp_right = node->right;
        while (tmp_right->left) tmp_right = tmp_right->left;
        return tmp_right;
    }

    while (node->parent && node==node->parent->right) node = node->parent;
    return node->parent;

}
