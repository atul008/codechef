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
    ll m,n;
   // freopen("in.txt","r",stdin);
    cin >> m >> n;
    ll arr[m][n],vis[m][n];
    memset(vis,0,sizeof(vis));
    FOR(0,m-1,i) FOR(0,n-1,j) cin >> arr[i][j];
    ll res = 1,t=1;
    FOR(0,m-1,i) FOR(0,n-1,j){
        //if(!vis[i][j]){
        vis[i][j] = 1;
        t = 1;
        int k = j,f=0,d;
        while(k <=n-1 && arr[i][k] == arr[i][j]){
                      d = i;
                      while(d <=m-1 && arr[d][j] == arr[i][j]){
                            f = 0;

                       if((k-j+1)*(d-i+1) > res){

                           FOR(j,k,r){
                                if(arr[d][r] != arr[i][j]){
                                    f = 1;
                                    break;
                                }
                              //  vis[d][r] = 1;
                            }
                            if(f == 0){
                                FOR(i,d,c){
                                    if(arr[c][k] != arr[i][j]){
                                        f = 1;
                                        break;
                                    }
                            //    vis[c][k] = 1;
                                }

                            }

                            if(f == 0){
                                t = (k-j +1)*(d-i +1);
                                res = max(res,t);
                               // FOR(j,k,a) FOR(i,d,b) vis[i][j] = 1;
                            }
                       }
                      d++;
                    }
            k++;
        }
    }

    cout << res << endl;


 return 0;
 }
