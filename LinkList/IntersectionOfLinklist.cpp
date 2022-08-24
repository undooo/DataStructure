#include <stdc++.h>
using namespace std;

struct  Node
{
	int val;
	Node* next;
	Node(int x):val(x),next(nullptr){}
};

//给出两个链表的头节点，找出两个单链表的交点，若没有，则返回null
//方法一、双指针法
Node * getIntersection(Node* headA, Node* headB){
	Node* tempA = headA;
	Node* tempB = headB;
	while(tempA !=tempB){
		tempA = tempA ==nullptr? headB:tempA->next;
		tempB = tempB ==nullptr? headA:tempB->next;
	}
	return tempA;
}

//方法二、一般方法
Node* getIntersectionTwo(Node* headA, Node* headB){
	//首先，获得两个链表的长度
	int lenA=0,lenB=0;
	Node * tempA = headA;
	Node * tempB = headB;
	while(tempA->next!=nullptr){
		lenA++;
		tempA = tempA->next;
	}
	while(tempB->next!=nullptr){
		lenB++;
		tempB = tempB->next;
	}

	//使A链表为较长的链表
	tempA = headA;
	tempB = headB;
	if(lenA < lenB){
		swap(lenA,lenB);
		swap(tempA,tempB);
	}

	//将tempA向前移动，使得两个链表尾部对齐
	int dif = lenA - lenB;
	while(dif--){
		tempA = tempA->next;
	}
	//同时移动两个指针，若相同则返回
	while(tempA != nullptr){
		if(tempA == tempB){
			return tempA;
		}
		tempA = tempA->next;
		tempB = tempB->next;
	}
	//若没找到，则返回空
	return nullptr;
}
int main(int argc, char const *argv[])
{
	
	return 0;
}