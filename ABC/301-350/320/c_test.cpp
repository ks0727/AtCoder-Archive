#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int m;
    cin >> m;
    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    s1.push_back(s1[0]);
    s2.push_back(s2[0]);
    s3.push_back(s3[0]);
    
    vector<vector<int> > arr(m+1,vector<int>(3));
    rep(i,m+1){
        arr[i][0] = s1[i] - '0';
        arr[i][1] = s2[i] - '0';
        arr[i][2] = s3[i] - '0';
    }
    
    vector<int> cnt(10,0);
    vector<vector<int> > new_cnt(10,vector<int>(3));
    int ans =0;
    rep(i,m+1){
        vector<bool> isUp(10,true);
        rep(j,3){
            if(isUp[arr[i][j]]){
                new_cnt[arr[i][j]][j] = 1;
                isUp[arr[i][j]] = false;
            }
            if(i== m && j == 2){
                int mx = 0;
                rep(k,10){
                    int current = 0;
                    rep(l,3){
                        if(new_cnt[k][l] == 1) current++;
                    }
                    mx = max(mx,current);
                }
                if(mx <= 2){
                    cout << -1 << endl;
                    rep(x,m+1){
                        rep(y,3){
                            cout << new_cnt[x][y];
                            if(y==2) cout << endl;
                        }
                    }
                    return 0;
                }
            }
        }
        ans++;
        rep(m,10){
            int sum = 0;
            rep(n,3){
                if(new_cnt[m][n] == 1) sum++;
            }
            if(sum == 3){
                cout << ans - 1 << endl;
                return 0;
            }
        }
    }
    return 0;
}