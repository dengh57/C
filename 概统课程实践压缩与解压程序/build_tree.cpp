#include "source.hpp"

bool comp(TreeNode *t1, TreeNode *t2)
{
    return t1->frequency < t2->frequency;
}

TreeNode *build_tree(vector<int> num)
{
    vector<TreeNode *> tree(128);
    for (int i = 0; i < tree.size(); ++i)
    {
        tree[i] = new TreeNode(i, num[i]);
    }
    while (tree.size() != 1)
    {
        sort(tree.begin(), tree.end(), comp);
        TreeNode *temp = new TreeNode(0, tree[0]->frequency + tree[1]->frequency);
        temp->left = tree[0];
        temp->right = tree[1];
        tree.erase(tree.begin());
        tree[0] = temp;
    }
    return tree[0];
}
