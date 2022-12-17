class Solution {
public:
	//将前n个字符移动到字符的尾端
    string reverseLeftWords(string s, int n) {
        //三次翻转，实现交换
        reverse(s.begin(),s.begin()+n);
        reverse(s.begin()+n,s.end());
        reverse(s.begin(),s.end());
        return s;
    }
};