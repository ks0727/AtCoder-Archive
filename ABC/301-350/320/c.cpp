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
        rep(j,3){
            cnt[arr[i][j]]++;
            if(j == 0){
                if(arr[i][j] == arr[i][j+1]){
                    cnt[arr[i][j]]--;
                } 
                if(arr[i][j] == arr[i][j+2]){
                    cnt[arr[i][j]]--;
                } 
                if(arr[i][j+1] == arr[i][j+2]){
                    cnt[arr[i][j+1]]--;
                }
                if((arr[i][j] == arr[i][j+1]) && (arr[i][j] == arr[i][j+2]) && (arr[i][j+1] == arr[i][j+2])){
                    cnt[arr[i][j]]++;
                } 
            }
            if(i== m && j == 2){
                int mx = 0;
                rep(k,9){
                    mx = max(mx,cnt[k]);
                }
                if(mx <= 2){
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
        ans++;
        rep(k,9){
            if(cnt[k] >= 3){
                cout << ans - 1<< endl;
                return 0;
            }
        }
    }
    return 0;
}