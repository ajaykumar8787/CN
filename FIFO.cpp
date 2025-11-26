#include <iostream>
using namespace std;

#define SIZE 10

int main() {
    int queue[SIZE];
    int front = -1, rear = -1;
    int choice, item;

    while (true) {
        cout << "\n--- FIFO Queue Menu ---\n";
        cout << "1. Enqueue (Insert)\n";
        cout << "2. Dequeue (Delete)\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {              // ENQUEUE
            if (rear == SIZE - 1) {
                cout << "Queue Overflow! (Buffer full)\n";
            } else {
                cout << "Enter value to insert: ";
                cin >> item;

                if (front == -1) front = 0;
                rear++;
                queue[rear] = item;

                cout << "Inserted: " << item << endl;
            }
        }
        else if (choice == 2) {         // DEQUEUE
            if (front == -1 || front > rear) {
                cout << "Queue Underflow! (No packets)\n";
                front = rear = -1;
            } else {
                cout << "Deleted: " << queue[front] << endl;
                front++;
            }
        }
        else if (choice == 3) {         // DISPLAY
            if (front == -1) {
                cout << "Queue is Empty!\n";
            } else {
                cout << "Queue (FIFO Order): ";
                for (int i = front; i <= rear; i++) {
                    cout << queue[i] << " ";
                }
                cout << endl;
            }
        }
        else if (choice == 4) {
            cout << "Exiting..." << endl;
            break;
        }
        else {
            cout << "Invalid Choice!" << endl;
        }
    }

    return 0;
}
