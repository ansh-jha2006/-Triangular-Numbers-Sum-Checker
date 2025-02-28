#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int binarySearch(int low, int high, int key, int *arr) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return 1;
        if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return 0;
}

bool canBeRepresentedAsSumOfTwoTriangularNumbers(int n) {
    int t[10000], c = 0;
    for (int a = 1; ; a++) {
        int T = a * (a + 1) / 2;
        if (T > n) break;
        t[c++] = T;
    }
    qsort(t, c, sizeof(int), compare);
    for (int i = 0; i < c; i++) {
        int comp = n - t[i];
        if (comp >= 0 && binarySearch(0, c - 1, comp, t)) return true;
    }
    return false;
}

int main() {
    int n;
    scanf("%d", &n);
    printf(canBeRepresentedAsSumOfTwoTriangularNumbers(n) ? "YES\n" : "NO\n");
    return 0;
}
