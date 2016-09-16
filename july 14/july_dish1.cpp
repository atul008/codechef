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

 #define pb push_back
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
        vector<uint32_t> dishChef(n+1),chefMax(n+1);

        FOR(1,n,i) {
            chefMax[i] = fi.ReadNext();
        }

        vector<list <uint32_t> > dishList(n+1);

        FOR(1,n,i) {
            dishChef[i] = i;
            dishList[i].clear();
            dishList[i].pb(i);
        }
        //cin >> q;
        q = fi.ReadNext();
        uint32_t a,x,y;
        while(q--){
            //cin >> a;
            a = fi.ReadNext();
            if(a == 0){
                 //cin >> x >> y;
                 x = fi.ReadNext();
                 y = fi.ReadNext();
                 uint32_t dy = dishChef[y];
                 uint32_t dx = dishChef[x];

                 if(dy == dx){
                    cout << "Invalid query!" << endl;
                    continue;
                 }

                 if(chefMax[dx] > chefMax[dy]){
                    tr(dishList[dy],it){
                            dishChef[*it] = dx;
                    }
                    dishList[dx].splice(dishList[dx].end(),dishList[dy]);

                 }else if(chefMax[dx] < chefMax[dy]){
                    tr(dishList[dx],it){
                            dishChef[*it] = dy;
                    }
                    dishList[dy].splice(dishList[dy].end(),dishList[dx]);
                }
            }else{
                //cin >> x;
                x = fi.ReadNext();
                cout << dishChef[x] << endl;
            }
        }
    }

 return 0;
 }
