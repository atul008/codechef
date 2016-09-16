 #include <bits/stdc++.h>
 #define  F first
 #define  S second

 #define sz(a) int((a).size())
 #define all(c) (c).begin(),(c).end()
 #define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
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
 #define mod 1000000007
 vvi arr(105);
 ll dp[1025][105];
 int p;
 ll recur(int mask,int shirtId){
    if(shirtId == 101){
        if(mask == p){
            return dp[mask][shirtId] = 1ll;
        }else{
            return dp[mask][shirtId] = 0ll;
        }
    }
    if(dp[mask][shirtId] != -1) return dp[mask][shirtId];
    ll ans = 0;
    ans = ans + recur(mask,shirtId+1);
    int n = sz(arr[shirtId]);
    FOR(0,n-1,i){
        if((mask) & (1 << arr[shirtId][i])) continue;
        ans = ans + recur(((mask) | (1 << arr[shirtId][i])),shirtId + 1);
        ans = ans % mod;
    }
    return dp[mask][shirtId] = ans;
 }


 int main(){
     int t,n;
     cin >> t;
     while(t--){
        int a;
        string s;
        stringstream ss ;
        cin >> n;
        getchar();
        FOR(0,104,i) arr[i].clear();
        SET(dp,-1);
        FOR(0,n-1,i){
            getline(cin,s);
            ss << s;
            while(ss >> a){
                arr[a].pb(i);
            }
            ss.clear();
        }
        FOR(1,100,i) sort(all(arr[i]));
        p = (1<<n)-1;
        cout << recur(0,1) << endl;
     }

 return 0;
 }
