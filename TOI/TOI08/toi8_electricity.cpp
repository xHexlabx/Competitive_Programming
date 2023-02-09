#include<bits/stdc++.h>
using namespace std;
deque<pair<int , int>>dq ;
int n , k , temp ;
int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    cin >> n >> k ;
    for(int i = 1 ; i <= n ; i ++ ){
        
        cin >> temp ;
        if(i == 1)dq.push_back({temp , i});
        else {
            while(!dq.empty() && i - dq.front().second > k )dq.pop_front() ;
            if(i == n)cout << temp + dq.front().first ;
            while(!dq.empty() && dq.back().first > temp + dq.front().first)dq.pop_back() ;
            dq.push_back({temp + dq.front().first , i});
        }
    }
    return 0 ;
}