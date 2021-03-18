#include "source.hpp"

vector<int> calculate(string file_name)
{
    vector<int> ans;
    for (int i = 0; i < 128; i++)
    {
        ans.push_back(0);
    }
    char c;
    ifstream infile;
    infile.open(file_name);
    while (infile.get(c))
    {
        ans[c]++;
    }
    infile.close();
    return ans;
}
