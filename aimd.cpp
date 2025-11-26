#include <iostream>
using namespace std;

int main() {
    int cwnd;   // congestion window
    cout << "Enter initial congestion window (cwnd): ";
    cin >> cwnd;

    while (true) {
        int event;
        cout << "\nEvent? (1 = ACK, 0 = Loss/Timeout, -1 = Exit): ";
        cin >> event;

        if (event == -1)
            break;

        if (event == 1) {
            // Additive Increase
            cwnd = cwnd + 1;
            cout << "ACK received → Additive Increase" << endl;
            cout << "New cwnd = " << cwnd << endl;
        }
        else if (event == 0) {
            // Multiplicative Decrease
            cwnd = cwnd / 2;
            if (cwnd < 1) cwnd = 1;  // prevent zero window
            cout << "Loss detected → Multiplicative Decrease" << endl;
            cout << "New cwnd = " << cwnd << endl;
        }
        else {
            cout << "Invalid input!" << endl;
        }
    }

    return 0;
}
