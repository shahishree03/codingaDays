#include<stdio.h>
#include<stdlib.h>

typedef struct {
  int key;
  int value;
} Hash;

Hash* temp;
Hash* arr[10];

int hashcode(int key) {
    return key % 10;
}

void insert(int key, int value) {
    Hash *t = (Hash*)malloc(sizeof(Hash));
    t->key = key;
    t->value = value;
    int hashIndex = hashcode(key);
    while (arr[hashIndex] != NULL && arr[hashIndex]->key != -1) {
        hashIndex++;
        hashIndex %= 10;
    }
    arr[hashIndex] = t;
}

Hash* search(int key) {
    int hashIndex = hashcode(key);
    for (int i = 0; i < 10; i++) {
        if (arr[hashIndex] != NULL && arr[hashIndex]->key == key)
            return arr[hashIndex];
        hashIndex++;
        hashIndex %= 10;
    }
    return NULL; // Return NULL if key not found
}

void deleteItem(int key) {
    int hashIndex = hashcode(key);
    for (int i = 0; i < 10; i++) {
        if (arr[hashIndex] != NULL && arr[hashIndex]->key == key) {
            free(arr[hashIndex]);
            arr[hashIndex] = NULL;
            return;
        }
        hashIndex++;
        hashIndex %= 10;
    }
    printf("Key %d not found for deletion.\n", key);
}

int main() {
    temp = (Hash*)malloc(10 * sizeof(Hash));
    temp->key = -1;
    temp->value = -1;

    insert(4, 12);
    insert(5, 8);
    insert(14, 8);

    printf("Hash table contents:\n");
    for (int i = 0; i < 10; i++) {
        if (arr[i] != NULL) {
            printf("(%d %d)\n", arr[i]->key, arr[i]->value);
        } else {
            printf("NULL here\n");
        }
    }

    Hash* foundItem = search(4);
    if (foundItem != NULL) {
        printf("\nFound item: (%d %d)\n", foundItem->key, foundItem->value);
    } else {
        printf("\nItem not found.\n");
    }

    printf("\nDelete item with key 4...\n");
    deleteItem(4);

    printf("Hash table contents after deletion:\n");
    for (int i = 0; i < 10; i++) {
        if (arr[i] != NULL) {
            printf("(%d %d)\n", arr[i]->key, arr[i]->value);
        } else {
            printf("NULL here\n");
        }
    }

    return 0;
}
