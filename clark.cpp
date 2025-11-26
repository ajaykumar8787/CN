#include <iostream>
using namespace std;

int main() {
    int bufferSize, used, MSS;

    cout << "Enter Receiver Buffer Size: ";
    cin >> bufferSize;

    cout << "Enter MSS (Maximum Segment Size): ";
    cin >> MSS;

    cout << "\n--- Clark's Algorithm Simulation ---\n";

    while (true) {
        cout << "\nEnter currently used buffer (or -1 to exit): ";
        cin >> used;

        if (used == -1)
            break;

        int freeSpace = bufferSize - used;
        cout << "Free Space: " << freeSpace << endl;

        // Clark's Algorithm logic
        if (freeSpace >= MSS) {
            cout << "Receiver advertises window = " << freeSpace 
                 << " (Enough space available)\n";
        }
        else if (freeSpace >= bufferSize / 2) {
            cout << "Receiver advertises window = " << freeSpace
                 << " (Half buffer free)\n";
        }
        else {
            cout << "Receiver advertises window = 0 (Clark blocks tiny window)\n";
        }
    }

    return 0;
}
