#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 1000

typedef struct {
    char key[50];
    int value;
} KeyValuePair;

typedef struct {
    KeyValuePair table[TABLE_SIZE];
} HashTable;

unsigned int hashFunction(const char *key) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash * 31) + (*key);
        key++;
    }
    return hash % TABLE_SIZE;
}

void initHashTable(HashTable *hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->table[i].key[0] = '\0';
        hashTable->table[i].value = -1;
    }
}

void insert(HashTable *hashTable, const char *key, int value) {
    unsigned int index = hashFunction(key);
    while (hashTable->table[index].value != -1) {
        index = (index + 1) % TABLE_SIZE;
    }
    strcpy(hashTable->table[index].key, key);
    hashTable->table[index].value = value;
}

int find(HashTable *hashTable, const char *key) {
    unsigned int index = hashFunction(key);
    while (hashTable->table[index].value != -1) {
        if (strcmp(hashTable->table[index].key, key) == 0) {
            return hashTable->table[index].value;
        }
        index = (index + 1) % TABLE_SIZE;
    }
    return -1; // Key not found
}

int main() {
    HashTable hashTable;
    initHashTable(&hashTable);

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        char key[50];
        int value;
        scanf("%s", key);
        value = 1;
        insert(&hashTable, key, value);
    }

    //scanf("%d", &m);
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        char target[50];
        scanf("%s", target);

        //int value = find(&hashTable, target);
        if (find(&hashTable, target) == 1){
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}
