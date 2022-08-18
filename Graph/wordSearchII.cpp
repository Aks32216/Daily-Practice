#include <bits/stdc++.h>
using namespace std;

 int n,m;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    
    bool dfs(int x,int y,vector<vector<char> >& board,vector<vector<bool> >& visited,string word,int idx)
    {
        if(idx>=word.length())
            return true;
        if(x<0 || x>=n || y<0 || y>=m || visited[x][y]==true || board[x][y]!=word[idx])
            return false;
        visited[x][y]=true;
        bool cur=false;
        for(int i=0;i<4;++i)
        {
            int curx=x+dx[i];
            int cury=y+dy[i];
            cur=cur||dfs(curx,cury,board,visited,word,idx+1);
        }
        visited[x][y]=false;
        return cur;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n=board.size();
        m=board[0].size();
        unordered_map<char,vector<string> > mp;
        for(auto i:words)
        {
            mp[i[0]].push_back(i);
        }
        vector<string> res;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(mp.find(board[i][j])!=mp.end())
                {
                    vector<string> temp=mp[board[i][j]];
                    for(auto word:temp)
                    {
                        vector<vector<bool> > visited(n,vector<bool>(m,false));
                        if(dfs(i,j,board,visited,word,0))
                            res.push_back(word);
                    }
                }
            }
        }
        return res;
    }

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("../input.txt","r",stdin);
        freopen("../output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<string> word(n);
    for(auto& i:word)
        cin>>i;
    int x,y;
    cin>>x>>y;
    vector<vector<char> > v(x,vector<char>(y));
    for(int i=0;i<x;++i)
    {
        for(int j=0;j<y;++j)
        {
            cin>>v[i][j];
        }
    }
    vector<string> res=findWords(v,word);
    for(auto i:res)
        cout<<i<<" ";
    cout<<"\n";
}