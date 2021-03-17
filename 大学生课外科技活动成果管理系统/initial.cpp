#include "headfile.h"

void Initial() {
	
	bool reg = true;
	while(reg) {
		InitialInterface();	//打印初始界面 
		char c;
		cin >> c;
		int a = Detect1(c); //判断输入是否符合要求 
	
		//判断选择的情况 
		switch(a) {
			case 1: //进入老师界面 
				cout << "\n" << endl;
				Teacher();
				cout << "\n" << endl;
				break;
			case 2: //进入学生界面 
				cout << "\n" << endl;
				Student();
				cout << "\n" << endl; 
				break;
			default: //表示选择了退出系统，通过reg = false 退出循环 
				reg = false;
		}
	}
	//reg = false时退出函数 
}
