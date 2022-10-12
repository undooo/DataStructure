#include<stdc++.h>
using namespace std;

//给定四个数组，找出四元组（i,j,k,m）的个数，使得A[i] + B[j] + C[k] + D[m] == 0
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
            unordered_map<int, int> ab_map;
            for(int a : nums1){
                    for(int b : nums2){
                            ab_map[a+b]++;
                    }
            }
            
            int ans = 0;
            for(int c : nums3){
                    for(int d : nums4){
                            if(ab_map.find(0-(c+d)) != ab_map.end()){
                                    ans+= ab_map[0-(c+d)];
                            }
                    }
            }
            return ans;
    }
};

int main(int argc, char const *argv[])
{
	
	return 0;
}