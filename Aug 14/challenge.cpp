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

 using namespace std;
 typedef vector<int> vi;
 typedef vector<vi> vvi;
 typedef pair<int,int> ii;
 typedef long long ll;


 int main(){
    int n;
    int64_t sl = 0,sr = 0,diff;
    cin >> n;
    list<int> arr;
    arr.pb(0);
    int a;
    FOR(1,n,i){
         cin >> a;
         arr.pb(a);
         if(i <=n/2)
            sl += a;
        else
            sr += a;
    }
    int l ,r;
    int64_t iterVal = 0;
    vector<ii> res;
    while(iterVal <= 2){
        l = rand()%(n/2) + 1;
        r =  n/2 + rand()%(n/2) + 1 ;
        if(r == n) r--;
        //cout << "l :" << l << " " << " r: " << r << endl;
        iterVal += r-l+1;
        res.pb(mp(l,r));
        int count = -1,lval,midVal;
        list<int>::iterator it2;
        tr(arr,it){
            count++;
            if(count == l){
                lval = *it;
               it2 = it;
            }
            if(count == n/2 + 1) midVal = *it;
            if(count == r+1){
                arr.insert(it,lval);
                break;
            }
        }
         arr.erase(it2);


      //  tr(arr,it1) cout << *it1 << " ";

        sl += midVal - lval;
        sr += lval - midVal;

    }
    cout << sz(res) << endl;

    tr(res,it){
        cout << it->x << " " << it->y << endl;
    }
 return 0;
 }
