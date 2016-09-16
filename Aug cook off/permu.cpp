 #include <bits/stdc++.h>
 #define  F first
 #define  S second

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
 int t,m,n;
 cin >> t;
 while(t--){
    cin >> n >> m;
    int arr[n+1];
    vector<ii> st(m+1);
    FOR(1,n,i) cin >> arr[i];
    ii a ;
    a.F = -1;
    a.S = -1;
    st[0] = a;
    FOR(1,m,i){
        cin  >> a.F >> a.S;
        st[i] = a;
    }
    sort(all(st));
    int b,e,k;
    int flag = 0;
    if(st[1].F > 1){
        b = 1;
        e = st[1].F-1;
            FOR(b,e,j){
                if(arr[j] != j){
                    cout << "Impossible" << endl;
                    flag = 1;
                    break;
                }
            }
    }
    if(flag == 1) continue;

    flag = 0;
    int g = 0;
    b = 1;
    e = 1;
    for(int i = 1;i<= m;){
        g = 0;
       if(st[i].F <= e ){
            while(st[i].F <= e && i <= m){
                    e = max(e,st[i].S);
                    i++;
            }
        }else if(st[i].F == e+1){
            b = st[i].F;
            e = st[i].S;
            i++;
        }else{
            b = e + 1;
            e = st[i].F-1;
            g = 1;
        }
        //cout << " b : "<< b << " e: " << e << endl;
        FOR(b,e,j){
            if(g){
             if(arr[j] != j){
                flag = 1;
                break;
             }
            } else {
                 if(arr[j] > e || arr[j] < b){
                    flag = 1;
                    break;
                 }
            }
        }
        if(flag == 1) break;
    }

     if(flag == 0)
        cout << "Possible" << endl;
    else
        cout << "Impossible" << endl;

 }

 return 0;
 }

