#include <stdio.h>

struct Items {
    int weight;
    int profit;
};

int greedyforweight(struct Items item[], int n, int knap_size) {
    int weight = 0, profit = 0;
    
    for (int i = 0; i < n; i++) {
        if (weight + item[i].weight <= knap_size) {
            weight = weight + item[i].weight;
            profit = profit + item[i].profit;
        }
    }
    return profit;
}

int main() {
    int n, knap_size;
    
    printf("Enter the number of items and Knapsack size: ");
    scanf("%d %d", &n, &knap_size);
    
    struct Items item[n];
    
    for (int i = 0; i < n; i++) {
        printf("Enter weight and profit for item %d: ", i + 1);
        scanf("%d %d", &item[i].weight, &item[i].profit);
    }
    
    int max_profit = greedyforweight(item, n, knap_size);
    
    printf("Maximum profit is %d\n", max_profit);
    
    return 0;
}
