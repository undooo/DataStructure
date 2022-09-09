class Solution {
    public int minOperations(String[] logs) {
        int step = 0;
        for(int i=0;i<logs.length;i++){
            if("./".equals(logs[i])){
                continue;
            }else if("../".equals(logs[i])){
                if(step>0){
                    step--;
                }
            }else{
                step++;
            }
        }
        return step;
    }
}