#include<bits/stdc++.h>
#define vec vector
#define umap unordered_map
#define endll '\n'
using namespace std ;
int main(){
	ios_base :: sync_with_stdio(0),cin.tie(0);
	int p2 , p1 , com2 = 0 , com1 = 0 ;
	cin >> p2 ; p1 = p2 ;
	int temp ; 
	while(p1 > 0 && p2 > 0){
		cin >> temp ;
		if(temp & 1){
			com1 += 1 ;
			com2 = 0 ;
			if(com1 >= 3){
				p2 -= 3;
			}
			else p2 -= 1 ;
		}
		else {
			com1 = 0 ;
			com2 += 1;
			if(com2 >= 3)p1 -= 3;
			else p1 -= 1 ;
		}
	}
	if(p1 <= 0)cout << 0 << endll << temp ;
	else cout << 1 << endll << temp ;
	return 0 ;
}