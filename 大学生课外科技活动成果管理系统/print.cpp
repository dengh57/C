#include "headfile.h"

void InitialInterface() {
	SetConsoleTitle("��ѧ������Ƽ���ɹ�����ϵͳ"); 
	cout << "--------------------��ѧ������Ƽ���ɹ�����ϵͳ--------------------" << endl;
	cout << endl;
	cout << "                                1 ��ʦ" << endl;
	cout << "                                2 ѧ��" << endl; 
	cout << "                                3 �˳�" << endl; 
	cout << endl;
	cout << "                                ������������ݻ��˳�ϵͳ<1-3>��"; 
}

void PrintTeacher() {
	cout << "--------------------��ѧ������Ƽ���ɹ�����ϵͳ--------------------" << endl;
	cout << endl;
	cout << "                                ��ʦ���ܣ�" << endl;
	cout << endl;
	cout << "                                1 �����Ƽ��" << endl; 
	cout << "                                2 ��ʾ���пƼ��" << endl;
	cout << "                                3 ɾ�����пƼ��" << endl; 
	cout << "                                4 ɾ��ĳ��Ƽ��" << endl;
	cout << "                                5 �鿴ĳ��Ƽ���ɹ�ѧ���ɼ�" << endl;
	cout << "                                6 ��ĳ��Ƽ��ɹ�ѧ���ɼ����ɼ���������" << endl; 
	cout << "                                7 ����" << endl; 
	cout << endl;
	cout << "                                ����������ѡ��򷵻���һ��<1-7>��"; 
} 

void PrintStudent(vector<string>& s) {
	cout << "--------------------��ѧ������Ƽ���ɹ�����ϵͳ--------------------" << endl;
	cout << endl;
	cout << "                                �Ƽ��ɹ����ͣ�" << endl;
	cout << endl;
	for(int i = 0; i < s.size(); ++i) {
		cout << "                                " << i + 1 << " " << s[i] << endl;
	}
	cout << "                                " << s.size() + 1 << " ����" << endl; 
	cout << endl;
	cout << "                                ��������Ҫ��д�ĿƼ��ɹ����߷�����һ��<1-" << s.size() + 1 << ">��";
}

void Print1(vector<string>& s) {
	cout << "���Ƽ�����͡���";
	for(int i = 0; i < s.size(); ++i) {
		cout << s[i] << "  ";
	}
	cout << endl;
}

