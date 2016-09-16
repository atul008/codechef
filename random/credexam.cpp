 #include <bits/stdc++.h>
 #define  x first
 #define  y second

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

 int main(){
    ll n,m;
    cin >> m >> n;
    ll arr[m];
    FOR(0,m-1,i) cin >> arr[i];
    if(n%2 == 1){
        ll c = 0,x = (n/2);
        FOR(0,m-1,i){
            if(arr[i] > x){
                if(c == 0 && arr[i] == x + 1){
                    c++;
                }else{
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }else{
        ll x = n/2;
        FOR(0,m-1,i){
            if(arr[i] > x){
                cout << "NO\n";
                return 0;
            }

        }
    }
    cout << "YES\n";

 return 0;
 }
