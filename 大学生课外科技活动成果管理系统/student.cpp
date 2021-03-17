#include "headfile.h"

void Student() {
	//判断老师是否创建科技活动类型 
	vector<string> s;
	if(Detect5(s)) {
		return;
	} else {
		while(true) {
			//打印学生界面 
			PrintStudent(s); 
			
			//判断输入的选项是否存在，当f为1时不存在，为0时存在 
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
				cout << "【您输入选项不存在，请重新输入】\n\n" << endl;
				Student(); 
			}
			
			//当选项为返回上一级时，跳出循环，并退出函数 
			if(c == s.size() + 1 + '0') break;
			
			//将选项保存在a中，并打开想要填写的文件，将其要填写的属性保存在t中 
			int a = c - '0';
			string name = s[a - 1] + ".csv";
			ifstream infile;
			infile.open(name);
			string t;
			getline(infile, t);
			infile.close();
			
			//将学上填写的属性保存在data中 
			cout << "你需要输入的属性为【" << t << "】，中间以空格隔开" << endl;
			string data;
			getchar();
			getline(cin, data);
			for(int i = 0; i < data.size(); ++i) {
				if(data[i] == ' ') data[i] = ',';
			}
			
			//将data中的内容写入文件尾部 
			ofstream out;
			out.open(name, ios::app);
			out << data << "\n";
			out.close();
			cout << "\n" << endl;
		}	
	}
}
