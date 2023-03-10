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
// #define mod 1e9+7
 
vector<int> NSL(vector<int> v)
{
    int n=v.size();
    stack<pair<int,int> > s;
    vector<int> res;
    for(int i=0;i<n;++i)
    {
        if(s.empty())
            res.push_back(-1);
        else if(s.top().first<v[i])
            res.push_back(s.top().second);
        else if(s.top().first>=v[i])
        {
            while(!s.empty() && s.top().first>=v[i])
                s.pop();
            if(s.empty())
                res.push_back(-1);
            else
                res.push_back(s.top().second);
        }
        s.push({v[i],i});
    }
    return res;
}

vector<int> NSR(vector<int> v)
{
    int n=v.size();
    stack<pair<int,int> > s;
    vector<int> res(n);
    for(int i=n-1;i>=0;--i)
    {
        if(s.empty())
            res[i]=n;
        else if(s.top().first<=v[i])
            res[i]=s.top().second;
        else if(s.top().first>v[i])
        {
            while(!s.empty() && s.top().first>v[i])
                s.pop();
            if(s.empty())
                res[i]=n;
            else
                res[i]=s.top().second;
        }
        s.push({v[i],i});
    }
    return res;
}


int sumSubarrayMins(vector<int>& arr) 
{
    int n=arr.size();
    vector<int> nsr,nsl;
    nsr=NSR(arr);
    nsl=NSL(arr);
    for(auto i:nsr)
        cout<<i<<" ";
    cout<<"\n";
    for(auto i:nsl)
        cout<<i<<" ";
    cout<<"\n";
    long long int ans=0;
    int mod=1e9+7;
    for(int i=0;i<n;i++)
    {
        ans=(ans%mod + (long)arr[i]*(i-nsl[i])*(nsr[i]-i))%mod;
        ans=ans%mod;
    }
    return ans % 1000000007;
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
 	cout<<sumSubarrayMins(v)<<"\n";
}