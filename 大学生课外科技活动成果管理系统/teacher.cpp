#include "headfile.h"

void Teacher() {
	while(true) {
		PrintTeacher(); //打印老师界面 
		char c;
		cin >> c;
		int a = Detect2(c); //判断输入选项是否正确 
	
		if(a == 7) break; //如果选项为7，则跳出循环进而退出函数 
		 
		Features(a); //如果选项不为7即为1-6，进入老师功能函数 
	}	
}
