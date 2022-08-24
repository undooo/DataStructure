#include <stdc++.h>
using namespace std;

struct ListNode{
	int val;
	ListNode * next;
	ListNode(int x):val(x),next(nullptr){}
};


ListNode * swapNeighboringNode(ListNode * head){
	
	ListNode * dummyHead = new ListNode(0);
	dummyHead->next = head;
	ListNode * cur = dummyHead;
	while(cur->next!=nullptr &&cur->next->next!=nullptr){
		//保存临时变量
		ListNode * temp_first = cur->next;
		ListNode * temp_third = temp_first->next->next;

		cur->next = temp_first->next;	//头指向第二个
		cur->next->next = temp_first;	//第二个的下一个指向第一个
		temp_first->next = temp_third;	//第一个指向第三个

		cur = cur->next->next;
	}
	delete dummyHead;
	return dummyHead->next;
}
int main(int argc, char const *argv[])
{
	
	return 0;
}
