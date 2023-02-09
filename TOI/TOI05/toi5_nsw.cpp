#include<bits/stdc++.h>
using namespace std;
vector<int> slide_Up(vector<int>wheel,int n){
    for(int i = 0;i<n;i++){
        wheel.push_back(wheel[0]);
        wheel.erase(wheel.begin());
    }
    return wheel;
}
vector<int> slide_Down(vector<int>wheel,int n){
    for(int i = 0;i<n;i++){
        wheel.insert(wheel.begin(),wheel[wheel.size()-1]);
        wheel.pop_back();
    }
    return wheel;
}
int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0);
    vector<int> w1 = {1,2,3,4,5,6,7,8,9};
    vector<int> w2 = {1,2,3,4,5,6,7,8,9};
    vector<int> w3 = {1,2,3,4,5,6,7,8,9};
    string key;cin >> key;
    string number;cin >> number;
    //setting wheel
    w1 = slide_Up(w1,key[0] - '0' - 1);
    w2 = slide_Up(w2,key[1] - '0' - 1);
    w3 = slide_Up(w3,key[2] - '0' - 1);
    for(int i = 0;i<number.size();i++){
        cout << w3[w2[w1[number[i] - '0'-1]-1]-1];
        w1 = slide_Up(w1,key[0] - '0');
        w2 = slide_Down(w2,1);
        w3 = slide_Up(w3,key[2] - '0');
    }
    return 0;
}