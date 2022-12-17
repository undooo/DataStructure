#include<stdc++.h>
using namespace std;

//用一个队列实现栈
class MyStack {
private:
    queue<int> Queue;

public:
    MyStack() {

    }
    
    void push(int x) {
        Queue.push(x);
    }
    
    int pop() {
        if(Queue.empty()){
            return -1;
        }
        int size = Queue.size();
        --size;
        while(size--){
            int temp = Queue.front();
            Queue.pop();
            Queue.push(temp);
        }
        int ans = Queue.front();
        Queue.pop();
        return ans;
    }
    
    int top() {
        return Queue.back();        
    }
    
    bool empty() {
        return Queue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
int main(int argc, char const *argv[])
{
	
	return 0;
}