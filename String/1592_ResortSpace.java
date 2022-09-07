class Solution {
    public String reorderSpaces(String text) {

        int length = text.length();
        //获取所有的单词
        String [] strs = text.trim().split("\\s+");
    
        int cntSpace = length;
        //获取空格数
        for(String str: strs){
            cntSpace-=str.length();
        }

        StringBuilder ans = new StringBuilder();
       
        
        if(strs.length ==1){
            ans.append(strs[0]);
            for(int i=0;i<cntSpace;i++){
                ans.append(" ");
            }
            return ans.toString();
        }

 //获取相间空格数和末尾空格数
        int gap = cntSpace/(strs.length-1);
        int end = cntSpace%(strs.length-1);
        String gapSpace = new String(" ").repeat(gap);
        String endSpace = new String(" ").repeat(end);

        for(int i=0;i<strs.length;i++){
            if(i>0){
              
                ans.append(gapSpace);
            }
            ans.append(strs[i]);
        }
        ans.append(endSpace);
        return ans.toString();
    }
}