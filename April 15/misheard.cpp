#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long > arr(n);
        for(int i=0;i<n;i++) cin >> arr[i];
        int count =0;
        bool flag = false;

        for(int i=1;i<n;i++){
            if(arr[i] != arr[i-1]){
                if(flag == false){
                    count +=2;
                    flag = true;
                }else{
                    count += 1;
                    flag = true;
                }
            }else{
                flag = false;
            }

        }
        cout << count << endl;

    }

return 0;

}
