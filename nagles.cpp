#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<char> buffer;  // sender buffer (waiting data)
    bool ackPending = false;  // is an unacknowledged packet in flight?
    
    string data;
    cout << "Enter data (characters): ";
    cin >> data;

    cout << "\n--- Nagle's Algorithm Simulation ---\n";

    for (char ch : data) {
        buffer.push(ch);
        cout << "Data arrived: " << ch << endl;

        if (!ackPending) {
            // Send one small packet
            cout << "Sending packet: " << buffer.front() << endl;
            buffer.pop();
            ackPending = true;
        } 
        else {
            // Can't send more until ACK arrives
            cout << "ACK pending... data buffered.\n";
        }

        // Simulate an ACK received for every character
        cout << "ACK received.\n";
        ackPending = false;

        // After ACK, send all buffered data at once
        if (!buffer.empty()) {
            cout << "Sending accumulated packet: ";
            while (!buffer.empty()) {
                cout << buffer.front();
                buffer.pop();
            }
            cout << endl;
        }

        cout << "----------------------------------\n";
    }

    return 0;
}
