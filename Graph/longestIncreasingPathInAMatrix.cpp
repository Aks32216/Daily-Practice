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

bool isValid(int x,int y)
{
    return x>=0 && x<n && y>=0 && y<m;
}

int findLength(int x,int y,vector<vector<int> >& cache,vector<vector<int> >& matrix)
{
    if(cache[x][y]!=-1)
        return cache[x][y];
    int maxDirPath=1;
    for(int i=0;i<4;++i)
    {
        int curx=x+dx[i];
        int cury=y+dy[i];
        if(isValid(curx,cury) && matrix[x][y]<matrix[curx][cury])
            maxDirPath=max(maxDirPath,findLength(curx,cury,cache,matrix)+1);
    }
    cache[x][y]=maxDirPath;
    return maxDirPath;
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    n=matrix.size();
    m=matrix[0].size();
    vector<vector<int> > cache(n,vector<int>(m,-1));
    int maxLength=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(cache[i][j]==-1)
            {
                maxLength=max(maxLength,findLength(i,j,cache,matrix));
            }
        }
    }
    return maxLength;
}
 
int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA
 
 	int rows,cols;
 	cin>>rows>>cols;
 	vector<vector<int> > matrix(rows,vector<int>(cols));
 	for(int i=0;i<rows;i++)
 	{
 		for(int j=0;j<cols;++j)
 		{
 			cin>>matrix[i][j];
 		}
 	}      
 	cout<<longestIncreasingPath(matrix);
}