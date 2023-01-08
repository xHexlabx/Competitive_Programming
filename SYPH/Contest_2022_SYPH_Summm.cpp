#include<bits/stdc++.h>

using namespace std ;

int target , cnt ;
bool found = false ;

void solve(int sum , string res){

    if(found)return ;
    if(sum == target){
        cnt -- ;
        if(cnt == 0){
            cout << res ;
            found = true ;
            return ;
        }
    }
    for(int i = 1 ; i < 10 ; i ++ ){
        if(sum + i > target)continue ;
        solve(sum + i , res + char('0' + i)) ;
    }

}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> target >> cnt ;
    solve(0 , "");

    return 0 ;
}