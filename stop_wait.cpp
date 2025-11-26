#include <iostream>
using namespace std;

int main() {
    int totalFrames;
    cout << "Enter number of frames to send: ";
    cin >> totalFrames;

    for (int frame = 1; frame <= totalFrames; frame++) {
        
        cout << "\nSending Frame " << frame << "..." << endl;

        int status;
        cout << "Enter 1 for ACK received, 0 for ACK lost, 2 for frame lost: ";
        cin >> status;

        if (status == 1) {
            cout << "ACK received for Frame " << frame << endl;
        }
        else if (status == 0) {
            cout << "ACK lost! Timeout occurred." << endl;
            cout << "Resending Frame " << frame << "..." << endl;
            cout << "ACK received for Frame " << frame << endl;
        }
        else if (status == 2) {
            cout << "Frame " << frame << " lost during transmission!" << endl;
            cout << "Resending Frame " << frame << "..." << endl;
            cout << "ACK received for Frame " << frame << endl;
        }
        else {
            cout << "Invalid input!" << endl;
            frame--;    // retry same frame
        }
    }

    cout << "\nAll frames sent successfully!" << endl;
    return 0;
}
