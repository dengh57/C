#ifndef DETECT_H
#define DETECT_H

//检查首界面是否输入正常 
int Detect1(char c); 

//检查老师功能是否输入正常 
int Detect2(char c); 

//检查是否创建科技活动（老师功能中） 
int Detect3(std::vector<std::string>& s);

//检查科技活动类型是否存在并返回在s中的位置，返回-1表示未找到 
int Detect4(std::vector<std::string>& s, std::string name); 

//检查是否创建科技活动（学生功能中） 
int Detect5(std::vector<std::string>& s);
#endif
