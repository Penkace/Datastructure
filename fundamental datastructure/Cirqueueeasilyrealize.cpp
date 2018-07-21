/********************
	>File Nmae: 循环队列
	>Author: Penkcae
	>Date: 2018-07-21 Saturday
	>E-mail: penkaceunique@163.com
********************/

#include<iostream>
using namespace std;
const int Queuesize = 50;

class Cirqueue {
private:
	int data[Queuesize];
	int front, rear;
public:
	Cirqueue() {
		front = rear = 0;
	}
	~Cirqueue() { cout << "destory"; }
	void Enqueue(int x);
	int Dequeue();
	int GetQueue();
	bool Empty() {
		if (front == rear)
			return 1;
		else
			return 0;
	}
};

void Cirqueue::Enqueue(int x) {
	if ((rear + 1) % Queuesize == front)
		cout << "queue is full with elems" << endl;
	else {
		rear = (rear + 1) % Queuesize;
		data[rear] = x;
	}
}

int Cirqueue::Dequeue() {
	if (Empty())
		cout << "queue is empty" << endl;
	else
	{
		front = (front + 1) % Queuesize;
		return data[front];
	}
}

int Cirqueue::GetQueue() {
	if (Empty())
		cout << "Queue is empty" << endl;
	else
	{
		return data[(front + 1) % Queuesize];
	}
}

int main() {
	Cirqueue Q;
	Q.Enqueue(5);
	Q.Enqueue(9);
	Q.Enqueue(7);
	cout << Q.Dequeue() << endl;
	cout << Q.GetQueue() << endl;
	cout << Q.GetQueue() << endl;
	cout << Q.Dequeue() << endl;
	Q.Dequeue();
	system("pause");
	return 0;
}
