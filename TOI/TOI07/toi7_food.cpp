#include<bits/stdc++.h>
using namespace std;
bool visited[15];
vector<int>no_use(15);
int arr[15] ;
int n , k ;
void solve(int idx){
    if(idx == n){
        for(int i = 0 ; i < n ; i ++ ){
            cout << arr[i] << ' ';
        }
        cout << '\n' ;
    }
    for(int i = 1 ; i <= n ; i ++ ){
        if(visited[i])continue ;
        if(idx == 0 && find(no_use.begin(), no_use.end(),i) != no_use.end()){
            continue ;
        }
        visited[i] = true ;
        arr[idx] = i ;
        solve(idx + 1) ;
        visited[i] = false ;
    }
}
int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    cin >> n >> k ;
    for(int i = 0 ; i < k ; i ++ )cin >> no_use[i] ;
    solve(0) ;
    return 0 ;
}