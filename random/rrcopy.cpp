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
    int t,n;
    int v[100005],arr[100005];
    cin >> t;
    while(t--){
        cin >> n;
        SET(v,0);
        FOR(0,n-1,i){
            cin >> arr[i];
            v[arr[i]] = 1;
        }
        int res = 0 ;
        FOR(1,100000,i) if(v[i]) res++;
        cout << res << endl;
    }
 return 0;
 }
