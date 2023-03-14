class Solution {
public:

    vector<TreeNode*> solve(int n,unordered_map<int,vector<TreeNode*>>& mp){
        if(n==1)
            return {new TreeNode(0,NULL,NULL)};
        if(mp.find(n)!=mp.end())
            return mp[n];
        vector<TreeNode*> temp;
        for(int i=1;i<n;i+=2){
            vector<TreeNode*> left=solve(i,mp);
            vector<TreeNode*> right=solve(n-i-1,mp);
            for(int j=0;j<left.size();++j)
            {
                for(int k=0;k<right.size();++k){
                    TreeNode* cur=new TreeNode(0,left[j],right[k]);
                    temp.push_back(cur);
                }
            }
        }
        return mp[n]=temp;
    }

    vector<TreeNode*> allPossibleFBT(int n) {
        unordered_map<int,vector<TreeNode*>> mp;
        return solve(n,mp);
    }
};