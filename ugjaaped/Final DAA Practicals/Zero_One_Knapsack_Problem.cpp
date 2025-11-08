#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to solve 0/1 Knapsack problem using DP
int knapsackDP(int W, vector<int>& wt, vector<int>& val, int n) {
    // dp[i][w] will store max value for i items and capacity w
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build DP table bottom-up
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]],
                               dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W]; // maximum value at last cell
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> val(n), wt(n);
    cout << "Enter values of items:\n";
    for (int i = 0; i < n; i++)
        cin >> val[i];

    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++)
        cin >> wt[i];

    cout << "Enter capacity of knapsack: ";
    cin >> W;

    int maxValue = knapsackDP(W, wt, val, n);

    cout << "\nMaximum value in Knapsack = " << maxValue << endl;
    return 0;
}

/*
Enter number of items: 4
Enter values of items:
60 100 120 80
Enter weights of items:
10 20 30 40
Enter capacity of knapsack: 50
*/