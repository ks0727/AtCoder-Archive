#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;
    vector<string> S(N);
    vector<pair<int,int> > ans;
    for(int i=0;i<N;i++){
        cin >> S.at(i);
    }
    for(int i=0;i<=N-9;i++){
        for(int j=0;j<=M-9;j++){
            if(S.at(i).at(j) == '#' && S.at(i).at(j+1) == '#' && S.at(i).at(j+2) == '#'){
                if(S.at(i).at(j+3) == '.'){
                    if(S.at(i+1).at(j) == '#' && S.at(i+1).at(j+1) == '#' && S.at(i+1).at(j+2) == '#'){
                        if(S.at(i+1).at(j+3) == '.'){
                            if(S.at(i+2).at(j) == '#' && S.at(i+2).at(j+1) == '#' && S.at(i+2).at(j+2) == '#'){
                                if(S.at(i+2).at(j+3) == '.'){
                                    if(S.at(i+3).at(j) == '.' && S.at(i+3).at(j+1) == '.' && S.at(i+3).at(j+2) == '.' && S.at(i+3).at(j+3) == '.'){
                                        if(S.at(i+5).at(j+5) =='.' &&  S.at(i+5).at(j+6) == '.' && S.at(i+5).at(j+7) == '.' && S.at(i+5).at(j+8) == '.'){
                                            if(S.at(i+6).at(j+5) == '.'){
                                                if(S.at(i+6).at(j+6) == '#' && S.at(i+6).at(j+7) == '#' && S.at(i+6).at(j+8) == '#'){
                                                    if(S.at(i+7).at(j+5) == '.'){
                                                        if(S.at(i+7).at(j+6) == '#' && S.at(i+7).at(j+7) == '#' && S.at(i+7).at(j+8) == '#'){
                                                            if(S.at(i+8).at(j+5) == '.'){
                                                                if(S.at(i+8).at(j+6) == '#' && S.at(i+8).at(j+7) == '#' && S.at(i+8).at(j+8) == '#'){
                                                                    ans.push_back(make_pair(i+1,j+1));
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            } 
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    sort(ans.begin(),ans.end());
    for(int i =0; i<ans.size();i++){
        cout << ans.at(i).first << ' ' << ans.at(i).second << endl;
    }

}