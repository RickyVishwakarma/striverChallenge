#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;


ll contribution(int len) {

    return 1LL * len * (len + 1) * (len + 2) / 6;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }

        ll total = 0;
        int i = 0;


        while (i < n) {
            int j = i;

          
            while (j + 1 < n && p[j] > p[j + 1]) {
                j++;
            }

            int len = j - i + 1;

          
            total += contribution(len);


            i = j + 1;
        }

        cout << total << '\n';
    }

    return 0;
}
