## 双指针
用于遍历数组，两个指针指向不同的元素，从而协同完成任务

- 若两个指针指向同一数组，遍历方向相同且不相交，则称其为滑动窗口，通常用于区间搜索

- 若两个指针指向同一数组，遍历方向相反，则可以用来搜索


### 指针与常量

``` C++

int x;
int * p1 = &x; // 指针可以被修改，值也可以被修改
const int * p2 = &x; // 指针可以被修改，值不可以被修改（const int）
int * const p3 = &x; // 指针不可以被修改（* const），值可以被修改
const int * const p4 = &x; // 指针不可以被修改，值也不可以被修改

```
### 指针函数与函数指针

``` C++
//addition是指针函数，一个返回类型是指针的函数
int * addition(int a, int b){
	int *sum=new int(a+b);
	return sum;
}

int subtraction(int a ,int b){
	return a-b;
}
//minus是函数指针，指向函数的指针

int operator(int x, int y, int (*func)(int,int){
	return (*func)(x,y);
}

int (*minus)(int,int) = subtraction;

int *m = addition(1,2);
int n = operation(3,*m, minus)

```