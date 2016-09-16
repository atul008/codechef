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
    ll n;
    double a,f,ang = 0;
    string s;
    cin >> n >> s >> a >> f;
    if(a >= f){
        cout << "NO\n";
        return 0;
    }
    ang = a;
    FOR(1,n-1,i){
        if(ang >= f){
            cout << "NO\n";
            return 0;
        }
        if(s[i] == s[i-1]){
            ang =ang + a;
        }else{
            ang =ang-a;
        }
        if(ang<0) ang = -ang;
       // cout << "ang : " << ang << endl;
    }
    if(ang >= f)
        cout << "NO\n";
    else
        cout << "YES\n";

 return 0;
 }
