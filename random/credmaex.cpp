 #include <bits/stdc++.h>

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
    int t;
    cin >> t;
    while(t--){
        ll z,a,b,c,d,x,y;
        cin >> z;
        cin >> a >> b >> c >> d >> x >> y;
        ll m = 1,res = 1;
        while(x > m || y > m) m = m*2;
        while(m > 1){
            if((x >=1 && x <=m/2) && (y>=1 && y<=m/2)){
                res *= a;
            }else if((x >=1 && x <=m/2) && (y>=(m/2) +1 && y<=m)){
                res *= b;
            }else if((x >=(m/2)+1 && x <=m) && (y>=1 && y<=m/2)){
                res *= c;
            }else{
                res *=d;
            }
            if(x > m/2) x = x-m/2;
            if(y > m/2) y = y-m/2;
            m = m/2;
        }
        res *= z;
        cout << res << endl;
    }
 return 0;
 }
