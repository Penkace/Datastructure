/************************
	>File Name: Stack in C++ STL
	>Author: Penkace
	>Date: 2018-07-21 Saturday
************************/

/*#include<iostream>
#include<stack>
using namespace std;
int main() {
	stack<int> myStack;
	myStack.push(5);
	myStack.push(6);
	myStack.push(7);
	myStack.pop();//弹出7。pop()移除并返回栈顶元素
	cout << myStack.top() << endl;//现在最上面是。top()返回栈顶元素
	cout << myStack.size() << endl;//返回栈中元素的个数
	cout << myStack.empty() << endl;
	system("pause");
	return 0;
}
*/

#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<stack>
using namespace std;
int main() {
	ifstream inf;
	inf.open("temp.txt");
	if (!inf) {
		cerr << "cannot open the file" << endl;//cout：写到标准输出的ostream对象；cerr：输出到标准错误的ostream对象，常用于程序错误信息；clog：也是输出标准错误流
		//cout经过缓冲后输出，但是cerr是不经过缓冲直接输出，一般用于快速的给出错误提示。
		return EXIT_FAILURE;
	}
	stack<string> s;
	string line;
	while (getline(inf, line)) {//读入一行文本
		s.push(line);//压入栈中.文本一行一行的入栈
	}
	inf.close();
	while (!s.empty()) {//栈不为空，输出栈顶元素
		cout << s.top() << endl;
		s.pop();
	}
	system("pause");
	return 0;
}
