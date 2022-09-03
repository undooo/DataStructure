#include <stdc++.h>
using namespace std;

// You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.

// A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.

// Return the length longest chain which can be formed.

// You do not need to use up all the given intervals. You can select pairs in any order.
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int pre = INT_MIN;
        sort(pairs.begin(),pairs.end(),[](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });
        int n = pairs.size();
        int num = 0;
        for(int i=0;i<n;i++){
            if(pairs[i][0]>pre){
                num++;
                pre = pairs[i][1];
            }
        }
        return num;
    }
};

int main(int argc, char const *argv[])
{
	
	return 0;
}