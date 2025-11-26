#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int main() {
    queue<string> dhcpPool;                  // available IPs
    unordered_map<string, string> assigned;  // device → IP

    int n;
    cout << "How many IPs in DHCP pool? ";
    cin >> n;

    cout << "Enter IPs available in DHCP pool:\n";
    for (int i = 0; i < n; i++) {
        string ip;
        cin >> ip;
        dhcpPool.push(ip);
    }

    while (true) {
        int choice;
        cout << "\n1. Request IP (DHCP)\n2. Release IP\n3. Show Assignments\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {  
            string device;
            cout << "Enter device name: ";
            cin >> device;

            if (dhcpPool.empty()) {
                cout << "No IP available in DHCP pool!\n";
            } 
            else {
                string ip = dhcpPool.front();
                dhcpPool.pop();
                assigned[device] = ip;
                cout << "Assigned IP to " << device << " = " << ip << endl;
            }
        }
        else if (choice == 2) {  
            string device;
            cout << "Enter device to release IP: ";
            cin >> device;

            if (assigned.count(device)) {
                dhcpPool.push(assigned[device]);
                cout << "Released IP: " << assigned[device] << endl;
                assigned.erase(device);
            } 
            else {
                cout << "Device not found.\n";
            }
        }
        else if (choice == 3) {  
            cout << "\nCurrent DHCP Assignments:\n";
            for (auto &p : assigned) {
                cout << p.first << " => " << p.second << endl;
            }
        }
        else break;
    }

    return 0;
}
