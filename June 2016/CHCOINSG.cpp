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

int main2(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		if(n%6 == 0){
			cout << "Misha" << endl;
		}else{
			cout << "Chef" << endl;
		}
	}
	return 0;
}
