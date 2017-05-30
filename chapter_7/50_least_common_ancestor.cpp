#include <vector>

struct TreeNode {
    int val;
    TreeNode *left, *right, *parent;
    
    TreeNode(int num):val(num), left(NULL), right(NULL), parent(NULL) {}
};
// ---------------------- ASSUME THAT node_1 and node_2 ARE IN THE TREE --------------------
// the tree is binary search tree

TreeNode *LCA_1(TreeNode *root, TreeNode *node_1, TreeNode *node_2) {
    if (!root || !node_1 || !node_2) return NULL;
    while (1) {
        if (node_1->val<root->val && node_2->val<root->val) root = root->left;
        else if (node_1->val>root->val && node_2->val>root->val) root = root->right;
        else return root;
    }
}

// the tree is not binary search tree, but there is the node pointing to the parent node
TreeNode *LCA_2(TreeNode *node_1, TreeNode *node_2) {
    if (!node_1 || !node_2) return NULL;

    int len_1 = 1, len_2 = 1;
    // find the length from current node to root node 
    TreeNode *tmp = node_1;
    while (tmp->parent) {
        len_1++;
        tmp = tmp->parent;
    }

    tmp = node_2;
    while (tmp->parent) {
        len_2++;
        tmp = tmp->parent;
    }
    // find the longer list, move forward first
    TreeNode *p_1 = node_1, *p_2 = node_2;
    if (len_1 < len_2) {
        int diff = len_2 - len_1;
        while (diff-->0) p_2 = p_2->parent;
    } else if (len_1 > len_2) {
        int diff = len_1 - len_2;
        while (diff-->0) p_1 = p_1->parent;
    }
    // move forward together, the first common node is what I need
    while (p_1 != p_2) {
        p_1 = p_1->parent;
        p_2 = p_2->parent;
    }
    
    return p_1;
}

// there is no the node pointing to the parent
bool findPath(TreeNode *root, vector<TreeNode *> &path, TreeNode *des) {
    if (!root) return false;
    path.push_back(root);
    if (root == des) return true;
    // here maybe more than 2 children
    if (findPath(root->left, path, des)) return true;
    if (findPath(root->right, path, des)) return true;
    path.pop_back();
    return false;
}

TreeNode *LCA_3(TreeNode *root, TreeNode *node_1, TreeNode *node_2) {
    // find the path from the root node to current node
    if (!root || !node_1 || !node_2) return NULL;

    vector<TreeNode *> path_1, path_2;
    findPath(root, path_1, node_1);
    findPath(root, path_2, node_2);
    TreeNode *res = NULL;
    for (int i = 0; i < path_1.size() && i < path_2.size(); i++) {
        if (path_1[i] == path_2[i]) res = path_1[i];
        else break;
    }
    return res;
}

// the whole tree will be visited 
TreeNode *LCA_4Core(TreeNode *root, TreeNode *node_1, TreeNode *node_2) {
    if (!root || root==node_1 || root==node_2) return root;
    TreeNode *left = LCA_4Core(root->left, node_1, node_2);
    TreeNode *right = LCA_4Core(root->right, node_1, node_2);
    return !left ? right : (!right ? left : root);
}
TreeNode *LCA_4(TreeNode *root, TreeNode *node_1, TreeNode *node_2) {
    if (!root || !node_1 || !node_2) return NULL;
    return LCA_4Core(root, node_1, node_2);
}
