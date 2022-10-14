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
 
/*
void dfs(vector<vector<char>>& board, int i, int j){
    if(i<0 || j<0 || i>=board.size() || j>=board[i].size() || board[i][j]!='X'){
        return;
    }
    board[i][j]='.';
    dfs(board,i+1,j);
    dfs(board,i-1,j);
    dfs(board,i,j-1);
    dfs(board,i,j+1);
}
int countBattleships(vector<vector<char>>& board) {
    int ans = 0;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            if(board[i][j]=='X'){
                ans++;
                dfs(board,i,j);
            }
        }
    }
    return ans;
}
*/
int countBattleships(vector<vector<char>>& board) {
	int ans = 0;
	for(int i=0;i<board.size();i++){
		for(int j=0;j<board[i].size();j++){
			if(board[i][j]=='.'){
				continue;
			}
			if(i>0 && board[i-1][j]=='X'){
				continue;
			}
			if(j>0 && board[i][j-1]=='X'){
				continue;
			}
                ans++;   // counting the number of heads of battles
            }
        }
        return ans;
    }

int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA
 
 	int n,m;
 	cin>>n>>m;
 	vector<vector<char> > v(n,vector<char>(m));
 	for(int i=0;i<n;++i)
 	{
 		for(int j=0;j<m;++j)
 		{
 			cin>>v[i][j];
 		}
 	}  
 	cout<<countBattleships(v)<<"\n";    
}