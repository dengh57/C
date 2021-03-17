#include "headfile.h"

int Detect1(char c) {
	while(c != '1' && c != '2' && c != '3') { //当输入不是1，2，3时，进入循环 
		cout << endl;
		cout << "【您输入选项不存在，请重新输入】\n\n" << endl;
		InitialInterface();	  
		cin >> c;
	}
	return (int)(c - '0'); //返回正常的选择 
}

int Detect2(char c) {
	while(c != '1' && c != '2' && c != '3' && c != '4' && c != '5' && c != '6' && c != '7') { //当输入不是1，2，3，4，5，6，7时，进入循环
		cout << endl;
		cout << "【您输入功能不存在，请重新输入】\n\n" << endl;
		PrintTeacher(); 
		cin >> c;
	}
	return (int)(c - '0'); //返回正常的选择
} 

int Detect3(vector<string>& s) {
	
	//打不开 索引.txt 文件，说明没有创建任何科技活动类型 
	ifstream infile;
	infile.open("索引.txt");
	if(!infile) {
		cout << "【对不起，您现在还没有创建任何科技活动类型】" << endl;
		cout << "\n" << endl;
		return 1; 
	}
	
	//如果存在 索引.txt 文件，将文件中的内容保存在s中 
	while(!infile.eof()) {
		string t;
		getline(infile, t);
		s.push_back(t);
	}
	infile.close();
	s.pop_back();
	
	// 如果s为空，则说明没有创建任何科技活动类型 
	if(s.empty()) {
		cout << "【对不起，您现在还没有创建任何科技活动类型】" << endl;
		cout << "\n" << endl;
		return 1; 
	}
	
	//没有创建科技活动返回值为1，创建了返回值为0 
	return 0;
}

int Detect4(std::vector<std::string>& s, std::string name) {
	int ans = -1; //返回值ans初始值为-1
	 
	for(int i = 0; i < s.size(); ++i) {
		if(s[i] == name) {
			ans = i; //想要删除的科技活动存在，将ans保存为该科技活动类型位置 
			break; //跳出循环 
		}
	}
	
	return ans; //返回ans 
}

//判断老师是否创建科技活动类型，相比于Detect3()改了打印的内容 
int Detect5(vector<string>& s) {
	ifstream infile;
	infile.open("索引.txt");
	if(!infile) {
		cout << "【对不起，老师现在还没有创建任何科技活动类型】" << endl;
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
		cout << "【对不起，老师现在还没有创建任何科技活动类型】" << endl;
		cout << endl;
		return 1; 
	}
	
	return 0;
}
