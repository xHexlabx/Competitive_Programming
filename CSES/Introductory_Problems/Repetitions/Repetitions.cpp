#include<bits/stdc++.h>

using namespace std;

const int Size = 1e6 + 1 ;

int dp[Size] , MAX = INT_MIN ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0);

    string sequence ; cin >> sequence ;
    sequence = " " + sequence ;

    for(int i = 1 ; i < sequence.size() ; i++){
        
        if(sequence[i] == sequence[i - 1]){
            dp[i] = dp[i - 1] + 1 ;
        }
        else {
            dp[i] = 1 ;
        }

        MAX = max(MAX , dp[i]) ;

    }

    cout << MAX ;

    return 0 ;
}