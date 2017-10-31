#include <bits/stdc++.h>
using namespace std;
 
int main() {
    vector<int> xx(4);
    for (int i = 0; i < 4; i++) cin >> xx[i];
    sort(xx.begin(), xx.end());
    long long A = xx[0], B = xx[1], C = xx[2], D = xx[3];
 
    vector<int> cnt(10000);
    int total = 0;
 
    for (int i = 1; i <= C; i++) {
        for (int j = i; j <= D; j++) {
            cnt[i ^ j]++;
            total++;
        }
    }
 
    long long ans = 0;
    for (int b = 1; b <= B; b++) {
        for (int a = 1; a <= min<int>(A, b); a++) {
            ans += total - cnt[a ^ b];
        }
        for (int d = b; d <= D; d++) {
            cnt[b ^ d]--;
            total--;
        }
    }
    cout << ans << endl;
}
