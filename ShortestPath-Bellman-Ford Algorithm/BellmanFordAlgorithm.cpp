/***************************
  >File Name: Bellman-Ford Algorithm
  >Author: PengKai
  >Time: 2018-08-16 Thursday 12:05
  >Reference: https://blog.csdn.net/niushuai666/article/details/6791765
***************************/
#include<iostream>
using namespace std;

#define Size 1010
#define max 0x3f3f3f3f//在一些算法竞赛中，通常使用0x3f3f3f3f来表示无穷大，如果用INT_MAX，即0x7fffffff作为无穷大，当加一个其他数会溢出

int n, e, s;//结点数，边数，起点
typedef struct Edge {
	int u;
	int v;
	int w;
}Edge;//定义边的结构体。包括边的起点、终点、权重

Edge edge[Size];//定义结构体数组，用于存放边的信息
int dis[Size];//单源最短路径存放数组
int PrePoint[Size];//打印结点数组

int BellmanFord() {
	for (int i = 1; i <= n; i++)
		dis[i] = (i == s ? 0 : max);//初始化最短路径数组，如果等于起点就是0，否则为无穷大

	for (int i = 1; i < n - 1; i++)
		for (int j = 1; j <= e; ++j)
			if (dis[edge[j].v] > dis[edge[j].u ]+ edge[j].w) {//在最短路径数组里的终点下的值如果大于边j起点与其边的权重之和，说明该路径更短
				dis[edge[j].v] = dis[edge[j].u] + edge[j].w;//针对的是数字标号的路径
				PrePoint[edge[j].v] = edge[j].u;//改变PrePoint数组的值
			}
	//下面是检测是否存在负环，BellmanFord不同于Dijkstra算法，能够检测负环，但是其证明原理与Dijstra是一样的
	int flag = 1;
	for(int i=1;i<=e;++i)
		if (dis[edge[i].v] > dis[edge[i].u] + edge[i].w) {
			flag=0; break;
		}
	return flag;
}

//该方法用于打印最短路径
void printPath(int root) {
	while (root != PrePoint[root]) {
		cout << root << "<-- ";
		root = PrePoint[root];
	}
		cout << root << endl;
}

int main() {
	cin >> n>>e>>s;

	for (int i = 1; i <= e; ++i) {
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
	}//输入边的详细信息

	if (BellmanFord()) {
		for (int i = 1; i <= n; i++) {
			cout <<"最短路径权重: "<< dis[i] << endl;
			cout << "Path: ";
			printPath(i);
		}
	}
	else
		cout << "The graph has negative circle!" << endl;
		system("pause");
		return 0;
}
