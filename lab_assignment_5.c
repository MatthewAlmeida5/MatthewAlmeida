#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char letter;
    struct Node* next;
} node;

int length(node* head) {
    int count = 0;
    node* current = head;
    
    while (current != NULL) {
        count++;
        current = current->next;
    }
    
    return count;
}

char* tocstring(node* head) {
    int len = length(head);
    char* str = (char*)malloc((len + 1) * sizeof(char));
    
    node* current = head;
    int i = 0;
    
    while (current != NULL) {
        str[i] = current->letter;
        current = current->next;
        i++;
    }
    
    str[i] = '\0';
    return str;
}

void insertChar(node** pHead, char c) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->letter = c;
    newNode->next = NULL;
    
    if (*pHead == NULL) {
        *pHead = newNode;
    } else {
        node* current = *pHead;
        
        while (current->next != NULL) {
            current = current->next;
        }
        
        current->next = newNode;
    }
}

void deletelist(node** pHead) {
    node* current = *pHead;
    
    while (current != NULL) {
        node* nextNode = current->next;
        free(current);
        current = nextNode;
    }
    
    *pHead = NULL;
}

int main() {
    FILE* inputFile = fopen("/Users/matthewalmeida/Desktop/input.txt", "r");
    if (inputFile == NULL) {
        printf("Failed to open input.txt\n");
        return 1;
    }
    
    int n;
    char c;
    while (fscanf(inputFile, "%d", &n) == 1) {
        node* head = NULL;
        for (int i = 0; i < n; i++) {
            fscanf(inputFile, " %c", &c);
            insertChar(&head, c);
        }
        
        char* str = tocstring(head);
        printf("String is : (%s)\n", str);
        free(str);
        
        deletelist(&head);
    }
    
    fclose(inputFile);
    return 0;
}
