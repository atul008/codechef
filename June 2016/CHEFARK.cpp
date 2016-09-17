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

#define MAX 100
#define MOD 1000000007

int powMod(int n)
{
    int ret = 1;
    int a = 2;
    while (n > 0) {
        if (n & 1)
        	ret = ((ret%MOD) * (a % MOD))%MOD;
        a = ((a %MOD) * (a % MOD))%MOD;
        n >>= 1;
    }
    return ret;
}
void c(int n,vi& row) {
    int i, j;
    row[0] = 1;
    for(i = 1; i <= n; i++) {
        for(j = i; j > 0; j--) {
             row[j] = (row[j]%MOD +  row[j - 1]%MOD)%MOD;
        }
    }
}

int main(){
	//freopen("testCases.txt", "r", stdin);
	int t;
	cin >> t;
	while(t--){
		int n,x;
		cin >> n >> x;
		int a,f=0;
		FOR(0,n-1,i){
			cin >> a;
			if(a == 0)
				f++;
		}
		if(n == 1){
			cout << 1 << endl;
			continue;
		}
		ll ans = 0;
		if(f == 0){
			if(x > n){
				if(n%2 == x%2){
					x=n;
				}else{
					x = n-1;
				}
				ans = powMod(x-1);
			}else{
				int i=1;
				if(x %2 == 0){
					i = 0;
				}
				vi row(n+1,0);
				c(n,row);
				for(;i<=x;i = i+2){
					ans = ((ans%MOD) + (row[i]%MOD))%MOD;
				}
			}
		}else{
			n = n-f;
			x = n;
			ans = powMod(x);
		}
		cout << ans << endl;
	}
return 0;
}
