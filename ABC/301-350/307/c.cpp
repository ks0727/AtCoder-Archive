#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int ha,wa;
    cin >> ha >> wa;
    vector<string> a(ha);
    rep(i,ha) cin >> a[i];
    int hb,wb;
    cin >> hb >> wb;
    vector<string> b(hb);
    rep(i,hb) cin >> b[i];
    int hx,wx;
    cin >> hx >> wx;
    vector<string> x(hx);
    rep(i,hx) cin >> x[i];
    int ai,aj;
    bool adone = false;
    rep(i,ha){
        if(adone) break;
        rep(j,wa){
            if(a[i][j] == '#'){
                ai = i; aj = j;
                adone = true;
                break;
            }
        }
    }
    int bi,bj;
    bool bdone = false;
    rep(i,hb){
        if(bdone) break;
        rep(j,wb){
            if(b[i][j] == '#'){
                bi = i; bj = j;
                bdone = true;
                break;
            }
        }
    }
    vector<vector<int> > isexist(hx,vector<int>(wx));
    rep(i,hx){
        rep(j,wx){
            if(x[i][j] == '#') isexist[i][j] = 1;
        }
    } 
    bool aok = false;
    int ans_ai = -1; int ans_aj = -1;
    rep(i,hx){
        rep(j,wx){
            int cnt_i = 0; int cnt_j = 0; 
            bool ok = true;
            for(int k = ai; k <= ha - ai;k++){
                if(!ok) break;
                for(int l = aj; l<=wa - aj;l++){
                    if(i+cnt_i < wx && j+cnt_j < hx){
                        if(a[k][l] == '#' && x[i+cnt_i][j+cnt_j] != '#'){
                            ok = false;
                            break;
                        }
                    }else{
                        if(a[k][l] == '#'){
                            ok = false;
                            break;
                        }
                    }
                    if(k == ha-ai && l == wa-aj && ok){
                        ans_ai = i; ans_aj = aj;
                        aok = true;
                    }
                    cnt_j++;
                }
                cnt_i++;
            }
        }
    }
    bool bok = false;
    int ans_bi = -1; int ans_bj = -1;
    rep(i,hx){
        rep(j,wx){
            int cnt_i = 0; int cnt_j = 0; 
            bool ok = true;
            for(int k = bi; k <= hb - bi;k++){
                if(!ok) break;
                for(int l = bj; l<=wb - bj;l++){
                    if(i+cnt_i < wx && j+cnt_j < hx){
                        if(b[k][l] == '#' && x[i+cnt_i][j+cnt_j] != '#'){
                            ok = false;
                            break;
                        }
                    }else{
                        if(b[k][l] == '#'){
                            ok = false;
                            break;
                        }
                    }
                    if(k == hb-bi && l == wb-bj && ok){
                        ans_bi = i; ans_bj = aj;
                        bok = true;
                    }
                    cnt_j++; 
                }
                cnt_i++;
            }
        }
    }
    cout << ans_ai << ' ' << ans_aj << endl;
    cout << ans_bi << ' ' << ans_bj << endl;
    bool cok = true;
    rep(i,hx){
        rep(j,wx){
            if(isexist[i][j] != 0) cok = false;
        }
    }
    if(aok && bok && cok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}