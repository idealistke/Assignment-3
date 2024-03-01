//RONALDO NEVIS  ENE212-0089/2021

#include <stdio.h>

#define MAX_SIZE 100

void displayArray(int arr[], int size) {
    printf("Current Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void addElement(int arr[], int *size, int element) {
    // Find the correct position to maintain ascending order
    int index = 0;
    while (index < *size && arr[index] < element) {
        index++;
    }

    // Shift elements to make space for the new element
    for (int i = *size; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the element at the correct position
    arr[index] = element;
    (*size)++;
}

int removeElement(int arr[], int *size, int element) {
    int found = 0;
    for (int i = 0; i < *size; i++) {
        if (arr[i] == element) {
            // Shift elements to remove the specified element
            for (int j = i; j < *size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            (*size)--;
            found = 1;
            break;
        }
    }

    return found;
}

int main() {
    int array[MAX_SIZE];
    int size = 0;

    // Adding elements to the array
    addElement(array, &size, 7);
    addElement(array, &size, 8);
    addElement(array, &size, 80);
    addElement(array, &size, 87);

    // Displaying the current array
    displayArray(array, size);

    // Removing an element from the array
    int removedElement = 80;
    if (removeElement(array, &size, removedElement)) {
        printf("Element %d removed successfully.\n", removedElement);
    } else {
        printf("Failed to remove element %d.\n", removedElement);
    }

    // Displaying the array after removal
    displayArray(array, size);

    // Adding a new element to the array
    int newElement = 30;
    addElement(array, &size, newElement);
    printf("Element %d added to the array.\n", newElement);

    // Displaying the array after adding a new element
    displayArray(array, size);

    return 0;
}
