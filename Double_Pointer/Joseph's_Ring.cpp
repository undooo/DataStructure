#include <bits/stdc++.h>
using namespace std;

int lastRemaining_Recursive(int x, int y);
int lastRemaining_CircularList(int x, int y);

int main()
{	

	int x1=lastRemaining_Recursive(1,1);
	int x2=lastRemaining_CircularList(1,1);
	cout<< x1<<"---"<<endl;
	
	cout<< x2<<"---"<<endl;

	return 0;
}

/*
	约瑟夫环问题
	0,1,···,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字（删除后从下一个数字开始计数）。求出这个圆圈里剩下的最后一个数字。
 */

//递归解法
/*
	查找规律，例如对于10个人，每次去除第3个，即：
初始状态：				0 1 2 3 4 5 6 7 8 9
去除第一个数：			0 1   3 4 5 6 7 8 9
则下一次应该从3开始：			  3 4 5 6 7 8 9 0 1 
且其实0，1可表示为 10%10的形式
而对于9个人去第三个，可以发现：  0 1 2 3 4 5 6 7 8
有一个非常明显的规律， 3 = (0+3)%10
由此递归下去
	f(10,3) = (f(9,3)+3)%10
	f(9 ,3) = (f(8,3)+3)%9
	...
	f(1,3)  = 0
 */

int lastRemaining_Recursive(int n, int m){
	if(n == 1){
		return 0;
	}
	return (lastRemaining_Recursive(n-1,m)+m)%n;
}


//常规循环链表
struct ListNode
{
	int val;
	ListNode * next;
	ListNode(int i):val(i),next(nullptr){};
};

int lastRemaining_CircularList(int n, int m){
	//若是一个一个去，则最后一个即为最后一人
	if(m == 1){return n-1;}
	//初始化循环链表
	ListNode * node =new ListNode(0);
	ListNode * temp = node;
	for(int i=1;i<n;i++){
		ListNode * newNext = new ListNode(i);
		temp->next= newNext;
		temp= newNext;
	}

	temp->next = node;

	int index = 0;
	while(node->next != node){
		//若index = m-1，说明下一个节点应该删除
		if(index == (m-2)%n){
			node->next=node->next->next;
			index = 0;
			n--;
		}else{
			index++;
		}
		node = node->next;
	}
	return node->val;
}

