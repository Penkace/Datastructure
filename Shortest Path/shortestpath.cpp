#include "shortestpath.h"

Graph_SP::Graph_SP(int v, int e) {//构造函数
	this->v = v;//初始化顶点和边的个数
	this->e = e;
	//为邻接矩阵开辟空间和赋初值
	arc = new int *[this->v];//确定顶点的个数进而确定指针数组的一维长度
	dis = new Dis[this->v];
	for (int i = 0; i < this->v; i++) {
		arc[i] = new int[this->v];//再给数组初始化第二位的长度
		for (int k = 0; k < this->v; k++) {
			arc[i][k] = INT_MAX;//邻接矩阵初始化为无穷大
		}
	}
}

Graph_SP::~Graph_SP() {
	delete[] dis;//一维数组直接删除
	for (int i = 0; i < this->v; i++) {
		delete this->arc[i];//二维数组一维一维的删除，因为这个arc是头文件中类的属性
	}
	delete arc;//最后直接删除
}

bool Graph_SP::check_e_v(int start, int end, int w) {//判断每次输入的边的信息是否合法，顶点从1开始
	if (start < 1 || end<1 || start>v || end > v || w < 0) {
		return false;
	}
	return true;
}

void Graph_SP::createGraph() {
	cout << "请输入每条边的起点和终点（顶点编号从1开始）以及其权重" << endl;
	int start;
	int end;
	int w;
	int count = 0;
	while (count != this->e) {
		cin >> start >> end >> w;//首先判断边的信息是否合法
		while (!this->check_e_v(start, end, w)) {//调用判断的方法
			cout << "输入的边的信息不合法，请重新输入" << endl;
			cin >> start >> end >> w;//输入不正确则继续输入
		}
		arc[start - 1][end - 1] = w;//输入的编号是比矩阵下标多1，所以要start和end都减一
		++count;//统计边的个数
	}
}

void Graph_SP::print() {
	cout << "图的邻接矩阵为：" << endl;
	int count_row = 0;//打印行的标签
	int count_col = 0;//打印列的标签
	while (count_row != this->v) {//打印行和列
		count_col = 0;
			while (count_col != this->v) {
				if (arc[count_row][count_col] == INT_MAX)
					cout << "∞" << " ";//如果是没有权重，说明没有连线
				else
				cout << arc[count_row][count_col] << " ";//打印邻接矩阵
				++count_col;
			}
		cout << endl;
		++count_row;//每打印一行就要增加一列
	}
}

void Graph_SP::Dijkstra(int begin) {
	int i;
	for (i = 0; i < this->v; i++) {
		dis[i].path = "v" + to_string(begin) + "-->v" + to_string(i + 1);//记录每个顶点最短路径的信息
		dis[i].value = arc[begin - 1][i];
	}
	dis[begin - 1].value = 0;//起点的值为0
	dis[begin - 1].visit = true;//这个点为遍历过的
	int count = 1;//计算剩余的顶点的最短路径（剩余this—>v-1个顶点）
	int temp = 0;
	while (count != this->v) {//只要count不等于顶点的个数
		int min = INT_MAX;
		for (i = 0; i < this->v; i++) {//遍历所有的顶点
			if (!dis[i].visit && dis[i].value<min) {//只要这个顶点的visit为false并且其值小于最大值，则说明这是最小的路劲			
			min = dis[i].value;//min为当前的最小路径
			temp = i;//temp存储最小值的下标
		}
	}
	dis[temp].visit = true;//找到了最小路径的下标后标其visit为true
	++count;//顶点的数量加一
	for (i = 0; i < this->v; i++) {//松弛操作，relaxtion。再遍历整个点的数组
		if (!dis[i].visit && arc[temp][i] != INT_MAX && (dis[temp].value + arc[temp][i]) < dis[i].value) {
			//判断这个点是否遍历过并且该点于其他的有最小的路径，后面就是判断这个点的value和temp和其他点的路径的和是否小于，如果有就更新
			dis[i].value = dis[temp].value + arc[temp][i];
			dis[i].path = dis[temp].path + "-->v" + to_string(i + 1);//找带最小的点就更新dis数组
			}
		}
	}
}

void Graph_SP::print_path(int begin) {
	string str;
	str = "v" + to_string(begin);//给的是下标
	cout << "以" << str << "为起点的图的最短路径为：" << endl;
	for (int i = 0; i != this->v; i++) {//每个下标都要遍历
		if (dis[i].value != INT_MAX)
			cout << dis[i].path << "=" << dis[i].value << endl;
		else {
			cout << dis[i].path << "是最短路劲的" << endl;
		}
	}
}
