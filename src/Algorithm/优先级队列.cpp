#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node
{
	char data;
	int weight;
	Node(char _data, int _weight)
	{
		data = _data;
		weight = _weight;
	}
};
struct cmp1
{

	bool operator () (const Node& a, const Node& b)
	{
		return a.weight < b.weight;			//������ȼ��� 
	}
};
struct cmp2
{
	bool operator()(const Node& a, const Node& b)
	{
		return a.weight > b.weight;			//С�����ȼ��� 
	}
};
bool cmp(const Node& a, const Node& b)
{
	return a.weight > b.weight;
}
struct Node2
{
	char data;
	int weight;
	Node2(char _data, int _weight)
	{
		data = _data;
		weight = _weight;
	}
	friend bool operator < (const Node2& a, const Node2& b)
	{
		return a.weight < b.weight;
	}
};
struct Node3
{
	char data;
	int weight;
	Node3(char _data, int _weight)
	{
		data = _data;
		weight = _weight;
	}
	friend bool operator < (const Node3& a, const Node3& b)
	{
		return a.weight > b.weight;
	}
};
int main()
{
	string values = "ABCDEF";
	vector<int> weights = { 1,2,3,4,5,6 };
	priority_queue< Node, vector<Node>, cmp1> q1;
	for (int i = 0; i < values.length(); i++)
	{
		Node newNode(values[i], weights[i]);
		q1.push(newNode);
	}
	cout << "���ȶ���q1�ĵ�һ��Ԫ����:  " << q1.top().data << endl;

	priority_queue<Node, vector<Node>, cmp2> q2;
	for (int i = 0; i < values.length(); i++)
	{
		Node newNode(values[i], weights[i]);
		q2.push(newNode);
	}
	cout << "���ȶ���q2�ĵ�һ��Ԫ����:  " << q2.top().data << endl;

	priority_queue<Node2> q3;
	for (int i = 0; i < values.length(); i++)
	{
		Node2 newNode(values[i], weights[i]);
		q3.push(newNode);
	}
	cout << "���ȶ���q3�ĵ�һ��Ԫ����:  " << q3.top().data << endl;

	priority_queue<Node3> q4;
	for (int i = 0; i < values.length(); i++)
	{
		Node3 newNode(values[i], weights[i]);
		q4.push(newNode);
	}
	cout << "���ȶ���q4�ĵ�һ��Ԫ����:  " << q4.top().data << endl;
}
