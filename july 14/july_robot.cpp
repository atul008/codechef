 #include <map>
 #include <set>
 #include <vector>
 #include <list>
 #include <cmath>
 #include <cstring>
 #include <string>
 #include <sstream>
 #include <iostream>
 #include <algorithm>
 #define first x
 #define second y

 #define sz(a) int((a).size())
 #define all(c) (c).begin(),(c).end()
 #define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
 #define present(c,x) ((c).find(x) != (c).end())
 #define cpresent(c,x) (find(all(c),x) != (c).end())
 #define FOR(a,b,i) for(int i=a; i<=b; i++)
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
        ll ans,x,y;
        cin >> x >> y;
        x = abs(x);
        y = abs(y);
        if(x == y){
            ans = x+y;
            cout << ans << endl;
            continue;
        }

        ll m = min(x,y);
        x = x-m;
        y = y-m;

        if(x == 0){
            if(y%2 == 0)
                ans = 2*m + 2*y;
            else
                ans = 2*m + 2*y-1;
        }else{
            if(x%2 == 0)
                ans = 2*m + 2*x;
            else
                ans = 2*m + 2*x+1;
        }

        cout << ans << endl;
    }
 return 0;
 }
