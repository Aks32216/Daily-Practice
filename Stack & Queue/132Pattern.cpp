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
bool find132pattern(vector<int>& nums) {
    int n=nums.size();
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            for(int k=j+1;k<n;++k)
            {
                if(nums[j]>nums[i] && nums[j]>nums[k] && nums[k]>nums[i])
                    return true;
            }
        }
    }
    return false;
}
*/
    
    
bool find132pattern(vector<int>& nums)
{
	int n=nums.size();
	if(n<3)
		return false;
	vector<int> minArray(n);
	minArray[0]=nums[0];
    // construct a prefix min array which will tell that from ith index what is the minimum elemnt towards its left
	for(int i=1;i<n;++i)
	{
		minArray[i]=min(nums[i],minArray[i-1]);
	}
	stack<int> s;
    // maintain a stack and keep pushing elment to it from right
    // whenver you find that top of stack is less than current element and top of stack is greater than min of elements toward left of current index then return true
	for(int i=n-1;i>=0;--i)
	{
        while(!s.empty() && s.top()<nums[i]) // check if any elemnt in right is smaller than current elemnt if yes let that element be at top of stack
        {
            if(s.top()>minArray[i]) // if second smaller element is grater than min element from left of curent idx then return true
             	return true;
            s.pop(); // otherwise we dont need this element as it is of no use to us
        }
        s.push(nums[i]); // push the current element for further element
    }
    return false; // not found return false
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
 	cout<<find132pattern(v)<<"\n";
}