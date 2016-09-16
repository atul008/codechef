 #include <bits/stdc++.h>
 #define  x first
 #define  y second

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

 using namespace std;
 typedef vector<int> vi;
 typedef vector<vi> vvi;
 typedef pair<int,int> ii;
 typedef long long ll;

 void move(int& r,int& c,int beg,int end,int flag){
   // if flag is 0 move
      //  cout << " r : " << r << " c: " << c;
        int temp,step = end-beg;
        if(flag == 0){
            temp = end - c;
            c = end;
            r = r + (step-temp);
        }else if(flag == 1){
            temp =end - r;
            r = end;
            c = c- (step-temp);
        }else{
            temp = c -beg;
            c = beg;
            r = r-(step-temp);
        }
    //    cout << " r : " << r << " c: " << c << endl;
 }
 void rotateBy90(vvi& arr,int size,int level){
    if(level > size/2) return;
    int r1,c1,r2,c2,l,h;
    l = level,h = size-level+1;

    FOR(level,size-level,i){
        r1 = level,c1 = i;

        r2 = r1,c2 = c1;
        move(r2,c2,l,h,0);
        swap(arr[r1][c1],arr[r2][c2]);

        r1 = r2,c1 = c2;
        move(r2,c2,l,h,1);
        swap(arr[r1][c1],arr[r2][c2]);

        r1 = r2,c1 = c2;
        move(r2,c2,l,h,2);
        swap(arr[r1][c1],arr[r2][c2]);

      }
    rotateBy90(arr,size,level+1);
 }

 int main(){
    vvi arr(5,vi(5,0));
    int count = 1;
    FOR(1,4,i) FOR(1,4,j){
        arr[i][j] = count++;
    }
    cout << "before : " << endl;
    FOR(1,4,i){
         FOR(1,4,j){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    rotateBy90(arr,4,1);
    cout << "after : " << endl;
    FOR(1,4,i){
         FOR(1,4,j){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
 return 0;
 }
