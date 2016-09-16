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
    ll n,m,q,a,b,c,d;
    cin >> n >> m;
    while(m--){
        cin >> q;
        if(q < n+2 || q > 3*n){
            cout << "0" << endl;
            continue;
        }
       /* a = q-1,b = q-n,c = q-(n+1),d = q - (2*n);
        if( (a >= n+1 && a <= 2*n) && (c >= 1 && c <= n )){
            cout << c << endl;
            continue;
        }
        if((b >= n+1 && b <= 2*n) && (d >= 1 && d <= n )){
            cout << d-n+1 << endl;
            continue; */
        if(q - 1 >= n+1 && q-1 <= 2*n){
            cout << q-n-1 << endl;
            continue;
        }
        if(q-n >= n+1 && q-n <= 2*n){
            cout << 3*n-q + 1 << endl;
            continue;
        }

        }

 return 0;
 }
