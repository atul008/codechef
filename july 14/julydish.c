 #include <string.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <stdint.h>
 #include <unistd.h>
 #define FOR(a,b,i) for(i=a; i<=b; i++)

 int main(){
    int t,n,q,i;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int chefMax[n+1];
        FOR(1,n,i) {
            scanf("%d",&chefMax[i]);
        }
        int lv[n+1];
        FOR(1,n,i) lv[i] = i;
        scanf("%d",&q);
        int a,x,y;
        while(q--){
            scanf("%d",&a);
            if(a == 0){
                 scanf("%d",&x);
                 scanf("%d",&y);
                 int chefx,chefy,k;
                 chefx = lv[x];
                 chefy = lv[y];
                if(chefx == chefy){
                    printf("Invalid query!\n");
                    continue;
                }
                if(chefMax[chefx] > chefMax[chefy]){
                        FOR(1,n,i){
                            if(lv[i] == chefy) lv[i] = chefx;
                        }
                }else if(chefMax[chefx] < chefMax[chefy]){
                        FOR(1,n,i){
                            if(lv[i] == chefx) lv[i] = chefy;
                        }
                }

            }else{
                scanf("%d",&x);
                printf("%d\n",lv[x]);
            }
    }
    }

 return 0;
 }
