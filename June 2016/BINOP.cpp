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

int main3(){
	freopen("testCases.txt", "r", stdin);
	int t;
	cin >> t;
	while(t--){
		string s1,s2;
		cin >> s1 >> s2;
		if(s1 == s2){
			cout << "Lucky Chef" << endl;
			cout << 0 << endl;
			continue;
		}
		int allZeros=1,allOnes=1;
		FOR(0,sz(s1)-1,i){
			if(s1[i] == '0'){
				allOnes = 0;
			}else{
				allZeros = 0;
			}
			if(allOnes ==0 && allZeros == 0) break;
		}
		if(allZeros == 1|| allOnes == 1){
			cout << "Unlucky Chef" << endl;
			continue;
		}
		int zeros = 0,ones = 0;
		FOR(0,sz(s1)-1,i){
			if(s1[i] != s2[i]){
				if(s1[i] == '0'){
					zeros++;
				}else{
					ones++;
				}
			}
		}
		cout << "Lucky Chef" << endl;
		cout << max(zeros,ones) << endl;
	}
return 0;
}
