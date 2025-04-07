#include <stdio.h>

void quick_sort(float a[], int m, int n) {
    if (m < n) {
        float key = a[m];
        int i = m, j = n + 1;
        while (1) {
            do { i++; } while (i <= n && a[i] < key);
            do { j--; } while (a[j] > key);
            if (i < j) {
                float temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            } else break;
        }
        float temp = a[m];
        a[m] = a[j];
        a[j] = temp;

        quick_sort(a, m, j - 1);
        quick_sort(a, j + 1, n);
    }
}

int main() {
    float a[100];
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d decimal elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%f", &a[i]);

    quick_sort(a, 0, n - 1);

    printf("Sorted array (Quick Sort):\n");
    for (int i = 0; i < n; i++)
        printf("%.2f ", a[i]);
    printf("\n");

    return 0;
}
