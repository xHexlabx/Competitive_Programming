#include<bits/stdc++.h>
#define endll '\n'
using namespace std ;
int main(){
	ios_base :: sync_with_stdio(0),cin.tie(0);
	int MAX = INT_MIN ;
	
	int table[50001][71] = {0};
	int t ; cin >> t ;
	int row , str , stp ;
	while(t--){
		cin >> row >> str >> stp ;
		row -- ; str -- ;
		MAX = max(row , MAX);
		for(int i = str ; i < str + stp && i <= 69 ; i ++){
			table[row][i] = 1;
		}
	}
	for(int i  = 0 ; i <= MAX ; i ++){
		for(int j = 0 ; j < 70 ; j ++){
			cout << (table[i][j] ? 'x' : 'o');
		}
		cout << endll;
	}
	return 0 ;
}