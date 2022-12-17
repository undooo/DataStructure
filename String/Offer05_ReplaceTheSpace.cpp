class Solution {
public:
    //将字符串中的空格转化为“%20”


    string replaceSpace(string s) {
        //扩容+双指针
        int cnt = 0;
        int oriSize = s.size();
        for(int i =0; i< s.size();i++){
            if(s[i] == ' '){
                cnt++;
            }
        }
        //扩容
        s.resize(s.size()+cnt*2);
        //双指针从后向前
        int slow = s.size()-1;
        int fast = oriSize-1;

        while(fast<slow){
            if(s[fast] == ' '){
                s[slow--] = '0';
                s[slow--] = '2';
                s[slow] = '%';
        
            }else{
                s[slow] = s[fast];
            }
            --slow;
            --fast;
        }
        return s;

    }
};