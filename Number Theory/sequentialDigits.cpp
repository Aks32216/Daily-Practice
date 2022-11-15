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
bool isSequential(int n){
    int cur=n%10;
    n/=10;
    while(n){
        int dig=n%10;
        if(cur-dig!=1)
            return false;
        cur=dig;
        n/=10;
    }
    return true;
}

vector<int> sequentialDigits(int low, int high) {
    vector<int> seqDigits;
    for(int i=low;i<=high;++i)
    {
        if(isSequential(i))
            seqDigits.push_back(i);
    }
    return seqDigits;
}
*/

vector<int> sequentialDigits(int low,int high){
	vector<int> res;
	int num=1;
	int mul=1;
	for(int i=2;i<=9;++i)
	{
		num=num*10+i;
		int curNum=num;
		mul=mul*10+1;
		for(int j=1;j<=(10-i);++j)
		{
			if(curNum>=low && curNum<=high)
				res.push_back(curNum);
			curNum+=mul;
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
 
 	int low,high;
 	cin>>low>>high;
 	vector<int> res=sequentialDigits(low,high);
 	for(auto i:res)
 		cout<<i<<" ";
 	cout<<"\n";
}