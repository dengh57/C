#include "headfile.h"

void Teacher() {
	while(true) {
		PrintTeacher(); //��ӡ��ʦ���� 
		char c;
		cin >> c;
		int a = Detect2(c); //�ж�����ѡ���Ƿ���ȷ 
	
		if(a == 7) break; //���ѡ��Ϊ7��������ѭ�������˳����� 
		 
		Features(a); //���ѡ�Ϊ7��Ϊ1-6��������ʦ���ܺ��� 
	}	
}
