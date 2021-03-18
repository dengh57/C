#include "source.hpp"

vector<bool> num;

void Preorder(TreeNode *root, vector<vector<bool>> &reg)
{
    if (!root)
    {
        return;
    }
    if (!root->left && !root->right)
    {
        reg[root->ascii] = num;
        return;
    }
    num.push_back(0);
    Preorder(root->left, reg);
    num.pop_back();
    num.push_back(1);
    Preorder(root->right, reg);
    num.pop_back();
}

vector<vector<bool>> build_tree_number(TreeNode *root)
{
    vector<vector<bool>> reg(128);
    Preorder(root, reg);
    return reg;
}
