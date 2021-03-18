#include "source.hpp"
int main()
{
    cout << "压缩时输入命令：ziptxt 源文件名 压缩文件名" << endl;
    cout << "解压时输入命令：unziptxt 压缩文件名 解压后文件名" << endl;
    string op;
    string name1;
    string name2;
    cin >> op >> name1 >> name2;

    if (op == "ziptxt")
    {
        if (!zip(name1, name2))
        {
            cout << "打开源文件失败" << endl;
        }
        else
        {
            cout << "压缩完成" << endl;
        }
    }
    else if (op == "unziptxt")
    {
        if (!unzip(name1, name2))
        {
            cout << "打开压缩文件失败" << endl;
        }
        else
        {
            cout << "解压完成" << endl;
        }
    }
    else
    {
        cout << "指令错误" << endl;
    }

    return 0;
}
