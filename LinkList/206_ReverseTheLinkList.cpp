#include<stdc++.h>
using namespace std;

struct LinkList
{
	int val;
	LinkList * next;
	LinkList(int x):val(x),next(nullptr){}
};


//双指针法

LinkList * reverseList(LinkList * head){
	LinkList * pre = nullptr;
	LinkList * temp;
	LinkList * cur = head;
	while(cur){
		temp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = temp;
	}
	return cur;
}

//递归法
LinkList * reverse(LinkList * head){
	if(head==nullptr) return nullptr;
	if(head->next == nullptr) return head;

	LinkList * last = reverse(head->next);
	head->next->next = head;
	head->next = nullptr;
	return last;
}
int main(int argc, char const *argv[])
{
	
	return 0;
}