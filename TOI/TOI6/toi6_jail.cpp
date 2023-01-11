#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    queue<int>q ;
    int n , k , cnt = 0 ; cin >> n >> k ;
    for(int i = 1 ; i <= n ; i ++ )q.push(i) ;
    while(!q.empty()){
        
        cnt ++ ;
        if(cnt == k){
            cout << q.front() << ' ';
            q.pop() ;
            cnt = 0 ;
        }
        else {
            q.push(q.front()) ;
            q.pop() ;
        }
    }
    return 0 ;
}