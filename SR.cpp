#include <iostream>
using namespace std;

int main() {
    int total_frames, window_size;

    cout << "Enter total number of frames: ";
    cin >> total_frames;

    cout << "Enter window size: ";
    cin >> window_size;

    int ack[100];  // to store ACK status of each frame

    for (int i = 1; i <= total_frames; i += window_size) {

        cout << "\n--- Sending Window ---\n";

        // Sending all frames in the window
        for (int j = i; j < i + window_size && j <= total_frames; j++) {
            cout << "Sending Frame " << j << endl;
            ack[j] = 0;   // initialize as not acknowledged
        }

        cout << "\n--- Enter ACK Status ---\n";
        cout << "(1 = ACK received, 0 = Frame lost)\n";

        // Take ACK input for each frame in window
        for (int j = i; j < i + window_size && j <= total_frames; j++) {
            cout << "ACK for Frame " << j << ": ";
            cin >> ack[j];
        }

        // Resend only frames that were lost
        for (int j = i; j < i + window_size && j <= total_frames; j++) {
            if (ack[j] == 0) {
                cout << "Frame " << j << " lost! Retransmitting..." << endl;
                cout << "Sending Frame " << j << endl;
                cout << "ACK received for Frame " << j << endl;
            }
        }

        cout << "\nWindow completed.\n";
    }

    cout << "\nAll Frames Sent Successfully!" << endl;
    return 0;
}
