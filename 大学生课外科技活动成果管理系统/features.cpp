#include "headfile.h"

void Features(int a) {
	//判断a的值为1-6中的哪一个 
	switch(a) {
		case 1:
			FeaturesOne(); //老师功能一 
			break;
		case 2:
			FeaturesTwo(); //老师功能2 
			break;
		case 3:
			FeaturesThree(); //老师功能3 
			break;
		case 4:
			FeaturesFour(); //老师功能4 
			break;
		case 5:
			FeaturesFive(); //老师功能5 
			break;
		default:
			FeaturesSix(); //老师功能6 
	}
}

//创建新的科技活动类型 
void FeaturesOne() {
	//将要创建的科技活动类型名字保存在s1中 
	string s1;
	cout << "\n【请您输入新增的科技活动类型(例如论文、竞赛等)】："; 
	cin >> s1;
	
	ifstream infile1; //创建写入文件方法 
	infile1.open("索引.txt"); //尝试打开文件 索引.txt 
	if(!infile1) { //打不开，说明还没有创建 索引.txt 文件 
		//创建 索引.txt 文件 
		ofstream outfile1; 
		outfile1.open("索引.txt");
		outfile1.close();
	}
	
	//将 索引.txt 文件中现有的科技活动保存在s中，判断s1是否在s中，如果在则退出函数，没有在继续创建 
	string s;
	ifstream infile;
	infile.open("索引.txt");
	while(!infile.eof()) {
		s.push_back(infile.get());
	}
	infile.close();
	if(s.find(s1) != string::npos) {
		cout << "【对不起，您输入的科技活动类型已存在】\n" << endl;
		return; 
	}
	
	// 将想要创建的科技活动类型写入文件最后面 
	ofstream outfile;
	outfile.open("索引.txt", ios::app);
	outfile << s1 << "\n";
	outfile.close();
	
	// 将想要创建的科技活动类型属性保存在s2中 
	string s2;
	char c;
	cout << "【请输入" << s1 << "的各项属性，并用空格隔开】："; 
	getchar();
	getline(cin, s2);
	for(int i = 0; i < s2.length(); ++i) {
		if(s2[i] == ' ') {
			s2[i] = ',';
		}
	}
	
	//创建以新创建的科技活动为名字的.csv文件，并将属性写入第一行 
	ofstream out;
	out.open(s1 + ".csv");
	out << s2 << "\n";
	cout << "\n" << endl;
}

//显示现有的科技活动类型 
void FeaturesTwo() {
	// 判断是否创建科技活动类型 
	vector<string> s;
	if(Detect3(s)) return;
	
	//显示现有的科技活动类型 
	for(int i = 0; i < s.size(); ++i) {
		cout << "【科技活动类型】：" << s[i] << endl;
		ifstream in;
		in.open(s[i] + ".csv");
		string tem;
		getline(in, tem);
		cout << "【" << s[i] << "的属性】：" << tem << endl; 
		in.close();
	}
	cout << "\n" << endl;
	
} 

//删除所有的科技活动类型 
void FeaturesThree(){
	// 判断是否创建科技活动类型 
	vector<string> s;
	if(Detect3(s)) return;
	
	// 删除所有的.csv文件 
	for(int i = 0; i < s.size(); ++i) {
		s[i] += ".csv";
		remove(s[i].c_str());
	}
	remove("索引.txt"); // 删除 索引.txt 文件
	 
	cout << "【删除成功】" << endl;
	cout << "\n" << endl;
} 

// 删除某项科技活动 
void FeaturesFour() {
	// 判断是否创建科技活动类型 
	vector<string> s;
	if(Detect3(s)) return;
	
	//打印现有的科技活动类型 
	Print1(s);
	
	//将想要删除的科技活动保存在name中 
	string name;
	cout << "【请输入您想要删除的科技活动类型】："; 
	cin >> name;
	
	int index = Detect4(s, name); //找到name的位置 
	
	if(index == -1) { // 如果name的位置为-1，表明不存在 
		cout << "【对不起，您输入的科技活动不存在】\n" << endl;
	} else {
		// 删除 索引.txt 文件中的name和name.csv文件 
		s.erase(s.begin() + index);
		name += ".csv";
		remove(name.c_str());
		
		ofstream out;
		out.open("索引.txt");
		for(int i = 0; i < s.size(); ++i) {
			out << s[i] << "\n";
		}
		out.close();
		cout << "【删除成功】\n" << endl;
	}
} 

//显示某项科技活动类型的学生成绩 
void FeaturesFive() {
	// 判断是否存在科技活动 
	vector<string> s;
	if(Detect3(s)) return;
	
	//打印现有的科技活动 
	Print1(s);
	
	//将想要查看的科技活动类型保存在name中 
	string name;
	cout << "【请您输入想要查看的科技活动类型】：";
	cin >> name;
	
	int index = Detect4(s, name); //找到name的位置 
	
	if(index == -1) { // 如果name的位置为-1，表明不存在 
		cout << "【对不起，您输入的科技活动不存在】\n" << endl;
	} else {
		// 打开name.csv文件 
		name += ".csv";
		ifstream infile;
		infile.open(name);
		
		//将name.csv文件中内容保存在temp中 
		vector<string> temp;
		while(!infile.eof()) {
			string t;
			getline(infile, t);
			temp.push_back(t);
		}
		infile.close();
		temp.pop_back();
		
		//如果temp的大小为1，说明只有属性栏，还没有任何学生信息 
		if(temp.size() == 1) {
			cout << "【对不起，该科技活动类型暂时没有学生信息】" << endl;
			cout << "\n" << endl;
			return;
		}
		
		//打印学生信息 
		for(int i = 0; i < temp.size(); ++i) {
			cout << temp[i] << endl;
		}
	}
} 

//记录成绩这一属性的位置 
int num;

//比较方法函数 
bool comp(vector<string> a, vector<string> b) {
	if(stoi(a[num]) > stoi(b[num])) return true;
	return false;
}

//对某项科技活动按照成绩降序排序 
void FeaturesSix() {
	// 判断是否存在科技活动 
	vector<string> s;
	if(Detect3(s)) return;
	
	//打印现有的科技活动类型 
	Print1(s);
	
	//将想要排序的科技活动名称保存在name中 
	string name;
	cout << "【请您输入想要排序的科技活动类型】：";
	cin >> name;
	
	int index = Detect4(s, name); //找到name的位置 
	
	if(index == -1) { // 如果name的位置为-1，表明不存在 
		cout << "【对不起，您输入的科技活动不存在】\n" << endl;
	} else {
	    // 打开name.csv文件 
		name += ".csv";
		ifstream infile;
		infile.open(name);
		
		//将name.csv文件中内容保存在temp中 
		vector<string> temp;
		while(!infile.eof()) {
			string t;
			getline(infile, t);
			temp.push_back(t);
		}
		infile.close();
		temp.pop_back();
		
		//如果temp的大小为1，说明只有属性栏，还没有任何学生信息，退出函数 
		if(temp.size() == 1) {
			cout << "【对不起，该科技活动类型暂时没有学生信息】" << endl;
			cout << "\n" << endl;
			return;
		}
		
		//找到成绩的位置，用num保存 
		if(temp[0].find("成绩") == string::npos) {
			cout << "【对不起，您想要排序的科技活动类型没有“成绩”这一属性】" << endl;
			cout << "\n" << endl;
			return; 
		}
		int position = temp[0].find("成绩");
		num = 0;
		for(int i = 0; i < position; ++i) {
			if(temp[0][i] == ',') ++num;
		}
		
		//用matrix保存name.csv中的学生信息 
		vector<vector<string>> matrix;
		for(int i = 1; i < temp.size(); ++i) {
			vector<string> tem;
			string st;
			for(int j = 0; j < temp[i].size(); ++j) {
				if(temp[i][j] != ',') {
					st.push_back(temp[i][j]);
				} else {
					tem.push_back(st);
					st.clear();
				}
			}
			tem.push_back(st);
			matrix.push_back(tem);
		}

		//对matrix进行排序 
		sort(matrix.begin(), matrix.end(), comp);
		
		//将属性和matrix中的内容重新写回name.csv文件中 
		ofstream out;
		out.open(name);
		out << temp[0] << "\n";
		for(int i = 0; i < matrix.size(); ++i) {
			for(int j = 0; j < matrix[i].size() - 1; ++j) {
				out << matrix[i][j] << ",";
			}
			out << matrix[i][matrix[i].size() - 1] << "\n";
		}
		out.close();
		
		//是否显示排序后结果 
		char c;
		cout << "【排序完成，是否想要显示排序后的结果<Y/N>】:"; 
		while(cin >> c) {
			if(c == 'Y' || c == 'y' || c == 'N' || c == 'n') {
				break;
			} 
			cout << "【对不起，您输入有误。请重新输入】:"; 
		}
		
		//显示排序后结果 
		if(c == 'Y' || c == 'y') {
			cout << temp[0] << endl;
			for(int i = 0; i < matrix.size(); ++i) {
				for(int j = 0; j < matrix[i].size() - 1; ++j) {
					cout << matrix[i][j] << ",";
				}
				cout << matrix[i][matrix[i].size() - 1] << "\n";
			} 
		}
	}
	
}
