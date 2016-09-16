#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,t;
    cin >> t;
    while(t--){
        cin >> n;
            int a,ones=0,zeroes=0;
        for(int i=0;i<n;i++){
            cin >> a;
            if(a == 1){
                ones++;
            }else{
                zeroes++;
            }
        }
        int ans = 0;
        if(ones%2 == 0){
            ans += zeroes;
        }else{
            ans += ones;
        }

        cout << ans << endl;
    }
return 0;
}
