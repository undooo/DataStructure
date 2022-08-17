#include <stdc++.h>
using namespace std;

//实现自己的链表，需要完成下述功能：
//- 获取index位置的节点
//- 在链表最前面加入一个节点
//- 最后面插入一个节点
//- 在index位置插入一个节点
//- 删除index位置的节点

class MyLinkList{

public:

	struct Node{
		int val;
		Node* next;
		Node(int x):val(x),next(nullptr){}
	};

	MyLinkList(){//构造函数
		_dummyHead = new Node(0);
		_size = 0;
	}

	~MyLinkList(){//析构函数
		delete _dummyHead;
	}

	Node* get(int index){
		if(index <0 || index >=_size){
			return NULL;	//非法查询
		}
		Node* cur = _dummyHead->next;
		while(index--){
			cur = cur->next;
		}
		return cur;
	}

	void addAtHead(int val){
		Node* newNode = new Node(val);
		newNode->next = _dummyHead->next;
		_dummyHead->next = newNode;
		_size++;		
	}

	void addAtTail(int val){
		Node* newNode = new Node(val);
		Node* cur = _dummyHead;
		while(cur->next != NULL){
			cur = cur->next;
		}
		cur->next = newNode;
		_size++;
	}

	void addAtIndex(int index,int val){
		if(index >_size || index<0){
			return;
		}

		Node* cur = _dummyHead->next;
		Node* newNode = new Node(val);
		while(index--){
			cur = cur->next;
		}
		newNode->next = cur->next;
		cur->next = newNode;
		_size++;
	}

	void deleteAtIndex(int index){
		if(index >= _size || index < 0){
			return;
		}
		Node* cur = _dummyHead;
		while(index--){
			cur=cur->next;
		}
		Node * temp = cur->next;
		cur->next = temp->next;
		delete temp;
		_size--;
	}

	void printLinkList(){
		Node* cur = _dummyHead;
		while(cur->next != nullptr){
			cout<< cur->next->val<<"\t";
			cur = cur->next;
		}
		cout<<endl;
	}
private:
	int _size;
	Node* _dummyHead;
};











int main(int argc, char const *argv[])
{
	
	return 0;
}