#include <stdc++.h>
using namespace std;

struct LinkList{
	int val;
	LinkList * next;
	LinkList(int x):val(x),next(NULL){}
};
//删除链表中的某个元素
LinkList * removeElement(LinkList* head, int val){
	//创建一个虚拟头节点
	LinkList * dummyHead =new LinkList(0);
	dummyHead->next = head;
	LinkList * cur = dummyHead;
	while(cur->next!=NULL){
		if(cur->next->val == val){
			LinkList * temp = cur->next;
			cur->next = cur->next->next;
			delete temp;
		}else{
			cur=cur->next;
		}
	}
	head = dummyHead->next;
	delete dummyHead;
	return head;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}