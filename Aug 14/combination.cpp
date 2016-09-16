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
 #include <climits>
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

 using namespace std;
 typedef vector<int> vi;
 typedef vector<vi> vvi;
 typedef pair<int,int> ii;
 typedef long long ll;


 int main(){
     int t,n;
     cin >> t;
     while(t--){
        cin >> n;
        vvi box(n,vi(101,0));
        vi  count(n,0);
        int a;
        string s;
        stringstream ss ;
        cin.ignore(INT_MAX,'\n');
        cin.clear();
        FOR(0,n-1,i){
            getline(cin,s);
            cout << "s : " << s << endl;
            ss << s;
            while(ss >> a){
                box[i][a] = 1;
                count[i]++;
            }
            ss.clear();
        }
        int64_t res = 0;
/*        tr(count,it) cout << *it << " ";
        cout << endl;
        FOR(0,n-1,i){
             FOR(1,100,j) cout << box[i][j] << " " ;
            cout << endl;
        }
*/
        FOR(0,0,i){
            FOR(1,100,j){
                int temp = 1;
                if(box[i][j] == 1){
                    FOR(0,n-1,k){
                        if(i != k && box[k][j] == 1){
                            temp *= count[k]-1;
                        }else{
                            temp *= count[k];
                        }
                    }
                    cout << "temp : " << temp;
                    res += temp;
                }
            }
        }
        cout << res << endl;
     }

 return 0;
 }
