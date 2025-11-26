#include <iostream>
#include <queue>
using namespace std;

int main() {
    int flows;
    cout << "Enter number of flows: ";
    cin >> flows;

    queue<string> q[10];       // packets for each flow
    int weight[10];            // weight for each flow
    int packets;

    // Input flows
    for (int i = 0; i < flows; i++) {
        cout << "\nEnter number of packets in Flow " << i+1 << ": ";
        cin >> packets;

        cout << "Enter packet names: ";
        for (int j = 0; j < packets; j++) {
            string p;
            cin >> p;
            q[i].push(p);
        }

        cout << "Enter weight of Flow " << i+1 << ": ";
        cin >> weight[i];
    }

    cout << "\n=== Weighted Fair Queuing Transmission Order ===\n";

    bool remaining = true;

    while (remaining) {
        remaining = false;

        // For each flow, send packets equal to its weight
        for (int i = 0; i < flows; i++) {

            for (int w = 0; w < weight[i]; w++) {

                if (!q[i].empty()) {
                    cout << q[i].front() << " ";
                    q[i].pop();
                    remaining = true;
                }
            }
        }
    }

    cout << "\nAll packets transmitted using WFQ.\n";

    return 0;
}
