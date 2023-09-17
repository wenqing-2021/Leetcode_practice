
#include <vector>
#include <iostream>
using namespace std;

int gcd(int a, int b){
    while (b != 0){
    
    int temp = b;
    b =a % b;
    a = temp;

    }

    return a;
}


bool check(const int& num_1, const int& num_2, const int& k){
    
    if (std::abs(num_1*num_2) / gcd(num_1, num_2) == k){
        return true;
    }

    return false;
}

int main(){
    // int n, m, k;
    // cin >> n >> m >> k;

    // vector<int> arr_1(n, 0);
    // vector<int> arr_2(m, 0);

    // for (int i = 0; i < n; ++i){
    //     cin >> arr_1[i];
    // }

    // for (int j = 0; j < m; ++j){
    //     cin >> arr_2[j];
    // }
    int n = 3;
    int m = 3;
    int k = 6;

    vector<int> arr_1 = {1, 1, 6};
    vector<int> arr_2 = {2, 2, 3};

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (check(arr_1[i-1], arr_2[j-1], k)){
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]) + 1;
            } else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    int res = dp[n][m];

    std::cout << res;

    return 0;
}