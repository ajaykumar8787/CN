#include <iostream>
using namespace std;

int main() {
    int cwnd = 1;       // initial congestion window
    int ssthresh;       // slow-start threshold

    cout << "Enter initial ssthresh value: ";
    cin >> ssthresh;

    while (true) {

        cout << "\nCurrent cwnd = " << cwnd 
             << ", ssthresh = " << ssthresh << endl;

        int event;
        cout << "Event? (1 = ACK, 0 = Loss, -1 = Exit): ";
        cin >> event;

        if (event == -1)
            break;

        if (event == 1) {
            // ACK received → Slow Start or Congestion Avoidance
            if (cwnd < ssthresh) {
                // SLOW START → exponential growth
                cwnd = cwnd * 2;
                cout << "Slow Start: cwnd doubled → " << cwnd << endl;
            } else {
                // CONGESTION AVOIDANCE → additive increase
                cwnd = cwnd + 1;
                cout << "Congestion Avoidance: cwnd increased → " << cwnd << endl;
            }
        }
        else if (event == 0) {
            // Packet loss
            cout << "Packet loss detected!" << endl;
            ssthresh = cwnd / 2;
            if (ssthresh < 1) ssthresh = 1;

            cwnd = 1;  // reset to slow start
            cout << "New ssthresh = " << ssthresh << endl;
            cout << "cwnd reset to 1 → Restart Slow Start\n";
        }
        else {
            cout << "Invalid input!" << endl;
        }
    }

    return 0;
}
