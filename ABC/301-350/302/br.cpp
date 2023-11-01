#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<(n);i++)

const int di[] = {1,1,0,-1,-1,-1,0,1};
const int dj[] = {0,1,1,1,0,-1,-1,-1};

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    string snuke = "snuke";
    rep(i,h){
        rep(j,w){
            if(s[i][j] != 's') continue;
            rep(d,8){
                int ni = i; int nj = j;
                rep(k,4){
                    ni += di[d]; nj += dj[d];
                    if(ni < 0 || nj < 0 || ni > h-1 || nj > w-1) break;
                    if(s[ni][nj] != snuke[k+1]) break;
                    if(k == 3){
                        i++; j++;
                        cout << i << ' ' << j << endl;
                        rep(l,4){
                            i += di[d]; j+= dj[d];
                            cout << i << ' ' << j << endl;
                        }
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}