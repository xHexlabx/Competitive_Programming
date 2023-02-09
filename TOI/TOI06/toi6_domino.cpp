#include<bits/stdc++.h>
using namespace std;
int k ;
void solve(vector<string>vec , int n){
    if(n == k){
        for(auto i : vec){
            cout << i << '\n' ;
        }
        cout << 'E' << '\n' ;
    }
    else if(n < k){
        vec.push_back("--");
        solve(vec , n + 1) ;
        vec.pop_back();
        vec.push_back("||");
        solve(vec , n + 2) ;
        vec.pop_back();
    }
}
int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    
    cin >> k ;
    solve({} , 0);
    return 0 ;
}