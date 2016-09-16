 #include <map>
 #include <set>
 #include <stack>
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
 #define INF 999999999
 using namespace std;
 typedef vector<int> vi;
 typedef vector<vi> vvi;
 typedef pair<int,int> ii;
 typedef long long ll;

 void btDfs(vvi& graph,vvi& dgraph,vi& vis,vi& inverted,int n,int v){
    vis[v] = 1;
    FOR(1,n,i){
        if(graph[v][i] && !vis[i]){
            if(dgraph[v][i] == 0)
                inverted[i] = min(inverted[i],inverted[v] + 1);
            else
                inverted[i] = min(inverted[i],inverted[v]);
           if(i==n) break;
           btDfs(graph,dgraph,vis,inverted,n,i);
           if(inverted[n] == 0) return;
        }
    }
    vis[v] = 0;
 }

 int main(){
    int n,m,a,b;
    cin >> n >> m;
    vvi graph(n+1,vi(n+1,0)),dgraph(n+1,vi(n+1,0));
    FOR(1,m,i) {
        cin >> a >> b;
        dgraph[a][b] = 1;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    if(n == 1){
        cout << "0" << endl;
        return 0;
    }

    vi vis(n+1,0);
    vi inverted(n+1,INF);
    inverted[1] = 0;
    vis[0] = 1;
    btDfs(graph,dgraph,vis,inverted,n,1);
    int res = inverted[n];
    if(res == INF)
        cout << "-1" << endl;
    else
        cout << res << endl;

    return 0;
 }
