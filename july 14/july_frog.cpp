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

    vector< set<ll> > group(0);
    if(!pos.empty()){
        set < pair<ll,ll> >::iterator it = pos.begin();
        set <ll> gp;
        gp.insert(it->y);
        ll cDist = it->x;
        it++;
        for(;it!=pos.end();it++){
             if(it->x - cDist <= k){
                gp.insert(it->y);
                cDist = it->x;
                continue;
             }
             group.pb(gp);
             gp.clear();
             gp.insert(it->y);
             cDist = it->x;
        }
        group.pb(gp);
        gp.clear();
    }
    int f1,f2;
 /*   for(int j = 0;j<sz(group);j++){
        cout << "Group : " << j << endl;
        tr(group[j],iit) cout << *iit << " ";
        cout << endl;
    }
*/

    FOR(1,p,i){
        cin >> a >> b;
        f1 =0,f2 =0;
        for(int j = 0;j<sz(group);j++){
            if(present(group[j],a)) f1 =1;
            if(present(group[j],b)) f2 =1;
            if(f1 ==1 && f2 ==1){
                cout << "Yes" << endl;
                break;
            }
            if((f1 ==1 && f2 ==0) || (f1 == 0 && f2 == 1)){
                cout << "No" << endl;
                break;
            }
        }
    }
 return 0;
 }
