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
 #include <stdlib.h>
 #include <stdint.h>
 #include <unistd.h>

 #define FOR(a,b,i) for(int i=a; i<=b; i++)
 #define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
 #define present(c,x) ((c).find(x) != (c).end())
 #define pb push_back
 #define mp make_pair
 using namespace std;
 typedef vector<int> vi;

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


 int main(){
    uint32_t t;
    FastInput fi;
    //cin >> t;
    t = fi.ReadNext();
    while(t--){
        uint32_t n,q;
        //cin >> n;
        n = fi.ReadNext();
        vector<uint32_t> chefMax(n+1);

        FOR(1,n,i) {
            //cin >> s[i];
            chefMax[i] = fi.ReadNext();
        }

        map< uint32_t,uint32_t > lv;
        q = fi.ReadNext();
        uint32_t a,x,y;
        while(q--){
            //cin >> a;
            a = fi.ReadNext();
            if(a == 0){
                 x = fi.ReadNext();
                 y = fi.ReadNext();
                 uint32_t chefx,chefy;
                 if(!present(lv,x)){
                   chefx = x;
                 } else{
                     uint32_t k = lv[x];
                     int flag = 0;
                    while(present(lv,k)){
                        k = lv[k];
                        falg = 1;
                    }
                    if(flag == 1)
                        lv[x] = k;
                    chefx = k;
                 }

                 if(!present(lv,y)){
                   chefy = y;
                 } else{
                     uint32_t k = lv[y];
                     int falg = 0;
                    while(present(lv,k)){
                        k = lv[k];
                        flag = 1;
                    }
                    if(falg == 1) lv[y] = k;
                    chefy = k;
                 }

                if(chefx == chefy){
                    cout << "Invalid query!" << endl;
                    continue;
                }
                if(chefMax[chefx] > chefMax[chefy]){
                        lv.insert(mp(chefy,chefx));
                }else if(chefMax[chefx] < chefMax[chefy]){
                        lv.insert(mp(chefx,chefy));
                }

            }else{
                x = fi.ReadNext();
                if(!present(lv,x)){
                    cout << x << endl;
                }else{
                    uint32_t k = lv[x];
                    int flag = 0;
                    while(present(lv,k)){
                        k = lv[k];
                        flag = 1;
                    }
                    if(flag == 1) lv[x] = k;
                    cout << k << endl;
                }

            }
    }
    }

 return 0;
 }
