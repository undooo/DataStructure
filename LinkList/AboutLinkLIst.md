# 链表
通过指针串连起来的线性结构，每个节点由两个部分组成：数据域+指针域

指针域存放指向下一个节点的指针，最后一个结点的指针指向null

``` c++
struct Linklist{
	int val;
	Linklist * next;
	Linklist(int x):val(x),next(NULL){}
};

```

## 双链表
相比于单链表，双链表有两个指针域，一个指向上一个节点，一个指向下一个节点，因此既可以向前遍历，也可以向后遍历。

## 循环链表
链表的首尾相连

## 链表的存储方式
是不连续分布的，通过指针域的方式，连接存储在内存中的各个节点