#include "source.hpp"
int main()
{
    cout << "ѹ��ʱ�������ziptxt Դ�ļ��� ѹ���ļ���" << endl;
    cout << "��ѹʱ�������unziptxt ѹ���ļ��� ��ѹ���ļ���" << endl;
    string op;
    string name1;
    string name2;
    cin >> op >> name1 >> name2;

    if (op == "ziptxt")
    {
        if (!zip(name1, name2))
        {
            cout << "��Դ�ļ�ʧ��" << endl;
        }
        else
        {
            cout << "ѹ�����" << endl;
        }
    }
    else if (op == "unziptxt")
    {
        if (!unzip(name1, name2))
        {
            cout << "��ѹ���ļ�ʧ��" << endl;
        }
        else
        {
            cout << "��ѹ���" << endl;
        }
    }
    else
    {
        cout << "ָ�����" << endl;
    }

    return 0;
}
