#include<bits/stdc++.h>
using namespace std;
int arr[6000001] , MAX = 0 , range = 0 , n , k , sum ;
deque<int>dq ;
int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    cin >> n >> k ;
    for(int i = 1 ; i <= n ; i ++) {
        cin >> arr[i] ;
        arr[i] += arr[i - 1];
    }
    for(int i = 1 ; i <= n ; i ++ ){
        if(i == 1){
            if(arr[i] > MAX){
                MAX = arr[i] ;
                range = 1 ;
                
            }
            dq.push_back(1) ;
        }
        else {
            while(!dq.empty() && i - dq.front() > k)dq.pop_front() ;
            sum = arr[i] - arr[dq.front()] ;
            if(sum > MAX){
                MAX = sum;
                range = i - dq.front() ;
            }
            else if(sum == MAX){
                range = min(range , i - dq.front());
            }
            while(!dq.empty() && arr[dq.back()] > arr[i])dq.pop_back() ; 
            dq.push_back(i);
        }
    }
    cout << MAX << '\n' << range ;
    return 0 ;
}