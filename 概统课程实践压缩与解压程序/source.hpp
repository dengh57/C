#ifndef SOURCE_HPP
#define SOURCE_HPP

#include <stack>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

//the node of Huffman tree 
struct TreeNode
{
    char ascii;
    int frequency;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : ascii(0), frequency(0), left(NULL), right(NULL) {}
    TreeNode(char asc, int fre) : ascii(asc), frequency(fre), left(NULL), right(NULL) {}
};

//Count the number of characters in the document
vector<int> calculate(string file_name);

//Construct Huffman Tree
TreeNode *build_tree(vector<int> num);

//Constructing Huffman codes
vector<vector<bool>> build_tree_number(TreeNode *root);

//zip
bool zip(string source_name, string zip_name);

//unzip 
bool unzip(string zip_name, string unzip_name);

#endif

