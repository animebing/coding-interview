#include <string>
#include<sstream>

string serialize(TreeNode *root) {
    if (!root) return "$,";
    res += to_string(root->val)+",";
    res += serialize(root->left);
    res += serialize(root->right);
    return res;
}

bool checkNum(istringstream &str, int &num) {
    string tmp;
    getline(str, tmp, ',');
    if (tmp == "$") return false;
    
    num = stoi(tmp);
    return true;
}

TreeNode *deSerialize(istringstream &str) {
    int num;
    TreeNode *res = NULL;
    if (checkNum(str, num)) {
        res = new TreeNode(num);
        res->left = deSerialize(str);
        res->right = deSerialize(str);
    }
    return res;
}




