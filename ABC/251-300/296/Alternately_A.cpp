#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    int flag = 0;
    for(int i =0; i < n - 1;i++){
        if(flag != 0){
            break;
        }
        if(s[i] == s[i + 1]){
            flag = 1;
        }
    }
    if(flag == 1){
        printf("No\n");
    }else{
        printf("Yes\n");
    }
    return 0;
}