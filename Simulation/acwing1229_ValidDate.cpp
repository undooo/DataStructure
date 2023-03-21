#include <bits/stdc++.h>
using namespace std;

/*
小明正在整理一批历史文献。这些历史文献中出现了很多日期。

小明知道这些日期都在1960年1月1日至2059年12月31日。

令小明头疼的是，这些日期采用的格式非常不统一，有采用年/月/日的，有采用月/日/年的，还有采用日/月/年的。

更加麻烦的是，年份也都省略了前两位，使得文献上的一个日期，存在很多可能的日期与其对应。

比如02/03/04，可能是2002年03月04日、2004年02月03日或2004年03月02日。

给出一个文献上的日期，你能帮助小明判断有哪些可能的日期对其对应吗？

输入格式
一个日期，格式是”AA/BB/CC”。

即每个’/’隔开的部分由两个 0-9 之间的数字（不一定相同）组成。

输出格式
输出若干个不相同的日期，每个日期一行，格式是”yyyy-MM-dd”。

多个日期按从早到晚排列。

数据范围
0≤A,B,C≤9
输入样例：
02/03/04
输出样例：
2002-03-04
2004-02-03
2004-03-02
*/

int a,b,c;

int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool valid(int y, int m, int d){
    if(m==0 || m>12 || d==0) return false;
    if(m!=2 && d > days[m]) return false;
    if(m==2){
        int leap = (y%4==0 && y%100!=0) || y%400==0;
        if(d > days[2]+leap) return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    vector<int> ans;
    scanf("%d/%d/%d",&a,&b,&c);
    int year, month, day;
    // case 1
    year = a>=60? 1900+a : 2000+a;
    month = b;
    day = c;
    if(valid(year, month, day)) ans.push_back(year*10000+month*100+day);

    // case 2
    year = c>=60? 1900+c : 2000+c;
    month = a;
    day = b;
    if(valid(year, month, day)) ans.push_back(year*10000+month*100+day);
    
    // case 3
    year = c>=60? 1900+c : 2000+c;
    month = b;
    day = a;
    if(valid(year, month, day)) ans.push_back(year*10000+month*100+day); 

    sort(ans.begin(), ans.end());
    set<int> s(ans.begin(), ans.end());
    ans.assign(s.begin(),s.end());
    for(auto & date : ans){
        year = date/10000;
        month = date%10000/100;
        day = date%100;
        printf("%d-%02d-%02d\n",year, month, day);
    }
    return 0;
}
