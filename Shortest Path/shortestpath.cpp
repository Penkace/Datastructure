/**********************
  >File Name: Shortest Paths-shortestpath.h
  >Author: Penkace
  >References:https://blog.csdn.net/qq_35644234/article/details/60870719
  >Time: 2018-08-02 Thursday
  >Key Point: The function uses of C++
**********************/
#include<iostream>
#include<string>
using namespace std;

/*
使用Dijkstra算法实现最短路径的求解
采用的邻接矩阵来存储图
*/
struct Dis {//记录起点到每个顶点的最短路径的信息
	string path;
	int value;
	bool visit;
	Dis() {
		visit = false;
		value = 0;
		path = "";
	}
};

class Graph_SP {
private:
	int v;//图的顶点个数
	int e;//图的边数
	int **arc;//邻接矩阵
	Dis *dis;//记录各个顶点最短路径的信息
public:
	Graph_SP(int v, int e);//构造函数
	~Graph_SP();//析构函数
	bool check_e_v(int start, int end, int w);//判断每次输入的边的信息是否合法的函数。顶点从1开始编号
	void createGraph();//创建图
	void print();//打印邻接矩阵
	void Dijkstra(int begin);//求最短路径
	void print_path(int);//打印最短路径
};
