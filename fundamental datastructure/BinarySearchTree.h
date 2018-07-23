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
	return CountLeaf(n->lchild) + CountLeaf(n->rchild);//按叶子节点开始返回
}

void BSTree::PreorderTraversal(Node* n) {
	if (n) {
		cout << n->data << ", ";
		PreorderTraversal(n->lchild);
		PreorderTraversal(n->rchild);//前序遍历按照先根结点，在前序遍历根结点的左子节点，接着遍历根结点的右子节点
	}
}

void BSTree::InorderTraversal(Node* n) {
	if (n) {
		InorderTraversal(n->lchild);
		cout << n->data << ", ";
		InorderTraversal(n->rchild);//中序遍历的思想和前序遍历相似
	}
}

void BSTree::PostorderTraversal(Node* n) {
	if (n) {
		PostorderTraversal(n->rchild);
		PostorderTraversal(n->lchild);
		cout << n->data << ", ";//后序遍历的思想和前序遍历的思想相同
	}
}

void BSTree::DepthFirstSearch(Node* root) {//深度遍历就是一直往左走，直到头就回溯到上一个结点，走右边，到头再返
	stack<Node *>nodeStack;//创建一个栈用来存放遍历的过程
	nodeStack.push(root);//根结点入栈
	Node* node = NULL;//创建一个空节点
	while (!nodeStack.empty()) {//如果栈为非空，进入下列的循环
		node = nodeStack.top();//返回栈顶元素给Node
		cout << node->data << ", ";//输出跟结点
		nodeStack.pop();//删除栈顶的元素
		if (node->rchild) { nodeStack.push(node->rchild); }//如果有右子结点，则进栈；一直遍历到子节点没有子结点，左子节点也没有子结点，就完成遍历
		if (node->lchild) { nodeStack.push(node->lchild); }//如果有右子结点，则进栈
	}
}

void BSTree::BreadthFirstSearch(Node* root) {//广度遍历是一层一层的遍历，使用队列的性质
	queue<Node *>nodeQueue;//创建一个节点队列
	nodeQueue.push(root);//根结点先进栈
	Node* node = NULL;//创建一个空结点
	while (!nodeQueue.empty()) {//如果队列非空
		node = nodeQueue.front();
		cout << node->data << ", ";//队列的第一个元素出队并且输出数据
		nodeQueue.pop();//删除队头的元素
		if (!node->lchild) { nodeQueue.push(node->lchild); }//如果这个结点有子节点，则这些子节点排在祖父结点的子结点的后面
		if (!node->rchild) { nodeQueue.push(node->rchild); }
	}
}

void BSTree::Free(Node* n) {
	if (n) {
		Free(n->lchild);
		Free(n->rchild);//递归的形式去删除结点
		delete n;
		n = NULL;
	}
}

BSTree::BSTree() {
	m_root = NULL;//创建一个根结点为m_root
}

BSTree::~BSTree() {
	Free(m_root);
}

void BSTree::Insert(int x) {
	Node* temp = new Node(x);
	if (!m_root) { m_root = temp; }//如果根结点为空，则直接复制给根结点
	else {
		Node *pre = m_root;
		Node *cur = m_root;
		while (cur) {
			pre = cur;
			cur = (x < cur->data) ? (cur->lchild) : (cur->rchild);//如果现在结点的值比x小，则cur=他的左结点，否则为右节点
		}
		(x < pre->data) ? (pre->lchild = temp) : (pre->rchild = temp);//若cur经过上面的循环成为空指针，则pre就是上一轮的cur，这时候直接比大小把temp放做进去即可
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

