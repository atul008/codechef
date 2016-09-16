 #include <vector>
 #include <queue>
 #include <set>
 #include <sstream>
 #include <cstring>
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
 #define RFOR(a,b,i) for(int i=b; i>=a; i--)
 #define SET(c,x) memset(c,x,sizeof(c))
 #define pb push_back
 #define mp make_pair
 #define INF 999999
 #include <stdlib.h>
 #include <stdint.h>
 #include <unistd.h>
 #include <stdio.h>
 using namespace std;
 typedef vector<int> vi;
 typedef vector<vi> vvi;
 typedef pair<int,int> ii;
 typedef vector<ii> vii;
 typedef vector<vii> vvii;

 class compareDist{
    public:
        bool operator()(const ii& n1,const ii& n2){
            if(n1.y > n2.y)
             return true;
            else
             return false;
        }
 };

 void dikstra(vvii& graph,vi& dist,int n){
        int u;
        priority_queue < int,vector<ii>,compareDist > pq;
        dist[1] = 0;
        pq.push(mp(1,0));
        while(!pq.empty()){
            ii temp = pq.top();
            pq.pop();
           int u = temp.x,d = temp.y;
            if(u == n) return;
            int j;
            if(d <= dist[u]){
            tr(graph[u],it){
                    int v = it->x,cost = it->y;
                    if(dist[v] > dist[u] + cost){
                        dist[v] = dist[u] + cost;
                        pq.push(mp(v,dist[v]));
                    }
                }
            }
        }
 }

 int main(){
    int n,m,a,b;
    cin >> n >> m;
    vvii g(n+1);
    FOR(1,m,i) {
        cin >> a >> b;
          g[a].pb(mp(b,0));
          g[b].pb(mp(a,1));

    }
    if(n == 1){
        cout << "0" << endl;
        return 0;
    }
    vi dist(n+1,INF);
    dikstra(g,dist,n);
    int res = dist[n];

    if(res >= INF)
        cout << "-1" << endl;
    else
        cout << res << endl;

    return 0;
 }
