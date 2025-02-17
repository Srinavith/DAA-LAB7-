#include <stdio.h>
<<<<<<< HEAD
void swap(int* a, int* b) { 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
int partition (int arr[], int low, int high) { 
    int pivot = arr[high]; // pivot 
    int i = (low - 1);  
    for (int j = low; j <= high - 1; j++) { 
        if (arr[j] <= pivot) { 
            i++;  
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
void quickSort(int arr[], int low, int high) { 
    if (low < high) { 

        int pi = partition(arr, low, high); 


        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main() { 
    int arr[] = {10, 7, 8, 9, 1, 5}; 
    int n = sizeof(arr) / sizeof(arr[0]); 

    printf("Unsorted array: \n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1); 

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0; 
}
=======
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *cca(struct node *root, int node_1, int node_2) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data > node_1 && root->data > node_2) {
        return cca(root->left, node_1, node_2);
    }

    if (root->data < node_1 && root->data < node_2) {
        return cca(root->right, node_1, node_2);
    }

    return root;
}

struct node *newNode(int data) {
    struct node *p = (struct node*)malloc(sizeof(struct node));
    p->data = data;
    p->left = p->right = NULL;
    return p;
}

int main() {
    struct node *root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);

    int node_1 = 10, node_2 = 14;
    struct node *t = cca(root, node_1, node_2);
    printf("CCA of %d and %d is %d \n", node_1, node_2, t->data);

    node_1 = 14, node_2 = 8;
    t = cca(root, node_1, node_2);
    printf("CCA of %d and %d is %d \n", node_1, node_2, t->data);

    node_1 = 10, node_2 = 22;
    t = cca(root, node_1, node_2);
    printf("CCA of %d and %d is %d \n", node_1, node_2, t->data);

    return 0;
}
>>>>>>> 8614423 (message)
