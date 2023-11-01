#include<bits/stdc++.h>
using namespace std;
// 問題文の形式でvec値を出力

void print_vec(vector<int> vec) {
    cout << "[ ";
    for (int i = 0; i < vec.size(); i++) {
    cout << vec.at(i) << " ";
    }
    cout << "]" << endl;
}

char read_name(){
    char name;
    char s;
    cin >> name;
    while(cin >> s){
        if(s == '=') break;
    }
    return name;
}

int calc_int(map<char,int> &variable_int){
    int ans = 0;
    char c;
    vector<int> values; //値を格納しておく配列
    vector<char> variable_names; //
    vector<char> operators;
    while(cin >> c){
        if(isdigit(c)){ //入力が１桁の整数の値だった時
            int value = c - '0';
            values.push_back(value);
        }
        else{
            if(c == '+' || c == '-'){ //入力が足し算または引き算の演算子だった時
                operators.push_back(c);
            }
            else{ //入力が変数名だった時
                int value = variable_int[c];
                values.push_back(value);
            }
        }
        if(c == ';') break;
    }
    ans = values.at(0);
    for(int i = 0;i<(values.size()-2);i++){
        if(operators.at(i) == '+'){
            ans += values.at(i+1);
        }
        else if(operators.at(i) == '-'){
            ans -= values.at(i+1);
        }
    }
    return ans;
}

vector<int> calc_vector(map<char,int> &variable_int, map<char,vector<int> >& variable_vector){
    vector<vector<int> > vectors;
    vector<int> ans;
    vector<char> operators;
    char c;
    while(cin >> c){
        vector<int> vec;
        if(c == ';') break;
        else if(c == '['){
            char c2;
            while(cin >> c2){
                if(c2 == ']'){
                    break;
                }
                if(isdigit(c2)){
                    int value = c2 - '0';
                    vec.push_back(value); //数字だったら、ベクトルに格納する。
                }else{
                    if(c2 != ','){
                        int value = variable_int[c2];
                    vec.push_back(value);
                    }
                }
            }
            vectors.push_back(vec);
        }
        else if(c == '+' || c == '-'){
            operators.push_back(c);
        }
        else{
            vector<int> value = variable_vector[c];
            vectors.push_back(value);
        }
    }
    ans = vectors.at(0);
    if(!(operators.empty())){
        for(int i = 0; i<(vectors.size()-1);i++){
            if(operators.at(i) == '+'){
                for(int j=0;j<ans.size();j++){
                    ans.at(j) += vectors.at(i+1).at(j);
                }
            }
            else if(operators.at(i) == '-'){
            for(int j=0;j<ans.size();j++){
                ans.at(j) -= vectors.at(i+1).at(j);
            }
            }
        }
    }
    return ans;
}

int main(){
    int N;
    cin >> N;

    map<char,int> variable_int;
    map<char,vector<int> > variable_vector;

    for(int i=0;i<N;i++){
        string input;
        cin >> input;
        if(input == "int"){
            char name = read_name();
            variable_int[name] = calc_int(variable_int);
        }

        if(input == "vec"){
            char name = read_name();
            variable_vector[name] = calc_vector(variable_int, variable_vector);
        }
        if(input == "print_int"){
            cout << calc_int(variable_int) << endl;
        }
        if(input == "print_vec"){
            print_vec(calc_vector(variable_int, variable_vector));
        }
    }
}