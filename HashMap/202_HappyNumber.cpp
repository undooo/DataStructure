#include<stdc++.h>
using namespace std;

//判断一个数是不是快乐数：
//replace the number by the sum of the squares of its digits
//Those numbers for which this process ends in 1 are happy
            
class Solution {
public:

        long long getSum(long long n){
                long long sum = 0;
                while(n){
                        sum += (n%10) * (n%10);
                        n/=10;
                }
                return sum;
        }

        bool isHappy(int n) {
                unordered_set<long long> set;
                
                while(1){
                        long long sum = getSum(n);
                        if(sum == 1){
                                break;
                        }
                        if(set.find(sum) != set.end()){
                                return false;
                        }
                        set.insert(sum);
                        n = sum;
                }
                return true;
        }
};