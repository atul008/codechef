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
 #include <stdlib.h>
 #include <stdint.h>
 #include <unistd.h>
 #include <stdio.h>
 class FastInput {
 public:
    FastInput() {
        m_dataOffset = 0;
        m_dataSize = 0;
        m_v = 0x80000000;
    }
    uint32_t ReadNext() {
        if (m_dataOffset == m_dataSize) {
            int r = read(0, m_buffer, sizeof(m_buffer));
            if (r <= 0) return m_v;
            m_dataOffset = 0;
            m_dataSize = 0;
            int i = 0;
            if (m_buffer[0] < '0') {
                if (m_v != 0x80000000) {
                    m_data[m_dataSize++] = m_v;
                    m_v = 0x80000000;
                }
                for (; (i < r) && (m_buffer[i] < '0'); ++i);
            }
            for (; i < r;) {
                if (m_buffer[i] >= '0') {
                    m_v = m_v * 10 + m_buffer[i] - 48;
                    ++i;
                } else {
                    m_data[m_dataSize++] = m_v;
                    m_v = 0x80000000;
                    for (i = i + 1; (i < r) && (m_buffer[i] < '0'); ++i);
                }
            }
        }
        return m_data[m_dataOffset++];
    }
 public:
    uint8_t m_buffer[32768];
    uint32_t m_data[16384];
    size_t m_dataOffset, m_dataSize;
    uint32_t m_v;
 };

 using namespace std;
 typedef vector<int> vi;
 typedef vector<vi> vvi;
 typedef pair<int,int> ii;
 typedef long long ll;

 void btDfs(vvi& graph,vvi& dgraph,vi& vis,vi& inverted,int n,int v){
    vis[v] = 1;
    tr(graph[v],it){
    if(!vis[*it]){
       if(dgraph[v][*it] == 0)
            inverted[*it] = min(inverted[*it],inverted[v] + 1);
        else
            inverted[*it] = min(inverted[*it],inverted[v]);
       if(inverted[*it] < inverted[n])
         btDfs(graph,dgraph,vis,inverted,n,*it);

    }
    }
    if(inverted[v] < inverted[n])
        vis[v] = 0;
 }
/*
 void btDfs(vvi& graph,vvi& dgraph,vi& vis,vi& inverted,int n,int v){
    stack<int> s;
    s.push(v);
    while(!s.empty()){
        int v = s.top();
        s.pop();
        vis[v] = 1;
        tr(graph[v],it){
            if(!vis[*it]){
                if(dgraph[v][*it] == 0)
                    inverted[*it] = min(inverted[*it],inverted[v] + 1);
                else
                    inverted[*it] = min(inverted[*it],inverted[v]);
                if(inverted[n] == 0) return;
                s.push(*it);
            }
        }
    }
 }
*/

 int main(){
    int n,m,a,b;
    FastInput fi;
    n = fi.ReadNext();
    m = fi.ReadNext();
    //cin >> n >> m;
    vvi graph(n+1);
    vvi dgraph(n+1,vi(n+1,0)),mark(n+1,vi(n+1,0));
    FOR(1,m,i) {
       // cin >> a >> b;
       a = fi.ReadNext();
       b = fi.ReadNext();
        if(a != b){
        if(!mark[a][b]){
            mark[a][b] = 1;
            mark[b][a] = 1;
            graph[a].pb(b);
            graph[b].pb(a);
        }
        }
        dgraph[a][b] = 1;
    }
    if(n == 1){
        cout << "0" << endl;
        return 0;
    }

    vi vis(n+1,0);
    vi inverted(n+1,INF);
    inverted[1] = 0;
    btDfs(graph,dgraph,vis,inverted,n,1);
    int res = inverted[n];
    if(res == INF)
        cout << "-1" << endl;
    else
        cout << res << endl;

    return 0;
 }
