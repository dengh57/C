#include "headfile.h"

void Initial() {
	
	bool reg = true;
	while(reg) {
		InitialInterface();	//��ӡ��ʼ���� 
		char c;
		cin >> c;
		int a = Detect1(c); //�ж������Ƿ����Ҫ�� 
	
		//�ж�ѡ������ 
		switch(a) {
			case 1: //������ʦ���� 
				cout << "\n" << endl;
				Teacher();
				cout << "\n" << endl;
				break;
			case 2: //����ѧ������ 
				cout << "\n" << endl;
				Student();
				cout << "\n" << endl; 
				break;
			default: //��ʾѡ�����˳�ϵͳ��ͨ��reg = false �˳�ѭ�� 
				reg = false;
		}
	}
	//reg = falseʱ�˳����� 
}
