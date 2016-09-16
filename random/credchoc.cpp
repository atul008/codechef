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
 ll count(vector<ll>& s,ll m,ll n){
    vector<ll> t(n+1,0);
    t[0] = 1;
    FOR(0,m-1,i) FOR(s[i],n,j) t[j] += t[j-s[i]];
    return t[n];
 }

 int main(){
    ll n,x,y,a;
    cin >> n >> x >> y;
    vector<ll> s(n);
    FOR(0,n-1,i){
         cin >> a;
         s[i] = a-1;
    }
    if(count(s,n,y-x) == 0)
        cout << "IMPOSSIBLE\n";
    else
        cout << "POSSIBLE\n";
 return 0;
 }
