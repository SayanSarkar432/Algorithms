#include <stdio.h>

void bubble_sort(float a[], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) {
                float temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
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

    bubble_sort(a, n);

    printf("Sorted array (Bubble Sort):\n");
    for (int i = 0; i < n; i++)
        printf("%.2f ", a[i]);
    printf("\n");

    return 0;
}