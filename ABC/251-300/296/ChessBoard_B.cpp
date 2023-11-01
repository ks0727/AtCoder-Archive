#include<iostream>
#include<string>
using namespace std;
#define Length 8
int main(){
    string s[Length];
    char height[Length] = {'a','b','c','d','e','f','g','h'};
    char width[Length] = {'8','7','6','5','4','3','2','1'};
    int index_h = 0,index_w = 0;
    string ans;
    for(int i=0; i< Length; i++){
        cin >> s[i];
    }
    for(int i =0; i<Length; i++){
        for(int j = 0; j<Length; j++){
            if(s[i][j] == '*'){
                index_w = i;
                index_h = j;
                break;
            }
        }
    }
    printf("%c%c\n",height[index_h],width[index_w]);
    return 0;
}