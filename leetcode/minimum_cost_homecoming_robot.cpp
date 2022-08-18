#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <map>
#include <string.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
 
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

int n,m;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        n=rowCosts.size();
        m=colCosts.size();
        vector<vector<int> > costGrid(n,vector<int>(m,INT_MAX));
        queue<pair<int,int> > q;
        q.push({startPos[0],startPos[1]});
        costGrid[startPos[0]][startPos[1]]=0;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;++i)
                {
                    int curx=x+dx[i];
                    int cury=y+dy[i];
                    if(curx>=0 && cury>=0 && curx<n && cury<m)
                    {
                        if(i==0 || i==1)
                        {
                            if(costGrid[x][y]+rowCosts[curx]<costGrid[curx][cury])
                            {
                                costGrid[curx][cury]=costGrid[x][y]+rowCosts[curx];
                                q.push({curx,cury});
                            }
                        }
                        else
                        {
                            if(costGrid[x][y]+colCosts[cury]<costGrid[curx][cury])
                            {
                                costGrid[curx][cury]=costGrid[x][y]+colCosts[cury];
                                q.push({curx,cury});
                            }
                        }
                    }
                }
            }
        }
        return costGrid[homePos[0]][homePos[1]];
    }
 
int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA

       vector<int> startPos(2);
       cin>>startPos[0]>>startPos[1];
       vector<int> homePos(2);
       cin>>homePos[0]>>homePos[1];
       int n,m;
       cin>>n>>m;
       vector<int> rowCosts(n);
       for(auto& i:rowCosts)
       		cin>>i;
       vector<int> colCosts(m);
       for(auto& i:colCosts)
       		cin>>i;
       	cout<<minCost(startPos,homePos,rowCosts,colCosts)<<"\n";
}