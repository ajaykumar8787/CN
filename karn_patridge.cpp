#include <iostream>
using namespace std;

int main() {
    double RTO;
    cout << "Enter initial RTO (in ms): ";
    cin >> RTO;

    while (true) {
        int status;
        cout << "\nEnter ACK status (1 = ACK OK, 0 = Timeout, -1 = exit): ";
        cin >> status;

        if (status == -1)
            break;

        if (status == 1) {
            cout << "ACK received for non-retransmitted packet.\n";
            cout << "RTO remains = " << RTO << " ms\n";
        }
        else if (status == 0) {
            cout << "Timeout occurred! Retransmission needed.\n";

            // Karn/Partridge: exponential backoff
            RTO = RTO * 2;
            cout << "New RTO = " << RTO << " ms (after exponential backoff)\n";
        }
        else {
            cout << "Invalid input!\n";
        }
    }

    return 0;
}
