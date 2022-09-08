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

/*int maxRepeating(int *arr, int n, int k) {
    int element=-1,elemCount=0;
    for(int i=0;i<n;++i){
        int count=0;
        for(int j=0;j<n;++j){
            if(arr[j]==arr[i])
                count++;
        }
        if(count>elemCount){
            elemCount=count;
            element=arr[i];
        }
        else if(count==elemCount)
            element=min(element,arr[i]);
    }
    return element;
}*/

/*int maxRepeating(int arr[],int n,int k){
    vector<int> freq(k,0);
    for(int i=0;i<n;++i){
        freq[arr[i]]++;
    }
    int element=-1,elemCount=0;
    for(int i=0;i<k;++i){
        if(freq[i]>elemCount){
            elemCount=freq[i];
            element=i;
        }
    }
    return element;
}*/
    
int maxRepeating(vector<int>& arr,int n,int k)
{
	for(int i=0;i<n;++i)
	{
		arr[arr[i]%k]+=k;
	}
	int mx=0,idx=0;
	for(int i=0;i<n;++i)
	{
		if(arr[i]>mx)
		{
			mx=arr[i];
			idx=i;
		}
	}
	return idx;
}
 
int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA
 
 	int n,k;
 	cin>>n>>k;
 	vector<int> v(n);
 	for(auto& i:v)
 		cin>>i;
 	cout<<maxRepeating(v,n,k)<<"\n";
}