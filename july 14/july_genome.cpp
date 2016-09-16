 #include <map>
 #include <set>
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
 #define SET(c,x) memset(c,x,sizeof(c))
 #define pb push_back
 #define mp make_pair

 using namespace std;
 typedef vector<int> vi;
 typedef vector<vi> vvi;
 typedef pair<int,int> ii;
 typedef long long ll;


 int main(){
    int t,n,m,k;
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        vector< vector <char> > gen(n,vector<char>(m,' '));
        char c[4] = {'G','C','A','T'};
        int r;
        FOR(0,n-1,i) FOR(0,m-1,j) {
            r = rand()%4;
            gen[i][j] = c[r];
        }
        FOR(0,n-1,i){
            FOR(0,m-1,j)
                cout << gen[i][j];
            cout << endl;
        }


    }

 return 0;
 }
