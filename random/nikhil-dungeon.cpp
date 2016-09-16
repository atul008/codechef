#include <iostream>
#include <vector>
#include <stdio.h>

#define vi vector<int>
#define vvi vector<vi>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ii pair<int,int>
#define F first
#define S second
#define mp make_pair;
using namespace std;

int maxTime,tRemain,tGood,a,b,m,n;
int move[4][2] = { {0,1},{1,0}, {-1,0} ,{0,-1} };

void solve(vvi& dungeon,vvi& visited,int x ,int y){
    visited[x][y] = 1;
    tRemain -= dungeon[x][y];

 if(tRemain < 0 || tRemain <= tGood){
        tRemain += dungeon[x][y];
        visited[x][y] = 0;
        return;
    }
    if(x == a && y == b){
        if(tRemain > tGood)
            tGood = tRemain;
        tRemain += dungeon[x][y];
        visited[x][y] = 0;
        return ;
    }else{
        FOR(i,0,3){
            int  x1 = x+move[i][0],y1 = y+move[i][1];
            if(x1 <= m && x1 >= 0 && y1 <= n && y1 >= 0 && !visited[x1][y1])
            solve(dungeon,visited,x1,y1);
        }
        visited[x][y] = 0;
        tRemain += dungeon[x][y];
        return;
    }
}

int main(){
    freopen("input.txt","r",stdin);
    cin >> m >> n;
    vvi dungeon(m,vi(n)),visited(m,vi(n,0));
    FOR(i,0,m-1) FOR(j,0,n-1) cin >> dungeon[i][j];

    int x,y;
    cin >> a >> b >> maxTime;
    tRemain = maxTime;
    a = a-1;
    b = b-1;
    m = m-1;
    n = n-1;
    tGood = -1;
    solve(dungeon,visited,0,0);
    if(tGood != -1){
        cout << "YES\n";
        cout << tGood << endl;
    }else{
        cout << "NO\n";
    }
return 0;
}
