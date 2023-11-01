#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<int> > a(h,vector<int>(w)),b(h,vector<int>(w));
    rep(i,h)rep(j,w) cin >> a[i][j];
    rep(i,h)rep(j,w) cin >> b[i][j];

    for(int s = 1;s<w+1;s++){
        for(int t = 1; t<w+1;t++){
            vector<vector<int> > changed1(h,vector<int>(w));
            vector<vector<int> > changed2(h,vector<int>(w));
            rep(i,w){
                rep(j,h){
                    if(i + s < w) changed1[i][j] = a[i+s][j];
                    else changed1[i][j] = a[w-(s+i)][j];
                }
            }
            rep(i,w){
                rep(j,h){
                    if(j + t < h) changed2[i][j] = changed2[i][j+t];
                    else changed2[i][j] = changed2[i][h-(t+j)];
                }
            }
            bool ok = true;
            rep(i,w){
                if(!ok) break;
                rep(j,h){
                    if(changed2[i][j] != b[i][j]){
                        ok = false;
                        break;
                    }
                    if(i == w-1 && j == h-1){
                        cout << s << ' ' << t << endl;
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}