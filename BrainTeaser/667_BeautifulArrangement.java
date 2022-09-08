class Solution {
    public int[] constructArray(int n, int k) {
        
        int [] ans = new int[n];

        int idx = 0;
        //将前n-k-1个数全部依次排列即可
        for(int i=1;i<n-k;i++){
            ans[idx++] = i;
        }

        //后n-k个数按特定方法排列，即可保证差为1~n-k
        for(int i=n-k,j=n;i<=j;i++,j--){
            ans[idx] = i;
            idx++;
            if(i!=j){
                ans[idx] = j;
                idx++;
            }
        }

        return ans;
    }
}