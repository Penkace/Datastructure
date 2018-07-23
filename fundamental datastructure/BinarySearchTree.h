#include<iostream>
#include<stack>
#include<queue>
#include<cstdio>

using namespace std;
class BSTree {
	struct Node {//建立结点NODE
		Node(int x = 0) :data(x), lchild(NULL), rchild(NULL) {}
		struct Node* lchild;
		struct Node* rchild;
		int data;
	};
public://这里面的方式是给用户直接调用的，这些方法里面调用的是private里面的方法
	BSTree();
	~BSTree();
	void Insert(int x);

	unsigned short Size();
	unsigned short Deep();
	unsigned short Leaf();

	bool IsEmpty();

	void PreorderTraversal();
	void InorderTraversal();
	void PostorderTraversal();
	void DepthFirstSearch();
	void BreadthFirstSearch();

private://private里面定义的是具体的操作，用户不需要知道这里面的方法如何使用的；
	unsigned short CountSize(Node* n);
	unsigned short CountDeep(Node* n);
	unsigned short CountLeaf(Node* n);

	void PreorderTraversal(Node* n);
	void InorderTraversal(Node* n);
	void PostorderTraversal(Node* n);
	void DepthFirstSearch(Node* n);
	void BreadthFirstSearch(Node* n);

	void Free(Node* n);

private:
	Node * m_root;

};

unsigned short BSTree::CountSize(Node* n) {
	if (!n) return 0;//空树返回0
	return CountDeep(n->lchild) + CountDeep(n->rchild) + 1;//从左右两个子结点出发，开始遍历，最终返回树结点的个数
}

unsigned short BSTree::CountDeep(Node* n) {
	if (!n) return 0;
	int ldeep = CountDeep(n->lchild);
	int rdeep = CountDeep(n->rchild);
	return (ldeep > rdeep) ? (ldeep + 1) : (rdeep + 1);//递归求高，从最低处开始比较，每次向上返回左右树层数最多的值
}

unsigned short BSTree::CountLeaf(Node* n) {
	if (!n) return 0;
	if (!n->lchild && !n->rchild)  return 0;
	return CountLeaf(n->lchild) + CountLeaf(n->rchild);
}

void BSTree::PreorderTraversal(Node* n) {
	if (n) {
		cout << n->data << ", ";
		PreorderTraversal(n->lchild);
		PreorderTraversal(n->rchild);
	}
}

void BSTree::InorderTraversal(Node* n) {
	if (n) {
		InorderTraversal(n->lchild);
		cout << n->data << ", ";
		InorderTraversal(n->rchild);
	}
}

void BSTree::PostorderTraversal(Node* n) {
	if (n) {
		PostorderTraversal(n->rchild);
		PostorderTraversal(n->lchild);
		cout << n->data << ", ";
	}
}

void BSTree::DepthFirstSearch(Node* root) {
	stack<Node *>nodeStack;
	nodeStack.push(root);
	Node* node = NULL;
	while (!nodeStack.empty()) {
		node = nodeStack.top();
		cout << node->data << ", ";
		nodeStack.pop();
		if (node->rchild) { nodeStack.push(node->rchild); }
		if (node->lchild) { nodeStack.push(node->lchild); }
	}
}

void BSTree::BreadthFirstSearch(Node* root) {
	queue<Node *>nodeQueue;
	nodeQueue.push(root);
	Node* node = NULL;
	while (!nodeQueue.empty()) {
		node = nodeQueue.front();
		cout << node->data << ", ";
		nodeQueue.pop();
		if (!node->lchild) { nodeQueue.push(node->lchild); }
		if (!node->rchild) { nodeQueue.push(node->rchild); }
	}
}

void BSTree::Free(Node* n) {
	if (n) {
		Free(n->lchild);
		Free(n->rchild);
		delete n;
		n = NULL;
	}
}

BSTree::BSTree() {
	m_root = NULL;
}

BSTree::~BSTree() {
	Free(m_root);
}

void BSTree::Insert(int x) {
	Node* temp = new Node(x);
	if (!m_root) { m_root = temp; }
	else {
		Node *pre = m_root;
		Node *cur = m_root;
		while (cur) {
			pre = cur;
			cur = (x < cur->data) ? (cur->lchild) : (cur->rchild);
		}
		(x < pre->data) ? (pre->lchild = temp) : (pre->rchild = temp);
	}
}


unsigned short BSTree::Size()
{
	return CountSize(m_root);
}

unsigned short BSTree::Deep() {
	return CountDeep(m_root);
}

unsigned short BSTree::Leaf() {
	return CountLeaf(m_root);
}

bool BSTree::IsEmpty() {
	return m_root = NULL;
}

void BSTree::PreorderTraversal() {
	PreorderTraversal(m_root);
	cout << endl;
}

void BSTree::InorderTraversal() {
	InorderTraversal(m_root);
	cout << endl;
}

void BSTree::PostorderTraversal() {
	PostorderTraversal(m_root);
	cout << endl;
}

void BSTree::DepthFirstSearch() {
	DepthFirstSearch(m_root);
	cout << endl;
}

void BSTree::BreadthFirstSearch() {
	BreadthFirstSearch(m_root);
	cout << endl;
}
