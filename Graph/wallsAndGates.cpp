#include <bits/stdc++.h>
 
using namespace std;
#define set_precision cout << fixed << setprecision(10)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repb(i, a, b) for (int i = a; i >= b; i--)
#define replb(i, a, b) for (ll i = a; i >= b; i--)
#define repl(i, a, b) for (ll i = a; i < b; i++)
#define repit(arr) for (auto it = arr.begin(); it != arr.end(); 
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vl vector<long long int>
#define Vi vector<vector<int>>
#define vpi vector<pair<int,int> >
#define seti set<int>
#define setl set<ll>
#define dseti set<int, greater<int>>
#define dsetl set<ll, greater<ll>>
#define mseti multiset<int>
#define msetl multiset<ll>
#define dmseti multiset<int, greater<int>>
#define dmsetl multiset<ll, greater<ll>>
#define sortA(arr) sort(arr.begin(), arr.end())
#define dsortA(arr) sort(arr.begin(), arr.end(), greater<int>())
#define ssort(arr) stable_sort(arr.begin(), arr.end())
#define search(arr, c) binary_search(arr.begin(), arr.end(), c)
#define pb push_back
#define ll long long
#define cl_bf cin.ignore(numeric_limits<streamsize>::max(), '\n');
#define castl static_cast<ll>
#define BRAHAMASTRA ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ull unsigned long long int
#define mod 1e9+7

int n,m;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void wallsAndGates(vector<vector<int> >& v)
{
    queue<pair<int,int> > q;
    n=v.size();
    m=v[0].size();
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(v[i][j]==0)
                q.push({i,j});
        }
    }
    int curDist=0;
    while(!q.empty())
    {
        int size=q.size();
        while(size--)
        {
            auto cur=q.front();
            q.pop();
            int x=cur.first;
            int y=cur.second;
            if(v[x][y]<=0)
                v[x][y]=curDist;
            else if(v[x][y]>curDist)
                v[x][y]=curDist;
            for(int i=0;i<4;++i)
            {
                int curx=x+dx[i];
                int cury=y+dy[i];
                if(curx<0 || cury<0 || curx>=n || cury>=m || v[curx][cury]==0 || v[curx][cury]==-1)
                    continue;
                if(v[curx][cury]==-2)
                    q.push({curx,cury});
            }
        }
        curDist++;
    }
}
 
int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA
 
 	int r,c;
    cin>>r>>c;
    vector<vector<int> > v(r,vector<int>(c));
    for(int i=0;i<r;++i)
    {
        for(int j=0;j<c;++j)
        {
            cin>>v[i][j];
        }
    }
    wallsAndGates(v);
    for(int i=0;i<r;++i)
    {
        for(int j=0;j<c;++j)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }      
}