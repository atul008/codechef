 #include <bits/stdc++.h>
 #define  F first
 #define  S second

 #define sz(a) int((a).size())
 #define all(c) (c).begin(),(c).end()
 #define tr(c,i) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
 #define present(c,x) ((c).find(x) != (c).end())
 #define cpresent(c,x) (find(all(c),x) != (c).end())
 #define FOR(a,b,i) for(int i=a; i<=b; i++)
 #define RFOR(a,b,i) for(int i=a; i>=b; i--)
 #define SET(c,x) memset(c,x,sizeof(c))
 #define pb push_back
 #define mp make_pair

 using namespace std;
 typedef vector<int> vi;
 typedef vector<vi> vvi;
 typedef pair<int,int> ii;
 typedef long long ll;

 int main(){
    ll n;
   // freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    ll arr[n];
    vector<pair<ll,ll> > v;
    string s;
    FOR(0,n-1,i){
        stringstream ss;
         cin >> arr[i];
         ss << arr[i];
         ss >> s;
         v.pb(mp(static_cast<ll>(s.length()),arr[i]));
    }
    sort(all(v));
    ll res=0,ml = v[n-1].F,f = 0;
    RFOR(n-1,0,i) {
        RFOR(i-1,0,j){
        if(v[i].F >= ml || v[j].S >=ml){
            ll a =arr[i],b = arr[j],c=0,d =1,k;
            while( a > 0 || b > 0){
                if((a%10) + (b%10) > 9)
                     c = d*10 + c;
                d *=10;
                a /=10;
                b /=10;
            }
            k = arr[i]+arr[j] - c;
            if(res < k) res = k;
        }else{
            f = 1;
            break;
        }
    } if(f == 1) break;
    }
    cout << res << endl;
 return 0;
 }
