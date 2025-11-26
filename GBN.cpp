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
        // Send window of frames
        for (int i = frame; i < frame + window_size && i <= total_frames; i++) {
            cout << "Sending Frame " << i << endl;
        }

        // Simulate ACK status
        int ack;
        cout << "\nEnter ACK for last frame of window ("
             << frame + window_size - 1 << ") : ";
        cout << "\nEnter frame number where error occurred (0 for no error): ";
        cin >> ack;

        if (ack == 0) {
            // All frames acknowledged
            cout << "All frames in the window acknowledged.\n";
            frame += window_size;     // move window forward
        }
        else {
            // Error occurred at frame ack
            cout << "\nError detected at Frame " << ack << "!" << endl;
            cout << "Go-Back-N: Resending from Frame " << ack << endl;
            frame = ack;              // go back to erroneous frame
        }
    }

    cout << "\nAll frames sent successfully!" << endl;
    return 0;
}
