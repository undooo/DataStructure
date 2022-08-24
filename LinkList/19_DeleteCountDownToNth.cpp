#include<stdc++.h>
using namespace std;

//在一趟遍历的前提下，删除倒数第n个节点
struct Node
{
	int val;
	Node *next;
	Node(int x):val(x),next(nullptr){}
};

int DeleteCountdownNth(Node * head, int n){
	//快慢指针法，快指针先前进n，然后慢指针再走
	Node * dummyHead = new Node(0);
	Node * Fast = dummyHead;
	Node * Slow = dummyHead;
	while(n-- && Fast!=nullptr){
		Fast=Fast->next;
	}
	Fast = Fast->next;
	while(Fast->next!=nullptr){
		Fast = Fast->next;
		Slow = Slow->next;
	}
 
	Node * temp = Slow->next;
	Slow->next = Slow->next->next;
	delete temp;
	return dummyHead->next;
}


int main(int argc, char const *argv[])
{
	
	return 0;
}