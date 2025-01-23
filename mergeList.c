// David Ouma SCT221-0273/2022
// Stanley Omondi SCT221-0278/2022
// Jason Kabugi SCT221-0581/2022

#include <stdio.h>
#include <stdlib.h>

int* mergeSortedLists(int* list1, int size1, int* list2, int size2, int* mergedSize) {
    int* mergedList = (int*)malloc((size1 + size2) * sizeof(int));

    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (list1[i] < list2[j]) {
            mergedList[k] = list1[i];
            i++;
        } else {
            mergedList[k] = list2[j];
            j++;
        }
        k++;
    }

    while (i < size1) {
        mergedList[k] = list1[i];
        i++;
        k++;
    }

    // Add any remaining elements from list2
    while (j < size2) {
        mergedList[k] = list2[j];
        j++;
        k++;
    }

    *mergedSize = k;

    // Return the pointer to the merged list
    return mergedList;
}

int main() {
    int list1[] = {1, 3, 5, 7};
    int list2[] = {2, 4, 6, 8};

    // Calculate the sizes of the input lists
    int size1 = sizeof(list1) / sizeof(list1[0]);
    int size2 = sizeof(list2) / sizeof(list2[0]);

    int mergedSize;

    // Call the merge function
    int* mergedList = mergeSortedLists(list1, size1, list2, size2, &mergedSize);

    // Print the merged list
    printf("Merged Sorted List: ");
    for (int i = 0; i < mergedSize; i++) {
        printf("%d ", mergedList[i]);
    }
    printf("\n");

    free(mergedList);

    return 0;
}


/* RECURRENCE RELATION
n = size1 + size2
O(1)
recurrence relation is:
        T(n) = T(n-1) + O(1)

Time Complexity
T(n) = T(n-1) + O(1) = O(n)
overall time complexity is O(n)

Space Complexity
    O(n)
*\
