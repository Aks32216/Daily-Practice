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
 
/* bool isPossible(int idx,vector<int>& gas,vector<int>& cost)
{
    int sum=0;
    for(int i=0;i<gas.size();++i)
    {
        sum=sum+gas[idx]-cost[idx];
        if(sum<0)
            return false;
        idx=(idx+1)%gas.size();
    }
    return true;
}

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n=gas.size();
    for(int i=0;i<n;++i)
    {
        if(isPossible(i,gas,cost))
            return i;
    }
    return -1;
}
*/

int canCompleteCircuit(vector<int>& gas,vector<int>& cost){
	int rear=0;
	int sum=0;
	int n=gas.size();
	int tank=0;
	for(int i=0;i<n;++i)
	{
		sum+=gas[i]-cost[i];
		if(sum<0)
		{
			rear=i+1;
			tank+=sum;
			sum=0;
		}
	}
	if(tank+sum>=0)
		return rear;
	else
		return -1;
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
 	vector<int> gas(n),cost(n);
 	for(auto& i:gas)
 		cin>>i;
 	for(auto& i:cost)
 		cin>>i;
 	cout<<canCompleteCircuit(gas,cost)<<"\n";
}