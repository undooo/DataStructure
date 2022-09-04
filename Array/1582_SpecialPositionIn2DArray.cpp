#include <stdc++.h>
using namespace std;

// Given an m x n binary matrix mat, return the number of special positions in mat.

// A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).




class Solution {
public:
	//O(mxn)
	//O(m+n)
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> rowSum(m,0);
        vector<int> colSum(n,0);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 1){
                    colSum[j]+=1;
                    rowSum[i]+=1;
                }
            }
        }

        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1 && colSum[j]==1 && rowSum[i]==1){
                    ans++;
                }
            }
        }
        return ans;
    }

    //O(mxn)
    //o(1) 原地修改
    int numSpecial2(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;i++){
            int cnt=0;

            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    cnt++;
                }
            }

            if(i == 0){
                cnt--;
            }

            if(cnt>0){
                for(int j=0;j<n;j++){
                    if(mat[i][j]==1){
                        mat[0][j] += cnt;
                    }
                }
            }
        }

        int ans=0;
        for(int j=0;j<n;j++){
            if(mat[0][j]==1){
                ans++;
            }
        }
        return ans;
    }    
};


int main(int argc, char const *argv[])
{
	
	return 0;
}