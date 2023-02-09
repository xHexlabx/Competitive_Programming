#include<bits/stdc++.h>
using namespace std;
pair<string,string> decode(string code,string status){
    pair<string,string> password;
    if(status.compare("s1") == 0 ){
        if(code.compare("00") == 0){
            password.first = "0";
            password.second = "s1";
        }
        else{
            password.first = "1";
            password.second = "s2";
        }
    }
    if(status.compare("s2") == 0 ){
        if(code.compare("10") == 0){
            password.first = "0";
            password.second = "s3";
        }
        else{
            password.first = "1";
            password.second = "s4";
        }
    }
    if(status.compare("s3") == 0 ){
        if(code.compare("00") == 0){
            password.first = "1";
            password.second = "s2";
        }
        else{
            password.first = "0";
            password.second = "s1";
        }
    }
    if(status.compare("s4") == 0 ){
        if(code.compare("01") == 0){
            password.first = "0";
            password.second = "s3";
        }
        else{
            password.first = "1";
            password.second = "s4";
        }
    }
    return password;
}
int main(){
    ios_base :: sync_with_stdio(0),cin.tie(0);
    string pass;string answer;
    string code,status = "s1";
    int n;cin >> n;
    for(int i = 0;i<n;i++){
        string y;cin >> y;
        pass += y;
    }
    for(int i = 0;i<pass.length();i+=2){
        code.clear();
        code.push_back(pass[i]);
        code.push_back(pass[i+1]);
        answer += decode(code,status).first;
        status = decode(code,status).second;
        if(answer.length() == 8){
            answer.erase(answer.begin());
            cout <<  char(stoi(answer, nullptr,2));
            answer.clear();
        }
    }
    return 0;
}