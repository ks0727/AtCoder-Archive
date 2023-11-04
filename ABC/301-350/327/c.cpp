#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

bool ro(vector<string> a, int row){
    vector<bool> seen(9);
    rep(i,9){
        int num = a[row][i] - '0';
        num--;
        seen[num] = true;
    }
    rep(i,9){
        if(!seen[i]) return false;
    }
    return true;
}

bool col(vector<string> a, int column){
    vector<bool> seen(9);
    rep(i,9){
        int num = a[i][column] - '0';
        num--;
        seen[num] = true;
    }
    rep(i,9){
        if(!seen[i]) return false;
    }
    return true;
}

bool block(vector<string> a, int si,int sj){
    vector<bool> seen(9);
    rep(i,3){
        rep(j,3){
            int num = a[si+i][sj+j] - '0';
            num--;
            seen[num] = true;
        }
    }
    rep(i,9){
        if(!seen[i]) return false;
    }
    return true;
}

int main(){
    vector<string> a(9);
    rep(i,9){
        rep(j,9){
            char in;
            cin >> in;
            a[i].push_back(in);
        }
    }
    rep(i,9){
        if(!ro(a,i)){
            cout << "No" << endl;
            return 0;
        }
    }
    rep(i,9){
        if(!col(a,i)){
            cout << "No" << endl;
            return 0;
        }
    }
    rep(i,9){
        rep(j,9){
            if(i % 3 == 0 && j % 3 == 0){
                if(!block(a,i,j)){
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}