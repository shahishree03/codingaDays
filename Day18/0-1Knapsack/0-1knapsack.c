#include <stdio.h>
#include <stdlib.h>

struct Item {
    int weight, value;
};

struct Node {
    int level, profit, bound, weight;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int bound(Node u, int n, int W, Item arr[]) {
    if (u.weight >= W) return 0;
    int profit_bound = u.profit;
    int j = u.level + 1;
    int totweight = u.weight;
    while ((j < n) && (totweight + arr[j].weight <= W)) {
        totweight += arr[j].weight;
        profit_bound += arr[j].value;
        j++;
    }
    if (j < n) profit_bound += (W - totweight) * arr[j].value / arr[j].weight;
    return profit_bound;
}

int knapsack(int W, Item arr[], int n) {
    Node u, v;
    u.level = -1;
    u.profit = u.weight = 0;
    int maxProfit = 0;
    int Q_size = 0;
    Node Q[100000];
    Q[Q_size++] = u;
    while (Q_size > 0) {
        u = Q[--Q_size];
        if (u.level == -1) v.level = 0;
        if (u.level == n - 1) continue;
        v.level = u.level + 1;
        v.weight = u.weight + arr[v.level].weight;
        v.profit = u.profit + arr[v.level].value;
        if (v.weight <= W && v.profit > maxProfit) maxProfit = v.profit;
        v.bound = bound(v, n, W, arr);
        if (v.bound > maxProfit) Q[Q_size++] = v;
        u.bound = bound(u, n, W, arr);
        if (u.bound > maxProfit) Q[Q_size++] = u;
    }
    return maxProfit;
}

int main() {
    int W = 50;
    Item arr[] = {{10, 60}, {20, 100}, {30, 120}};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Maximum possible profit: %d\n", knapsack(W, arr, n));
    return 0;
}