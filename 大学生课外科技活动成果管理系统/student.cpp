#include "headfile.h"

void Student() {
	//�ж���ʦ�Ƿ񴴽��Ƽ������ 
	vector<string> s;
	if(Detect5(s)) {
		return;
	} else {
		while(true) {
			//��ӡѧ������ 
			PrintStudent(s); 
			
			//�ж������ѡ���Ƿ���ڣ���fΪ1ʱ�����ڣ�Ϊ0ʱ���� 
			char c;
			cin >> c;
			int f = 1;
			for(int i = 1; i <= s.size() + 1; ++i) {
				if(c == i + '0') {
					f = 0;
					break;
				}
			}
			if(f) {
				cout << "��������ѡ����ڣ����������롿\n\n" << endl;
				Student(); 
			}
			
			//��ѡ��Ϊ������һ��ʱ������ѭ�������˳����� 
			if(c == s.size() + 1 + '0') break;
			
			//��ѡ�����a�У�������Ҫ��д���ļ�������Ҫ��д�����Ա�����t�� 
			int a = c - '0';
			string name = s[a - 1] + ".csv";
			ifstream infile;
			infile.open(name);
			string t;
			getline(infile, t);
			infile.close();
			
			//��ѧ����д�����Ա�����data�� 
			cout << "����Ҫ���������Ϊ��" << t << "�����м��Կո����" << endl;
			string data;
			getchar();
			getline(cin, data);
			for(int i = 0; i < data.size(); ++i) {
				if(data[i] == ' ') data[i] = ',';
			}
			
			//��data�е�����д���ļ�β�� 
			ofstream out;
			out.open(name, ios::app);
			out << data << "\n";
			out.close();
			cout << "\n" << endl;
		}	
	}
}
