#include <stdio.h>

void selection_sort(float a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int j = i;
        for (int k = i + 1; k < n; k++)
            if (a[k] < a[j])
                j = k;
        if (i != j) {
            float temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
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

    selection_sort(a, n);

    printf("Sorted array (Selection Sort):\n");
    for (int i = 0; i < n; i++)
        printf("%.2f ", a[i]);
    printf("\n");

    return 0;
}