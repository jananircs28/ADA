#include <stdio.h>

int main() {
    int n = 4;
    int wt[4] = {3, 4, 6,5 };
    int val[4] = {2, 3, 1, 4};
    int W = 8;
    int k[5][9];

    // 🔹 Sort items by ascending weight (bubble sort)
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(wt[j] > wt[j + 1]) {
                // swap weights
                int temp = wt[j];
                wt[j] = wt[j + 1];
                wt[j + 1] = temp;

                // swap corresponding values
                int temp2 = val[j];
                val[j] = val[j + 1];
                val[j + 1] = temp2;
            }
        }
    }

    // 🔹 Knapsack DP
    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            if(i == 0 || w == 0) {
                k[i][w] = 0;
            }
            else if(wt[i - 1] <= w) {
                int include = val[i - 1] + k[i - 1][w - wt[i - 1]];
                int exclude = k[i - 1][w];

                if(include > exclude)
                    k[i][w] = include;
                else
                    k[i][w] = exclude;
            }
            else {
                k[i][w] = k[i - 1][w];
            }
        }
    }

    // 🔹 Output
    printf("Maximum value = %d\n", k[n][W]);

    // 🔹 Print sorted items
    printf("Items after sorting by weight:\n");
    for(int i = 0; i < n; i++) {
        printf("Weight = %d, Value = %d\n", wt[i], val[i]);
    }

    return 0;
}
