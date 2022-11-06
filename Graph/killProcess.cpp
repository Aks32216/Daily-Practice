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

vector<int> killProcesses(vector<int>& pid,vector<int>& ppid,int kill){
    int n=pid.size();
    unordered_map<int,vector<int> > graph;
    for(int i=0;i<ppid.size();++i){
        if(ppid[i]!=0){
            graph[ppid[i]].push_back(pid[i]);
        }
    }
    vector<int> res;
    queue<int> q;
    q.push(kill);
    while(!q.empty())
    {
        auto cur=q.front();
        q.pop();
        res.push_back(cur);
        for(auto child:graph[cur]){
            q.push(child);
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
 
       BRAHAMASTRA
 
 	int n;
    cin>>n;
    vector<int> pid(n),ppid(n);
    for(auto& i:pid)
        cin>>i;
    for(auto& i:ppid)
        cin>>i;
    int kill;
    cin>>kill;
    vector<int> res=killProcesses(pid,ppid,kill);
    for(auto i:res)
        cout<<i<<" ";
    cout<<"\n";      
}