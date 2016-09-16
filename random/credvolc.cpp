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
    int n,m,x,y,a,b;
  //  freopen("in.txt","r",stdin);
    cin >> m >> n;
    int arr[m][n],vis[m][n];
    FOR(0,m-1,i) FOR(0,n-1,j) cin >> arr[i][j];
    cin >> a >> b;
    SET(vis,0);
    int move[8][2] = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
    vis[a][b] = 1;
    int l = arr[a][b],stop = 0;
    set< pair<int , ii > > st;
    queue<ii> q;
    q.push(mp(a,b));
    st.insert(mp(l,mp(a,b)));
    while(!st.empty()){
        while(!q.empty()){
            ii p = q.front();
            q.pop();
            x = p.F,y=p.S;
            FOR(0,7,i) FOR(0,1,j){
                int nx = x+move[i][0],ny = y+move[i][1];
                if((nx<=m-1 && nx >=0) && (ny<=n-1 && ny>=0)){
                   if(arr[nx][ny] <= l){
                        if(!vis[nx][ny]){
                        vis[nx][ny] = 1;
                        q.push(mp(nx,ny));
                        }
                   }else{
                        st.insert(mp(arr[nx][ny],mp(nx,ny)));
                   }
                }else{
                    stop = 1;
                }
            }
        }
        if(stop == 0){
        l = st.begin()->F;
        x = st.begin()->S.F,y=st.begin()->S.S;
        st.erase(st.begin());
        q.push(mp(x,y));
        continue;
        }else{
            while(st.begin()->F == l){
                x = st.begin()->S.F,y =st.begin()->S.S;
                vis[x][y] = 1;
                st.erase(st.begin());
                FOR(0,7,i) FOR(0,1,j){
                int nx = x+move[i][0],ny = y+move[i][1];
                if((nx<=m-1 && nx >=0) && (ny<=n-1 && ny>=0)){
                   if(arr[nx][ny] <= l && !vis[nx][ny]){
                        st.insert(mp(arr[nx][ny],mp(nx,ny)));
                   }
                 }
                }
            }
            break;
        }
    }
    FOR(0,m-1,i){
         FOR(0,n-1,j){
            cout << vis[i][j] << " ";
         }
         cout << endl;
    }

 return 0;
 }
