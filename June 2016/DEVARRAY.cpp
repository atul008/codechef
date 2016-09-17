#include <bits/stdc++.h>
 
#define  F first
#define  S second
 
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define FOR(a,b,i) for(int i=a; i<=b; i++)
#define RFOR(a,b,i) for(int i=b; i>=a; i--)
#define SET(c,x) memset(c,x,sizeof(c))
#define pb push_back
#define mp make_pair

using namespace std;
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long ll;
 

int main1(){
	freopen("testCases.txt", "r", stdin);
	int n,q;
	cin >> n >> q;
	vi arr(n);
	int min = INT_MAX,max = INT_MIN;
	FOR(0,n-1,i){
		cin >> arr[i];
		if(min > arr[i])
			min = arr[i];
		if(max < arr[i])
			max = arr[i];
	}

	FOR(1,q,i){
		int a;
		cin >> a ;
		if(a>= min && a <= max){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	}
	return 0;
}
