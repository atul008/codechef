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

int main4(){
	freopen("testCases.txt", "r", stdin);
	int t;
	cin >> t;
	while(t--){
		ll k;
		cin >> k;
		vector<ll> base5;
		if(k == 1){
			cout << 0 << endl;
			continue;
		}
		k = k-1;
		while(k > 0){
			base5.push_back(k%5);
			k = k/5;
		}
		RFOR(0,sz(base5)-1,i){
			cout << 2*base5[i];
		}
		cout << endl;
	}

	return 0;
}
