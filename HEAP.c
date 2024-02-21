#include <stdio.h>

#define PARENT(i) ((i - 1) >> 1)
#define LEFT(i) ((i << 1) + 1)
#define RIGHT(i) ((i << 1) + 2)

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void minHeapify(int arr[], int i, int heap_size) {
    int smallest = i;
    int left = LEFT(i);
    int right = RIGHT(i);

    if (left < heap_size && arr[left] < arr[smallest])
        smallest = left;

    if (right < heap_size && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, smallest, heap_size);
    }
}

void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, i, n);
}

int popRoot(int arr[], int *heap_size) {
    if (*heap_size <= 0)
        return -1;

    if (*heap_size == 1) {
        (*heap_size)--;
        return arr[0];
    }

    int root = arr[0];
    arr[0] = arr[*heap_size - 1];
    (*heap_size)--;
    minHeapify(arr, 0, *heap_size);

    return root;
}

void printHeap(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    buildMinHeap(arr, n);

    int choice;
    do {
        printf("\n1. Display the heap\n2. Pop the root and reheapify\n3. Peek\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printHeap(arr, n);
                break;
            case 2:
                popRoot(arr, &n);
                break;
            case 3:
                if (n > 0)
                    printf("Root of the heap: %d\n", arr[0]);
                else
                    printf("Heap is empty\n");
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}
