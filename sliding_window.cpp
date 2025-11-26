#include <iostream>
using namespace std;

int main() {
    int total_frames, window_size;

    cout << "Enter total number of frames: ";
    cin >> total_frames;

    cout << "Enter window size: ";
    cin >> window_size;

    int frame = 1;

    while (frame <= total_frames) {
        cout << "\n--- Sending Window ---\n";

        // Send frames in the current window
        for (int i = frame; i < frame + window_size && i <= total_frames; i++) {
            cout << "Sending Frame " << i << endl;
        }

        int ack;
        cout << "\nEnter the last ACK received: ";
        cin >> ack;

        if (ack >= frame && ack < frame + window_size) {
            cout << "Sliding the window...\n";
            frame = ack + 1;  // slide window
        } else {
            cout << "Invalid ACK! Try again.\n";
        }
    }

    cout << "\nAll frames sent successfully!" << endl;
    return 0;
}
