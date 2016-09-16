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
    int n;
    cin >> n;
    vector<string> v(n);
    FOR(0,n-1,i) cin >> v[i];
    map<string,int> m;
    int l = 1;
    cout << l << " " << v[0] << endl;
    l++;
    m[v[0]] = 1;
    FOR(1,n-1,i){
        if(present(m,v[i])){
            int k = ++m[v[i]];
           // cout <<"-- " << v[i] << " " << k << endl;
            if(l == k ){
                cout << l <<" "<<v[i] << endl;
                l++;
            }
        }else{
            //m.insert(mp(v[i],1));
         //   cout <<"++ " << v[i]<< endl;
            m[v[i]] = 1;
        }
    }
 return 0;
 }
