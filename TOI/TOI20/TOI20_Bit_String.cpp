#include<bits/stdc++.h>

using namespace std ;

const int Size_N = 20 ;

int N , Q ;

long long dp[1 << Size_N] ;
long long arr[1 << Size_N] ;

int bit_to_state (string bit) {

    int state = 0 ;
    
    int current_val_bit = 1 ;

    for(int i = N - 1 ; i >= 0 ; i -- ){
        state += (bit[i] - '0') * current_val_bit ;
        current_val_bit <<= 1 ;
    }

    return state ;
}

void set_state () {
    for(int i = 0 ; i < (1 << N) ; i ++ ){
        dp[i] = -INT_MIN ; 
    }
}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> N >> Q ;

    set_state() ;

    for(int i = 0 ; i < (1 << N) ; i ++ ){        
        string bit ; long long val ;
        cin >> bit >> val ;
        arr[bit_to_state(bit)] = val ;
    }

    //

    dp[0] = 0 ;

    for(int current_state = 1 ; current_state < (1 << N) ; current_state ++ ){

        //one bit change
        int outbit = 1 ;

        for(int i = 0 ; i < N ; i ++ ){
            if((current_state & outbit) == (outbit)){
                int previous_state = current_state ^ (outbit) ;
                dp[current_state] = max(dp[current_state] , dp[previous_state] + arr[current_state]) ;
            }
            outbit <<= 1 ;
        }
        //two bit change
        outbit = 3 ;

        for(int i = 0 ; i < N - 1 ; i ++ ){
            if((current_state & outbit) == (outbit)){
                int previous_state = current_state ^ (outbit) ;
                dp[current_state] = max(dp[current_state] , dp[previous_state] + arr[current_state]) ;
            }
            outbit <<= 1 ;
        }  
    }

    for(int i = 0 ; i < Q ; i ++ ){
        string bit ; cin >> bit ;
        cout << dp[bit_to_state(bit)] << '\n' ;
    }

    return 0 ;
}