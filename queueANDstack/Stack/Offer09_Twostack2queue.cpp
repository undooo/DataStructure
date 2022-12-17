#include <stdc++.h>
using namespace std;

//用两个栈表示一个队列
class CQueue {
private:
    stack<int> instack,outstack;

    void in2out(){
        while(!instack.empty()){
            outstack.push(instack.top());
            instack.pop();
        }
    }
public:
    CQueue() {}
    
    void appendTail(int value) {
        instack.push(value);
    }
    
    int deleteHead() {
        if(outstack.empty()){
            if(instack.empty()){
                return -1;
            }
            in2out();
        }

        int value = outstack.top();
        outstack.pop();
        return value;
    }
};



int main(int argc, char const *argv[])
{
	
	return 0;
}