#include "headfile.h"

int Detect1(char c) {
	while(c != '1' && c != '2' && c != '3') { //�����벻��1��2��3ʱ������ѭ�� 
		cout << endl;
		cout << "��������ѡ����ڣ����������롿\n\n" << endl;
		InitialInterface();	  
		cin >> c;
	}
	return (int)(c - '0'); //����������ѡ�� 
}

int Detect2(char c) {
	while(c != '1' && c != '2' && c != '3' && c != '4' && c != '5' && c != '6' && c != '7') { //�����벻��1��2��3��4��5��6��7ʱ������ѭ��
		cout << endl;
		cout << "�������빦�ܲ����ڣ����������롿\n\n" << endl;
		PrintTeacher(); 
		cin >> c;
	}
	return (int)(c - '0'); //����������ѡ��
} 

int Detect3(vector<string>& s) {
	
	//�򲻿� ����.txt �ļ���˵��û�д����κοƼ������ 
	ifstream infile;
	infile.open("����.txt");
	if(!infile) {
		cout << "���Բ��������ڻ�û�д����κοƼ�����͡�" << endl;
		cout << "\n" << endl;
		return 1; 
	}
	
	//������� ����.txt �ļ������ļ��е����ݱ�����s�� 
	while(!infile.eof()) {
		string t;
		getline(infile, t);
		s.push_back(t);
	}
	infile.close();
	s.pop_back();
	
	// ���sΪ�գ���˵��û�д����κοƼ������ 
	if(s.empty()) {
		cout << "���Բ��������ڻ�û�д����κοƼ�����͡�" << endl;
		cout << "\n" << endl;
		return 1; 
	}
	
	//û�д����Ƽ������ֵΪ1�������˷���ֵΪ0 
	return 0;
}

int Detect4(std::vector<std::string>& s, std::string name) {
	int ans = -1; //����ֵans��ʼֵΪ-1
	 
	for(int i = 0; i < s.size(); ++i) {
		if(s[i] == name) {
			ans = i; //��Ҫɾ���ĿƼ�����ڣ���ans����Ϊ�ÿƼ������λ�� 
			break; //����ѭ�� 
		}
	}
	
	return ans; //����ans 
}

//�ж���ʦ�Ƿ񴴽��Ƽ�����ͣ������Detect3()���˴�ӡ������ 
int Detect5(vector<string>& s) {
	ifstream infile;
	infile.open("����.txt");
	if(!infile) {
		cout << "���Բ�����ʦ���ڻ�û�д����κοƼ�����͡�" << endl;
		cout << "\n" << endl;
		return 1; 
	}
	
	while(!infile.eof()) {
		string t;
		getline(infile, t);
		s.push_back(t);
	}
	infile.close();
	s.pop_back();
	
	if(s.empty()) {
		cout << "���Բ�����ʦ���ڻ�û�д����κοƼ�����͡�" << endl;
		cout << endl;
		return 1; 
	}
	
	return 0;
}
