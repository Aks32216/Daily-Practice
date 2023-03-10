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
 
pair<int,int> dp[50][50];
pair<int,int> solve(vector<int> &arr,int i,int j){
    if(i>j){
        return {0,1};
    }
    if(i==j){
        return {0,arr[j]};
    }
    if(dp[i][j].first!=-1){
        return dp[i][j];
    }
    pair<int,int> ans;
    ans.first = INT_MAX;
    for(int k=i;k<j;k++){
        pair<int,int> a = solve(arr,i,k);
        pair<int,int> b = solve(arr,k+1,j);
        ans.first =  min(ans.first,(a.second*b.second + a.first + b.first));
        ans.second = max(a.second,b.second);
    }
    dp[i][j].first = ans.first;
    dp[i][j].second = ans.second;
    return ans;
}
int mctFromLeafValues(vector<int>& arr) {
    memset(dp,-1,sizeof(dp));
    return solve(arr,0,arr.size()-1).first;
}

int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA
 
 	int n;
 	cin>>n;
 	vector<int> v(n);
 	for(auto& i:v)
 		cin>>i;      
 	cout<<mctFromLeafValues(v);
}