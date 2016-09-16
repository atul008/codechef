 #include <map>
 #include <set>
 #include <queue>
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


 int main(){
    int n,m,res = INF,a,b;
    cin >> n >> m;
    vvi graph(n+1,vi(n+1,0)),dgraph(n+1,vi(n+1,0));
    FOR(1,m,i) {
        cin >> a >> b;
        dgraph[a][b] = 1;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    queue<int> q;
    vi vis(n+1,0);
    vi inverted(n+1,INF);
    q.push(1);
    vis[1] = 1;
    inverted[1] = 0;
    int flag = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        FOR(1,n,i){
            if(graph[v][i] && !vis[i]){
                if(i == n) flag = 1;
                q.push(i);
                vis[i] = 1;
                if(dgraph[v][i] == 0)
                    inverted[i] = min(inverted[i],inverted[v] + 1);
                else
                    inverted[i] = min(inverted[i],inverted[v]);
                }
            }

        }
    //tr(inverted,it) cout << *it << endl;
        if(flag == 0)
            cout << "-1" << endl;
        else
            cout << inverted[n] << endl;
 return 0;
 }
