#include "source.hpp"

//convert the binary code of each character into a decimal number
int to_decimal(vector<bool> q)
{
    int re = 0;
    for (int i = 0; i < q.size(); i++)
    {
        re = re * 2 + q[i];
    }
    return re;
}

bool zip(string source_name, string zip_name)
{
    ifstream myfile(source_name);
    ofstream outfile(zip_name, ios::out | ios::binary);

    //If the file fails to read, an error signal is returned
    if (!myfile.is_open() || !outfile.is_open())
    {
        return false;
    }

    vector<int> freq = calculate(source_name);
    TreeNode *root = build_tree(freq);
    vector<vector<bool>> code = build_tree_number(root);

    //Put the number of times each character appears in the source file at the top of the zip file to build a tree when unzip
    for (int i = 0; i < freq.size(); i++)
    {
        int s = freq[i];
        outfile.write((char*)&s, sizeof(s));
    }

    char ch;
    vector<bool> q;

    //Read each character in the file, and save their Huffman encoding 16 bits as a short into the zip file
    while (!myfile.eof())
    {
        myfile.get(ch);
        vector<bool> tmp = code[ch];
        for (int i = 0; i < tmp.size(); i++)
        {
            q.push_back(tmp[i]);
            if (q.size() == 16)
            {
                int n = to_decimal(q);
                q.clear();
                short s = n - 32768;
                outfile.write((char*)&s, sizeof(s));
            }
        }
    }

    //If the last character is less than 16 bits, use 0 to complete
    if(q.size() < 16 && q.size() > 0){
        int t = q.size();
        for(int i = 0; i < 16 - t; i++){
            q.push_back(false);
        }
        int n = to_decimal(q);
        q.clear();
        short s = n - 32768;
        outfile.write((char*)&s, sizeof(s));
    }
    myfile.close();
    outfile.close();
    return true;
}
