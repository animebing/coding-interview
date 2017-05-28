bool isBalancedCoro(TreeNode *node_1, TreeNode *node_2) {
    if (!node_1 && !node_2) return true;

    if (node_1 || node_2) return false;

    if (node_1->val != node_2->val) return false;
    return isBalancedCore(node_1->left, node_2->right) && isBalancedCore(node_1->right, node_2->left);
}

bool isBalanced(TreeNode *root) {
    if (!root) return false;
    return isBalancedCore(root->left, root->right);
}
