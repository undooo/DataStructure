class Solution {

    //给定字符串s，反转每一个单词的顺序，需要去除前导和尾随空格
public:
    //去除空格
    void remove_extra_space(string & s){
        //快慢指针
        int slow = 0;

        for(int fast = 0;fast<s.size();++fast){
            if(s[fast]!=' '){//不为空格就处理，即删除空格
                if(slow!=0){s[slow++] = ' ';}//添加单词间的空格

                while(fast<s.size() && s[fast]!= ' '){
                    s[slow++] = s[fast++];
                }
            }
        }
        s.resize(slow);
    }

    string reverseWords(string s) {
        remove_extra_space(s);
        reverse(s.begin(),s.end());

        //翻转单词
        int k=0;
        for(int i=0;i<s.size();i++){
            while(i<s.size() && s[i]!=' '){i++;}
            reverse(s.begin()+k,s.begin()+i);
            k = i+1;
        }
        return s;
    }
};