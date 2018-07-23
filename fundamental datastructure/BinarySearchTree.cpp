//源文件调用BSTree头文件，创建树并调用类里面的方法
#include "BSTree.h"
#include<cstdlib>
#include<iostream>

using namespace std;
int main() {
	BSTree tree;
	int arr[6] = { 5, 4, 8, 1, 7, 10 };
	for (int i = 0; i < 6; ++i) {
		tree.Insert(arr[i]);
	}
	tree.PreorderTraversal();
	tree.InorderTraversal();
	tree.PostorderTraversal();
	tree.DepthFirstSearch();
	tree.BreadthFirstSearch();

	cout << tree.Size() << endl;
	cout << tree.Deep() << endl;
	cout << tree.Leaf() << endl;
	system("pause");
	return 0;
}
