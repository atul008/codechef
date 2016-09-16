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
 const ll mod = 1000000007;

 void lcm(vi& a,vi& b){
    FOR(0,min(sz(a),sz(b))-1,i){
        a[i] = max(a[i],b[i]);
    }
 }

 void primeList(int n,vi& pList){
    pList.pb(2);
    int flag;
    FOR(3,n,i){
        flag =0;
        FOR(2,sqrt(i),j){
            if(i%j == 0){
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            pList.pb(i);
    }
 }

 void primeFactor(int n,vi& res,vi& pList){
    int i = 0,count;

    while(n > 1){
        count =0;
        while(n%pList[i] == 0 ){
            count++;
            n = n/pList[i];
        }
        i++;
        res.pb(count);
    }
 }

 int main(){
    int t;
    cin >> t;
    vi pList(0);
    primeList(100002,pList);
    while(t--){
        int n ;
        cin >> n;
        vi pos(n+1),vis(n+1,0),group(n+1,0);
        pos[0] = 0;
        vis[0] = 1;
        FOR(1,n,i) cin >> pos[i];
        int no = 0;
        FOR(1,n,i){
            if(!vis[i]){
                int k = i;
                no++;
                while(!vis[k]){
                        group[k] = no;
                        vis[k] = 1;
                        k =pos[k];
                }
            }
        }
/*
        cout << "group : ";
        tr(group,it) cout << *it << " ";
        cout << endl;
*/
        vector<ll> count(no+1,0);

        FOR(1,n,i){
            count[group[i]]++;
        }

        vvi cPfactor(no+1);
        FOR(1,no,i) primeFactor(count[i],cPfactor[i],pList);

        vi ans(25000,0);

        FOR(1,no,i){
            lcm(ans,cPfactor[i]);
        }

        ll res = 1;
        FOR(0,sz(ans)-1,i){
            res = (res * pow(pList[i],ans[i]));
            res = res%mod;
        }
        cout << res << endl;

        /*ll ans = count[1];
        FOR(2,no,i){
            ll g = gcd(ans,count[i]);
            ll div = count[i]/g;
            ans = ans*div;
        }
        cout << ans%mod << endl;*/
    }
 return 0;
 }
