void solve(Node* root,map<int,vector<int> >& mp)
  {
      queue<pair<Node*,int> > q;
      q.push({root,0});
      while(!q.empty())
      {
          int n=q.size();
          while(n--)
          {
              auto cur=q.front();
              q.pop();
              mp[cur.second].push_back(cur.first->data);
              if(cur.first->left!=NULL)
                q.push({cur.first->left,cur.second-1});
            if(cur.first->right!=NULL)
                q.push({cur.first->right,cur.second+1});
          }
      }
  }
  
    vector <int> bottomView(Node *root) {
        vector<int> res;
        if(root==NULL)
            return res;
        map<int,vector<int> > mp;
        solve(root,mp);
        for(auto i:mp)
        {
            res.push_back(mp[i.first][mp[i.first].size()-1]);
        }
        return res;
    }