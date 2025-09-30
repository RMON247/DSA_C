 #include <stdio.h>
        #define SIZE 5  // Maximum size of the circular queue
    
        int queue[SIZE];
        int front = -1, rear = -1;
    
        // Function to check if the queue is full
        int isFull() {
            return (front == (rear + 1) % SIZE);
        }
    
        // Function to check if the queue is empty
        int isEmpty() {
            return (front == -1);
        }
    
        // Function to add element to the queue
        void enqueue(int value) {
            if (isFull()) {
                printf("Queue is full! Cannot insert %d\n", value);
            } else {
                if (front == -1)  // first element
                    front = 0;
                rear = (rear + 1) % SIZE;
                queue[rear] = value;
                printf("%d inserted into the queue.\n", value);
            }
        }
    
        // Function to remove element from the queue
        void dequeue() {
            if (isEmpty()) {
                printf("Queue is empty! Cannot dequeue.\n");
            } else {
                printf("%d removed from the queue.\n", queue[front]);
                if (front == rear) { // only one element was present
                    front = rear = -1;
                } else {
                    front = (front + 1) % SIZE;
                }
            }
        }
    
        // Function to display the queue
        void display() {
            if (isEmpty()) {
                printf("Queue is empty!\n");
            } else {
                printf("Queue elements: ");
                int i = front;
                while (1) {
                    printf("%d ", queue[i]);
                    if (i == rear)
                        break;
                    i = (i + 1) % SIZE;
                }
                printf("\n");
            }
        }
    
        // Main function
        int main() {
            int choice, value;
            while (1) {
                printf("\n--- Circular Queue Menu ---\n");
                printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
    
                switch (choice) {
                    case 1:
                        printf("Enter value to enqueue: ");
                        scanf("%d", &value);
                        enqueue(value);
                        break;
                    case 2:
                        dequeue();
                        break;
                    case 3:
                        display();
                        break;
                    case 4:
                        printf("Exiting program.\n");
                        return 0;
                    default:
                        printf("Invalid choice! Try again.\n");
                }
            }
        }