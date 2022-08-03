#include <stdc++.h>
using namespace std;

//输入两个链表，找出第一个公共节点
//
struct ListNode
{
	int val;
	ListNode * next;
	ListNode(int x):val(x),next(NULL){}
};

ListNode* getIntersectionNode(ListNode * headA, ListNode * headB){
	//双指针，第一个从A出发，再从B走，共走a+b+c
	//第二个从B出发，再从A走，也是a+b+c，最终会相遇
	ListNode * ptr1 = headA,ptr2 = headB;

	while(ptr1 != ptr2){
		ptr1 = ptr1==NULL? headB:ptr1->next;
		ptr2 = ptr2==NULL? headA:ptr2->next;

	}
	return ptr1;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}