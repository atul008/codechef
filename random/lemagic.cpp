 #include <bits/stdc++.h>
 using namespace std;

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

 int dp[103][103][3][3][13];
 int maxdp(int r,int c,int x,int y,int d){
    int res = 0;
    res = max(res,dp[r][c][x][y][d+1]);
    if(r > 0)
        res = max(max(res,dp[r-1][c][0][y][d]),dp[r-1][c][1][y][d] );
    if(c > 0)
        res = max(max(res,dp[r][c-1][x][0][d]) , dp[r][c-1][x][1][d] );
    if( r > 0 && c > 0 ){
        res = max(max(res,dp[r-1][c-1][0][0][d]) , dp[r-1][c-1][0][1][d] );
        res = max(max(res,dp[r-1][c-1][1][0][d]) , dp[r-1][c-1][1][1][d] );
    }
    return res;
 }


 int main(){
 int n,m,t,d;
 int arr[103][103];
 cin >> t;
 while(t--){
    SET(dp,0);
    int res  = 0;
    cin >> n >> m;
    string s;
    FOR(0,n-1,i){
        cin >> s;
        FOR(0,s.length()-1,j){
            arr[i][j] = s[j]-'0';
        }
    }

    FOR(0,9,p){
        FOR(0,n-1,r) FOR(0,m-1,c){
            FOR(0,1,x) FOR(0,1,y){
                FOR(0,9,d){
                    int v = (arr[r][c] + x*p + y*p)%10;
                    if(v == d)
                        dp[r][c][x][y][d] = maxdp(r,c,x,y,d) + 1;
                    else
                        dp[r][c][x][y][d] = maxdp(r,c,x,y,d);
                }
            }
        }
    }
    res = max(max(res,dp[n-1][m-1][0][0][0]) , dp[n-1][m-1][0][1][0]);
    res = max(max(res,dp[n-1][m-1][1][0][0]) , dp[n-1][m-1][1][1][0]);
    cout << res << endl;
 }
 return 0;
 }
