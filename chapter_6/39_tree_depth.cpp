#include <algorithm>  // for max
#include <cstdlib> // for abs, if fabs, then <cmath>


struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int num):val(num), left(NULL), right(NULL) {}
}

int treeDepth(TreeNode *root) {
    if (!root) return 0;
    return max(treeDepth(root->left), treeDepth(root->right)) + 1;
}

bool helper_0(TreeNode *root) {
    if (!root) return true;
    int l_depth = treeDepth(root->left);
    int r_depth = treeDepth(root->right);
    if (abs(l_depth - r_depth) > 1) return false;
    return helper_0(root->left) && helper_0(root->right);
}

bool helper_1(TreeNode *root, int &depth) {
    if (!root) {
        depth = 0;
        return true;
    }

    int l_depth, r_depth;
    if (helper_1(root->left, l_depth) && helper_1(root->right, r_depth)) {
        if (abs(l_depth - r_depth) <= 1) {
            depth = max(l_depth, r_depth) + 1;
            return true;
        }
    }
    return false;
}
bool isBalanced(TreeNode *root) {
    if (!root) return false;
    return helper_0(root);
    // int depth;
    // return helper_1(root, depth);
}




