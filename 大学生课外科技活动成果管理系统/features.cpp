#include "headfile.h"

void Features(int a) {
	//�ж�a��ֵΪ1-6�е���һ�� 
	switch(a) {
		case 1:
			FeaturesOne(); //��ʦ����һ 
			break;
		case 2:
			FeaturesTwo(); //��ʦ����2 
			break;
		case 3:
			FeaturesThree(); //��ʦ����3 
			break;
		case 4:
			FeaturesFour(); //��ʦ����4 
			break;
		case 5:
			FeaturesFive(); //��ʦ����5 
			break;
		default:
			FeaturesSix(); //��ʦ����6 
	}
}

//�����µĿƼ������ 
void FeaturesOne() {
	//��Ҫ�����ĿƼ���������ֱ�����s1�� 
	string s1;
	cout << "\n���������������ĿƼ������(�������ġ�������)����"; 
	cin >> s1;
	
	ifstream infile1; //����д���ļ����� 
	infile1.open("����.txt"); //���Դ��ļ� ����.txt 
	if(!infile1) { //�򲻿���˵����û�д��� ����.txt �ļ� 
		//���� ����.txt �ļ� 
		ofstream outfile1; 
		outfile1.open("����.txt");
		outfile1.close();
	}
	
	//�� ����.txt �ļ������еĿƼ��������s�У��ж�s1�Ƿ���s�У���������˳�������û���ڼ������� 
	string s;
	ifstream infile;
	infile.open("����.txt");
	while(!infile.eof()) {
		s.push_back(infile.get());
	}
	infile.close();
	if(s.find(s1) != string::npos) {
		cout << "���Բ���������ĿƼ�������Ѵ��ڡ�\n" << endl;
		return; 
	}
	
	// ����Ҫ�����ĿƼ������д���ļ������ 
	ofstream outfile;
	outfile.open("����.txt", ios::app);
	outfile << s1 << "\n";
	outfile.close();
	
	// ����Ҫ�����ĿƼ���������Ա�����s2�� 
	string s2;
	char c;
	cout << "��������" << s1 << "�ĸ������ԣ����ÿո��������"; 
	getchar();
	getline(cin, s2);
	for(int i = 0; i < s2.length(); ++i) {
		if(s2[i] == ' ') {
			s2[i] = ',';
		}
	}
	
	//�������´����ĿƼ��Ϊ���ֵ�.csv�ļ�����������д���һ�� 
	ofstream out;
	out.open(s1 + ".csv");
	out << s2 << "\n";
	cout << "\n" << endl;
}

//��ʾ���еĿƼ������ 
void FeaturesTwo() {
	// �ж��Ƿ񴴽��Ƽ������ 
	vector<string> s;
	if(Detect3(s)) return;
	
	//��ʾ���еĿƼ������ 
	for(int i = 0; i < s.size(); ++i) {
		cout << "���Ƽ�����͡���" << s[i] << endl;
		ifstream in;
		in.open(s[i] + ".csv");
		string tem;
		getline(in, tem);
		cout << "��" << s[i] << "�����ԡ���" << tem << endl; 
		in.close();
	}
	cout << "\n" << endl;
	
} 

//ɾ�����еĿƼ������ 
void FeaturesThree(){
	// �ж��Ƿ񴴽��Ƽ������ 
	vector<string> s;
	if(Detect3(s)) return;
	
	// ɾ�����е�.csv�ļ� 
	for(int i = 0; i < s.size(); ++i) {
		s[i] += ".csv";
		remove(s[i].c_str());
	}
	remove("����.txt"); // ɾ�� ����.txt �ļ�
	 
	cout << "��ɾ���ɹ���" << endl;
	cout << "\n" << endl;
} 

// ɾ��ĳ��Ƽ�� 
void FeaturesFour() {
	// �ж��Ƿ񴴽��Ƽ������ 
	vector<string> s;
	if(Detect3(s)) return;
	
	//��ӡ���еĿƼ������ 
	Print1(s);
	
	//����Ҫɾ���ĿƼ��������name�� 
	string name;
	cout << "������������Ҫɾ���ĿƼ�����͡���"; 
	cin >> name;
	
	int index = Detect4(s, name); //�ҵ�name��λ�� 
	
	if(index == -1) { // ���name��λ��Ϊ-1������������ 
		cout << "���Բ���������ĿƼ�������ڡ�\n" << endl;
	} else {
		// ɾ�� ����.txt �ļ��е�name��name.csv�ļ� 
		s.erase(s.begin() + index);
		name += ".csv";
		remove(name.c_str());
		
		ofstream out;
		out.open("����.txt");
		for(int i = 0; i < s.size(); ++i) {
			out << s[i] << "\n";
		}
		out.close();
		cout << "��ɾ���ɹ���\n" << endl;
	}
} 

//��ʾĳ��Ƽ�����͵�ѧ���ɼ� 
void FeaturesFive() {
	// �ж��Ƿ���ڿƼ�� 
	vector<string> s;
	if(Detect3(s)) return;
	
	//��ӡ���еĿƼ�� 
	Print1(s);
	
	//����Ҫ�鿴�ĿƼ�����ͱ�����name�� 
	string name;
	cout << "������������Ҫ�鿴�ĿƼ�����͡���";
	cin >> name;
	
	int index = Detect4(s, name); //�ҵ�name��λ�� 
	
	if(index == -1) { // ���name��λ��Ϊ-1������������ 
		cout << "���Բ���������ĿƼ�������ڡ�\n" << endl;
	} else {
		// ��name.csv�ļ� 
		name += ".csv";
		ifstream infile;
		infile.open(name);
		
		//��name.csv�ļ������ݱ�����temp�� 
		vector<string> temp;
		while(!infile.eof()) {
			string t;
			getline(infile, t);
			temp.push_back(t);
		}
		infile.close();
		temp.pop_back();
		
		//���temp�Ĵ�СΪ1��˵��ֻ������������û���κ�ѧ����Ϣ 
		if(temp.size() == 1) {
			cout << "���Բ��𣬸ÿƼ��������ʱû��ѧ����Ϣ��" << endl;
			cout << "\n" << endl;
			return;
		}
		
		//��ӡѧ����Ϣ 
		for(int i = 0; i < temp.size(); ++i) {
			cout << temp[i] << endl;
		}
	}
} 

//��¼�ɼ���һ���Ե�λ�� 
int num;

//�ȽϷ������� 
bool comp(vector<string> a, vector<string> b) {
	if(stoi(a[num]) > stoi(b[num])) return true;
	return false;
}

//��ĳ��Ƽ�����ճɼ��������� 
void FeaturesSix() {
	// �ж��Ƿ���ڿƼ�� 
	vector<string> s;
	if(Detect3(s)) return;
	
	//��ӡ���еĿƼ������ 
	Print1(s);
	
	//����Ҫ����ĿƼ�����Ʊ�����name�� 
	string name;
	cout << "������������Ҫ����ĿƼ�����͡���";
	cin >> name;
	
	int index = Detect4(s, name); //�ҵ�name��λ�� 
	
	if(index == -1) { // ���name��λ��Ϊ-1������������ 
		cout << "���Բ���������ĿƼ�������ڡ�\n" << endl;
	} else {
	    // ��name.csv�ļ� 
		name += ".csv";
		ifstream infile;
		infile.open(name);
		
		//��name.csv�ļ������ݱ�����temp�� 
		vector<string> temp;
		while(!infile.eof()) {
			string t;
			getline(infile, t);
			temp.push_back(t);
		}
		infile.close();
		temp.pop_back();
		
		//���temp�Ĵ�СΪ1��˵��ֻ������������û���κ�ѧ����Ϣ���˳����� 
		if(temp.size() == 1) {
			cout << "���Բ��𣬸ÿƼ��������ʱû��ѧ����Ϣ��" << endl;
			cout << "\n" << endl;
			return;
		}
		
		//�ҵ��ɼ���λ�ã���num���� 
		if(temp[0].find("�ɼ�") == string::npos) {
			cout << "���Բ�������Ҫ����ĿƼ������û�С��ɼ�����һ���ԡ�" << endl;
			cout << "\n" << endl;
			return; 
		}
		int position = temp[0].find("�ɼ�");
		num = 0;
		for(int i = 0; i < position; ++i) {
			if(temp[0][i] == ',') ++num;
		}
		
		//��matrix����name.csv�е�ѧ����Ϣ 
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

		//��matrix�������� 
		sort(matrix.begin(), matrix.end(), comp);
		
		//�����Ժ�matrix�е���������д��name.csv�ļ��� 
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
		
		//�Ƿ���ʾ������� 
		char c;
		cout << "��������ɣ��Ƿ���Ҫ��ʾ�����Ľ��<Y/N>��:"; 
		while(cin >> c) {
			if(c == 'Y' || c == 'y' || c == 'N' || c == 'n') {
				break;
			} 
			cout << "���Բ����������������������롿:"; 
		}
		
		//��ʾ������� 
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
