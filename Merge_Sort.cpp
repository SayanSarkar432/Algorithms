#include <stdio.h>

void merge(float a[], int p, int q, int r) {
    int n1 = q - p + 1, n2 = r - q;
    float L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = a[p + i];
    for (int j = 0; j < n2; j++) R[j] = a[q + 1 + j];

    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }
    while (i < n1)
        a[k++] = L[i++];
    while (j < n2)
        a[k++] = R[j++];
}

void merge_sort(float a[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(a, p, q);
        merge_sort(a, q + 1, r);
        merge(a, p, q, r);
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

    merge_sort(a, 0, n - 1);

    printf("Sorted array (Merge Sort):\n");
    for (int i = 0; i < n; i++)
        printf("%.2f ", a[i]);
    printf("\n");

    return 0;
}
