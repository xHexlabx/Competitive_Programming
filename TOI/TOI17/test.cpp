#include<bits/stdc++.h>

using namespace std;

set<int>s ;

int main(){
    
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    
    s.insert(10) ;

    for(int i : s){
        cout << i << ' ' ;
    }
    return 0 ;
}