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
 #define x first
 #define y second

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
    ll n,p,k,a,b;
    cin >> n >> k >> p;
    set < pair<ll,ll> > pos;

    FOR(1,n,i){
        cin >> a;
        pos.insert(mp(a,i));
    }
    int no = 0;
    vi group(n+1,-1);

    if(!pos.empty()){
        set < pair<ll,ll> >::iterator it = pos.begin();
        group[it->y] = no;
        int cDist = it->x;
        it++;
        for(;it!=pos.end();it++){
             if(it->x - cDist <= k){
                group[it->y] = no;
                cDist = it->x;
                continue;
             }
             no++;
             group[it->y] = no;
             cDist = it->x;
        }
    }
  /*  cout << "group " << endl;
    for(int j = 1;j<sz(group);j++){
        cout << group[j] << " ";
    }
    cout << endl;
*/

    FOR(1,p,i){
        cin >> a >> b;
        if(group[a] == group[b])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
 return 0;
 }
