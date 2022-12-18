#include <iostream>

using namespace std;

int sol[21][21];
int row[21], col[21];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int n; cin >> n;

  for(int i=1; i<=n; i++) cin >> row[i];
  for(int i=1; i<=n; i++) cin >> col[i];

  for(int i=1; i<=n; i++) {
    int sum=row[i];
    for(int j=1; j<=n; j++) {
      if(col[j]!=0 && sum>0) {
        if(col[j]>=sum) {
          cout << sum << " ";
          col[j] -= sum;
          sum = 0;
        }else {
          cout << col[j] << " ";
          sum -= col[j];
          col[j] = 0;
        }
      }else {
        cout << "0 ";
      }
    }
    cout << "\n";
  }

  return 0;
}