#include<bits/stdc++.h> 

using namespace std;

struct Link{
    int val;
    Link* next;
    Link* last;
    Link(int x,Link* last,Link*next):val(x),last(last),next(next){}
};

int n,m;
Link* dummy = new Link(0,nullptr,nullptr);
int main( )
{
    cin>>n>>m;
    Link * tempLink = dummy;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        Link * Node =new Link(temp,tempLink,nullptr);
        tempLink->next = Node;
        tempLink=tempLink->next;
    }


    for(int i=0;i<m;i++){
        int x,y,type;
        cin>>x>>y>>type;
        Link* NodeX = dummy;
        Link* NodeY = dummy;
        while(NodeX!=nullptr){
            if(NodeX->val == x){
                break;
            }
            NodeX = NodeX->next;
        }

        while(NodeY!=nullptr){
            if(NodeY->val == y){
                break;
            }
            NodeY= NodeY->next;
        }

        if(type){
            //取出NodeX
            Link* pre = NodeX->last;
            pre->next->next = NodeX->next;
            //放在NodeY的后面
            NodeX->next = NodeY->next;
            NodeY->next = NodeX;
        }else{
            //取出NodeX
            Link* pre = NodeX->last;
            pre->next->next = NodeX->next;
            //放在NodeY的后面
            Link* preY = NodeY->last;
            NodeX->next = NodeY;
            preY->next = NodeX;            
        }
    }

    dummy = dummy->next;
    for(int i=0;i<n;i++){
        cout<<dummy->val<<" ";
        dummy = dummy->next;
    }
    return 0;
}
