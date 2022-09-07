

class Solution {
    //保存序列号和对应的节点即序列数
    Map<String , Pair< TreeNode, Integer>> map = new HashMap<String , Pair<TreeNode, Integer>>();

    //保存结果
    Set<TreeNode> set = new HashSet();

    //特定序列号
    Integer idx = 0;

    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        dfs(root);
        return new ArrayList<TreeNode>(set);
    }

    public int dfs( TreeNode root){
        //空树的序号定为0
        if(root == null) return 0;

        int []  series = {root.val, dfs(root.left),dfs(root.right)};

        String hash = Arrays.toString(series);

        if(map.containsKey(hash)){
            Pair<TreeNode , Integer> pair = map.get(hash);
            TreeNode node = pair.getKey();
            int num = pair.getValue();
            set.add(node);
            return num;
        }else{
            map.put(hash,new Pair<TreeNode,Integer>(root,++idx));
            return idx;
        }
    }
}