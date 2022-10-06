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
int ans=INT_MAX;

void dfs(int x,int y,int curSteps,int k,vector<vector<int> >& grid)
{
        // cout<<x<<" "<<y<<" "<<curSteps<<" "<<k<<"\n";
	if(x<0 || y<0 || y>=m || x>=n || k<0 || grid[x][y]==-1)
		return;
	if(x==n-1 && y==m-1 && k>=0)
	{
		ans=min(ans,curSteps);
		return;
	}
	bool isObstacle=false;
	if(grid[x][y]==1)
	{
		isObstacle=true;
		grid[x][y]=0;
		k--;
	}
	else
		grid[x][y]=-1;
	for(int i=0;i<4;++i)
	{
		int curx=x+dx[i];
		int cury=y+dy[i];
		dfs(curx,cury,curSteps+1,k,grid);
	}
	if(isObstacle)
		grid[x][y]=1;
	else
		grid[x][y]=0;
}

int shortestPath(vector<vector<int>>& grid, int k) {
	int m = grid.size();
	int n = grid[0].size();
        // This vector stores the number of obstacles that we can still remove after walking through that cell
	vector<vector<int>> visited(m, vector<int>(n, -1));

	queue<vector<int>> q;
        // x, y, currentLength, remaining k
	q.push({0,0,0,k});
	while(!q.empty()){

		auto t = q.front();
		q.pop();

		int x = t[0], y = t[1];

            // Invalid cases being dealt here since it's easier to write one condition instead of 4 while pushing.
		if(x<0 || x>=m || y<0 || y>=n)
			continue;

            // If you've reached the end, great, return the currentLength!
		if(x == m-1 && y == n-1)
                return t[2]; //currentLength of the path

            // If we hit an obstacle & we don't have any Ks remaining, continue
            // If we still have Ks to spend, we spend 1.
            if(grid[x][y] == 1){
            	if(t[3] > 0)
            		t[3]--;
            	else
            		continue;
            }
            
            // If this cell is already visited with a K value lesser than this one, we would want to save Ks for future use, so we continue
            // This is the most important condition and part of the solution!
            if(visited[x][y]!=-1 && visited[x][y] >= t[3]){
            	continue;
            }
            
            // We store the currentRemaining K after spending K (if required) into the visited matrix.
            visited[x][y] = t[3];

            // Push the adjacent nodes in the queue.
            q.push({x+1, y, t[2]+1, t[3]});
            q.push({x-1, y, t[2]+1, t[3]});
            q.push({x, y+1, t[2]+1, t[3]});
            q.push({x, y-1, t[2]+1, t[3]});
        }
        
        return -1;
    }
 
int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA
 
 	int r,c,k;
 	cin>>r>>c>>k;
 	vector<vector<int> > v(r,vector<int>(c));
 	for(int i=0;i<r;++i)
 	{
 		for(int j=0;j<c;++j)
 		{
 			cin>>v[i][j];
 		}
 	}      
 	cout<<shortestPath(v,k)<<"\n";
}