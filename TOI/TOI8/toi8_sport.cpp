#include<bits/stdc++.h>
using namespace std;
int n , win , lose ;
void solve(string s , int w , int l){
    if(w == n || l == n){
        for(auto i : s)cout << i << ' ';
        cout << '\n';
    }
    else {
        solve(s + 'W' , w + 1 , l);
        solve(s + 'L' , w , l + 1);
    }
}
int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    cin >> n >> win >> lose ;
    
    solve("" , win , lose) ;
    return 0 ;
}