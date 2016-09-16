#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        if(n ==1 ){
            cout << 1 << endl;
        }else{
            long long ans = 0;
            for(long long i = 1;i*i<=n;i++){
                if(n%i == 0){
                    ans += i;
                    ans +=n/i;
                }
            }
            long long k = sqrt(n);
            if(k*k == n){
                ans -= k;
            }
            cout << ans << endl;

        }

    }
    return 0;
}
