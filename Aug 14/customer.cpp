 #include <map>
 #include <set>
 #include <vector>
 #include <list>
 #include <deque>
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
 #define INF 999999999
 using namespace std;
 typedef vector<int> vi;
 typedef vector<vi> vvi;
 typedef pair<int,int> ii;
 typedef long long ll;


 int main(){
    int t,n,m;
    cin >> t;
    while(t--){
        int cleanCount = 0;
        cin >> n >> m;
        vi orders(m);
        vector<deque<int> > index(401);

        FOR(0,m-1,i){
             cin  >> orders[i] ;
             index[orders[i]].pb(i);
        }

        FOR(0,400,i) index[i].pb(INF);

        vi tables(n,0);
        int flag = 0,loc,val = -1,no = 0;
        FOR(0,m-1,i){
            flag = 0;
            loc = -1,val  = -1;
            FOR(0,n-1,j){

                if(tables[j] == orders[i]){
                    index[orders[i]].pop_front();
                    flag = 1;
                    break;
                }
                if( val < index[tables[j]].front()){
                    val = index[tables[j]].front();
                    loc = j;
                }

            }
            if(flag == 1) continue;
             if(no <= n-1){
                    cleanCount++;
                  //  cout << orders[i] << " : " << cleanCount << endl;
                    tables[no] = orders[i];
                    index[orders[i]].pop_front();
                    no++;
                    continue;
             }
            if(loc < 0){
                tables[0] = orders[i];
                index[orders[i]].pop_front();
                cleanCount++;
              //  cout << orders[i] << " : " << cleanCount << endl;
            }else{
                tables[loc] = orders[i];
                index[orders[i]].pop_front();
                cleanCount++;
                //cout << orders[i] << " : " << cleanCount << endl;
            }
        }
        cout << cleanCount << endl;
    }
 return 0;
 }
