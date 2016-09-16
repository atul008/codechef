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
 #define  x first
 #define  y second

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
 #define INF 99999999
 using namespace std;
 typedef vector<int> vi;
 typedef vector<vi> vvi;
 typedef pair<int,int> ii;
 typedef long long ll;
 #define MAX 1000000000

 int main(){
    int t;
    cin >> t;
    while(t--){
        int64_t x,y;
        cin >> x >> y ;
        if(x == 0 && y ==0){
            cout << "YES\n";
            continue;
        }

        if( x >= 0 && y >= 0 ){
            if(x%2 == 1 && y <= x+1){
                cout << "YES\n";
                continue;
            }
            if(y%2 ==0 && x <= y-1 ){
                cout << "YES\n";
                continue;
            }
           cout << "NO\n";

        } else if( x >= 0 && y <= 0 ){
            y = -y;
            if(x%2 == 1 && y<= x-1){
                cout << "YES\n";
                continue;
            }
            if(y%2 ==0 && x<=y+1){
                cout << "YES\n";
                continue;
            }
            cout << "NO\n";

        } else{
            if(x < 0) x = -x;
            if(y < 0) y = -y;
            if(x%2==0 && y<=x){
                cout << "YES\n";
                continue;
            }
            if(y%2==0 && x <=y){
                cout << "YES\n";
                continue;
            }
            cout << "NO\n";

        }

    }
 return 0;
 }
