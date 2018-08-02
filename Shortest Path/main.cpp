#include "shortestpath.h"
#include<iostream>
using namespace std;

bool check(int v, int e) {
	if (v <= 0 || e <= 0 || ((v*(v - 1)) / 2) < e)
		return false;
	return true;
}

int main() {
	int v, e;
	cout << "输入图的顶点个数和边的条数：" << endl;
	cin >> v >> e;
	while (!check(v, e)) {
		cout << "输入的数值不合法，请重新输入" << endl;
		cin >> v >> e;
	}
	Graph_SP graph(v, e);
	graph.createGraph();
	graph.print();
	graph.Dijkstra(1);
	graph.print_path(1);
	system("pause");
	return 0;
}
