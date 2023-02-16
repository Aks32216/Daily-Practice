class Solution {
public:

    TreeNode* solve(int& idx,vector<int>& preorder,int prev,vector<int>& postorder,unordered_map<int,int>& mp){
        if(idx>=preorder.size())
            return NULL;
        int cur=mp[preorder[idx]];
        if(cur>=prev)
            return NULL;
        TreeNode* root=new TreeNode(preorder[idx]);
        idx++;
        prev=cur;
        root->left=solve(idx,preorder,prev,postorder,mp);
        root->right=solve(idx,preorder,prev,postorder,mp);
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int idx=0;
        int prev=INT_MAX;
        unordered_map<int,int> mp;
        for(int i=0;i<postorder.size();++i)
            mp[postorder[i]]=i;
        return solve(idx,preorder,prev,postorder,mp);
    }
};