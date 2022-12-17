# 栈和队列
C++有多个标准库:
- HP STL, 第一个标准库，且为开源代码，以HP STL为蓝本实现
- P.J.Plauger STL 参照HP STL实现，被Visual C++采用，不开源
- SGI STL， 参照HP HTL实现，被Linux的C++编译器GCC采用，开源，可读性高

以下介绍以SGI STL的版本进行。

## 栈与队列的底层

栈提供push和pop等接口，以实现必须满足先进后出的规则，因此不提供走访功能，以及迭代器（iterator）。

栈以底层容器完成工作，对外提供统一接口，底层容器是可插拔的（vector、deque、list），因此STL中栈往往被归类为 * 容器适配器 * 而不是容器。

SGI STL默认情况下以deque为底层结构
deque是一个双向队列，只需封住一端，便成为了栈的逻辑。
也可以人为指定底层：

```c++
std::stack<int, std::vector<int> > third;
```

同样的，队列底层默认情况下同样以deque为缺省情况下的底层结构

```c++
std::queue<int, std::list<int>> third;
```