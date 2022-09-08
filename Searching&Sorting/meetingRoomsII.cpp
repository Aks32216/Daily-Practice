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

class Interval{
public:
	int start,end;
	Interval(){

	}

	Interval(int start,int end){
		this->start=start;
		this->end=end;
	}

	void setInterval(int a,int b){
		start=a;
		end=b;
	}

	void putInterval(){
		cout<<start<<" "<<end<<"\n";
	}
};

int minMeetingRooms(vector<Interval> &intervals) {
        // Check for the base case. If there are no intervals, return 0
	if (intervals.size() == 0) {
		return 0;
	}

	vector<int> start(intervals.size());
	vector<int> end(intervals.size());

	for (int i = 0; i < intervals.size(); i++) {
		start[i] = intervals[i].start;
		end[i] = intervals[i].end;
	}

        // Sort the intervals by end time
	sort(end.begin(), end.end());

        // Sort the intervals by start time
	sort(start.begin(), start.end());

        // The two pointers in the algorithm: e_ptr and s_ptr.
	int startPointer = 0, endPointer = 0;

        // Variables to keep track of maximum number of rooms used.
	int usedRooms = 0;

        // Iterate over intervals.
	while (startPointer < intervals.size()) {

        // If there is a meeting that has ended by the time the meeting at `start_pointer` starts
		if (start[startPointer] >= end[endPointer]) {
			usedRooms -= 1;
			endPointer += 1;
		}

        // We do this irrespective of whether a room frees up or not.
        // If a room got free, then this used_rooms += 1 wouldn't have any effect. used_rooms would
        // remain the same in that case. If no room was free, then this would increase used_rooms
		usedRooms += 1;
		startPointer += 1;

	}

	return usedRooms;
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
 	vector<Interval> v(n);
 	for(int i=0;i<n;++i){
 		int a,b;
 		cin>>a>>b;
 		v[i].setInterval(a,b);
 	}
 	cout<<minMeetingRooms(v)<<"\n";
}