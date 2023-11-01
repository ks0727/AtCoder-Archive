çint main(){
    int current = -1;
    rep(i,8){
        int s;
        cin >> s;
        if(current > s){
            cout << "No" << endl;
            return 0;
        }else{
            current = s;
        }
        if(s < 100 || s > 675){
            cout << "No" << endl;
            return 0;
        }
        if(s % 25 != 0){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}