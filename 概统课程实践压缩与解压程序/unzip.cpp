#include "source.hpp"

bool unzip(string zip_name, string unzip_name)
{
	short t;
    int num;
    int n = 0;
    char c;
    stack<int> s;
    ifstream infile;
    ofstream outfile;
    vector<int> freq;
    TreeNode *root, *p;
    //open zipfile
    infile.open(zip_name, ios::in | ios::binary);
    if (!infile.is_open())
    {
        return 0;
    }
    //read frequency
    for (int i = 0; i < 128; i++)
    {
        infile.read((char *)&num, sizeof(num));
        n += num;
        freq.push_back(num);
    }
    //build tree
    root = build_tree(freq);
    //open unzipfile
    outfile.open(unzip_name);
    //unzip
    p = root;
    while (n > 0)
    {
        infile.read((char *)&t, sizeof(t));
        num = t + 32768;
        for (int i = 0; i < 16; i++)
        {
            s.push(num % 2);
            num /= 2;
        }
        while (s.size() != 0)
        {
            if (s.top() == 0)
            {
                p = p->left;
            }
            else
            {
                p = p->right;
            }
            s.pop();
            if (p->left == NULL && p->right == NULL)
            {
                outfile << p->ascii;
                n--;
                if (n == 0)
                {
                    return 1;
                }
                p = root;
            }
        }
    }
    infile.close();
    outfile.close();
    return 1;
}
