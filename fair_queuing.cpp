#include <iostream>
#include <queue>
using namespace std;

int main() {
    int flows;
    cout << "Enter number of flows: ";
    cin >> flows;

    queue<int> q[10];  // maximum 10 flows

    // Input packets for each flow
    for (int i = 0; i < flows; i++) {
        int n;
        cout << "Enter number of packets in Flow " << i+1 << ": ";
        cin >> n;

        cout << "Enter packets: ";
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            q[i].push(x);
        }
    }

    cout << "\n--- Fair Queuing Output (Round Robin) ---\n";

    bool packetsLeft = true;

    while (packetsLeft) {
        packetsLeft = false;

        for (int i = 0; i < flows; i++) {
            if (!q[i].empty()) {
                cout << "Flow " << i+1 << ": Sent Packet " << q[i].front() << endl;
                q[i].pop();
                packetsLeft = true;
            }
        }
    }

    cout << "\nAll packets transmitted fairly.\n";

    return 0;
}
