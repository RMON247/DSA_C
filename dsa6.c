#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
struct Node {
    char song[50];
    struct Node* next;
};

struct Node* top = NULL;

// Push = Play new song
void push(char* songName) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->song, songName);
    newNode->next = top;
    top = newNode;
    printf("Now playing: %s\n", songName);
}

// Pop = Go back to previous song
void pop() {
    if (top == NULL) {
        printf("No previous song!\n");
        return;
    }
    printf("Stopping: %s\n", top->song);
    struct Node* temp = top;
    top = top->next;
    free(temp);
    if (top != NULL)
        printf("Now playing: %s\n", top->song);
    else
        printf("No song playing.\n");
}

// Peek = Current song
void peek() {
    if (top == NULL) {
        printf("No song is playing.\n");
    } else {
        printf("Currently playing: %s\n", top->song);
    }
}

// Display playlist history
void display() {
    if (top == NULL) {
        printf("Playlist is empty.\n");
        return;
    }
    struct Node* temp = top;
    printf("Playlist history (latest first):\n");
    while (temp != NULL) {
        printf("%s -> ", temp->song);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;
    char song[50];

    while (1) {
        printf("\n--- Music Player Menu ---\n");
        printf("1. Play New Song (Push)\n");
        printf("2. Go Back to Previous Song (Pop)\n");
        printf("3. Show Current Song (Peek)\n");
        printf("4. Show Playlist History (Display)\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter song name: ");
                scanf(" %[^\n]", song); // to accept multi-word input
                push(song);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}