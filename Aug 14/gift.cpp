#include <iostream>
#define FOR(a,b,i) for(int i=a; i<=b; i++)
using namespace std;
int main(){
    int t,n,k,evenCount;
    cin >> t;
    while(t--){
        int a;
        evenCount = 0;
        cin >> n >> k;
        FOR(0,n-1,i){
             cin >> a ;
             if(a%2 == 0) evenCount++;
        }
        if(k == 0 && evenCount == n )
            cout << "NO" << endl;
        else if(evenCount >=k)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }

return 0;
}
