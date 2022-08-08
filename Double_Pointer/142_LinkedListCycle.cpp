#include <stdc++.h>
using namespace std;

// 给定一个链表，如果有环路，找出环路的开始点。


struct ListNode
{
	int val;
	ListNode * next;
	ListNode(int x): val(x),next(nullptr){};
};
/*
公式推导：

	假设开始点距离环点为m，当前两个点距离环点n，环长L
	则对于slow：
		i_s = m + n + aL
	对于Fast：
		i_f = m + n + bL
	且  i_f = 2 i_s;
	则做差得
	i_s = (b-a)L; 即
	m+n = (b-2a)L
	slow走m步，到达环点
	fast此时在环点前n步，再走m步即为m+n，由上式可知m+n是环的整数倍，所以走完后fast也必在环点
 */

ListNode * detect(ListNode * head){
	ListNode *slow=head,*fast=head;
	//判断有无环路
	do{
		if(!fast || !fast->next) return nullptr;
		slow=slow->next;
		fast=fast->next->next;
	}while (fast!=slow);
	//查找节点
	slow = head;
	while(slow!=fast){
		slow=slow->next;
		fast=fast->next;
	}
	return fast;
}

int main(int argc, char const *argv[])
{
	


	return 0;
}