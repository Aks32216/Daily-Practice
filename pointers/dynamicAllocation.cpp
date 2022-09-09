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
 
int main()
{
       #ifndef ONLINE_JUDGE
              freopen("../input.txt","r",stdin);
              freopen("../output.txt","w",stdout);
       #endif
 
       BRAHAMASTRA
 
 	// using c style allocation
 	// calloc and malloc

 	// using malloc
 	// stands for memory allocation'
 	// takes one argument -> size of the array to be created
 	// returns void* type pointer which can be casted to any other type pointer
 	// does not initialize memory blocks thus each element has garbage value
    // returns null if allocation was unsuccessfull

 	int n;
 	cin>>n;
 	cout<<"------------- Malloc -------------------------\n";
 	int* ptr=(int*)malloc(n*sizeof(int));
 	if(ptr==NULL){
 		cout<<"Memory not allocated\n";
 	}
 	else
 	{
 		for(int i=0;i<n;++i){
 			cin>>ptr[i];
 		}
 		for(int i=0;i<n;++i)
 		{
 			cout<<*(ptr+i)<<" ";
 		}
 		cout<<"\n";
 	}

 	cout<<"-------------- Calloc -----------------------\n";
 	// stands for contiguous allocation
 	// takes two argument 1. size of the array 2. size of each block
 	// assigns each memory block with 0
 	// return the type of pointer requested for
 	// returns NULL if memory allocation fails

 	int* ptr2=(int*)calloc(n,sizeof(int));
 	if(ptr2==NULL){
 		cout<<"Memory not allocated\n";
 	}
 	else{
 		for(int i=0;i<n;++i){
 			cin>>*(ptr2+i);
 		}
 		for(int i=0;i<n;++i){
 			cout<<ptr[i]<<" ";
 		}
 		cout<<"\n";
 	}

 	// free pointer frees the dynamically allocated memory once does not require
 	// it must be done manually

 	free(ptr);
 	free(ptr2);

 	cout<<"-------------------- New -------------------\n";
 	// new is keyword
 	// calls constructor

 	int* arr=new int[n];
 	for(int i=0;i<n;++i){
 		cin>>arr[i];
 	}
 	for(int i=0;i<n;++i){
 		cout<<arr[i]<<" ";
 	}
 	cout<<"\n";
}