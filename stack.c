#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int s[MAX];
int top = -1;

void push();
void pop();
void display();

int main() {
    int ch;
    for( ; ; ) {
        printf("stack");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

void push() {
    int item;
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        printf("Enter the element to push: ");
        scanf("%d", &item);
        top++;
        s[top] = item;
    }
}

void pop() {
    int item;
    if (top == -1) {
        printf("Stack underflow\n");
    } else {
        item = s[top];
        printf("Deleted item = %d\n", item);
        top--;
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", s[i]);
        }
        printf("\n");
    }
}
