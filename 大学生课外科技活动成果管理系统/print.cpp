#include "headfile.h"

void InitialInterface() {
	SetConsoleTitle("大学生课外科技活动成果管理系统"); 
	cout << "--------------------大学生课外科技活动成果管理系统--------------------" << endl;
	cout << endl;
	cout << "                                1 老师" << endl;
	cout << "                                2 学生" << endl; 
	cout << "                                3 退出" << endl; 
	cout << endl;
	cout << "                                请输入您的身份或退出系统<1-3>："; 
}

void PrintTeacher() {
	cout << "--------------------大学生课外科技活动成果管理系统--------------------" << endl;
	cout << endl;
	cout << "                                老师功能：" << endl;
	cout << endl;
	cout << "                                1 新增科技活动" << endl; 
	cout << "                                2 显示现有科技活动" << endl;
	cout << "                                3 删除所有科技活动" << endl; 
	cout << "                                4 删除某项科技活动" << endl;
	cout << "                                5 查看某项科技活动成果学生成绩" << endl;
	cout << "                                6 对某项科技成果学生成绩按成绩降序排序" << endl; 
	cout << "                                7 返回" << endl; 
	cout << endl;
	cout << "                                请输入您的选择或返回上一级<1-7>："; 
} 

void PrintStudent(vector<string>& s) {
	cout << "--------------------大学生课外科技活动成果管理系统--------------------" << endl;
	cout << endl;
	cout << "                                科技成果类型：" << endl;
	cout << endl;
	for(int i = 0; i < s.size(); ++i) {
		cout << "                                " << i + 1 << " " << s[i] << endl;
	}
	cout << "                                " << s.size() + 1 << " 返回" << endl; 
	cout << endl;
	cout << "                                请输入你要填写的科技成果或者返回上一级<1-" << s.size() + 1 << ">：";
}

void Print1(vector<string>& s) {
	cout << "【科技活动类型】：";
	for(int i = 0; i < s.size(); ++i) {
		cout << s[i] << "  ";
	}
	cout << endl;
}

