#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    bool ans = false;
    int key = 0;
    while(true){
        if(S.substr(key,5) == "dream"){
            if(key < (int)S.size()-6){
                if(S.substr(key+5,2) != "er"){
                key += 5;
            } //dreamで確定
            else{
                if(S.at(key+7) == 'd' || S.at(key+7) == 'e' ) key += 7; //
                else key += 5; //dreameraseの場合があるから、dreamerの次の文字がdかe以外だったらdreamとして進める
            }
            }
            else{
                ans = true;
                break;
            }
        }
        else if(S.substr(key,5) == "erase"){
            if(key < (int)S.size()-5){
                if(S.at(key+5) != 'r'){ //eraseで確定
                    key += 5;
                }
                else {
                    key+= 6; //eraserで確定
                }
            }
            else{
                ans = true;
                break;
            }
        }
        else{
            ans = false;
            break;
        }
        if(key == (int)S.size()){
            ans = true;
            break;
        }
    }
    if(ans) std::cout << "YES" << endl;
    else std::cout << "NO" << endl;
}