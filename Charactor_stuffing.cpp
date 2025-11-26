#include <iostream>
#include <string>
using namespace std;

int main() {
    // ===================== Stuffing =====================
    string data;
    cout << "Enter data: ";
    getline(cin, data);

    string stuffed = "";

    // Add START of frame
    stuffed += "DLESTX";

    // Stuffing process
    for (int i = 0; i < data.length(); i++) {
        if (data.substr(i, 3) == "DLE") {
            stuffed += "DLEDLE";  // Stuffed DLE
            i += 2;               // Skip next two characters
        } else {
            stuffed += data[i];   // Normal character
        }
    }

    // Add END of frame
    stuffed += "DLEETX";

    cout << "Stuffed Data: " << stuffed << endl;

    // ===================== Destuffing =====================
    string frame;
    cout << "Enter stuffed frame: ";
    getline(cin, frame);

    string destuffed = "";

    // Validate frame format
    if (frame.size() >= 12 &&
        frame.substr(0, 6) == "DLESTX" &&
        frame.substr(frame.size() - 6) == "DLEETX") {

        // Extract inside part (remove DLESTX and DLEETX)
        string inside = frame.substr(6, frame.size() - 12);

        for (int i = 0; i < inside.length(); i++) {
            if (inside.substr(i, 6) == "DLEDLE") {
                destuffed += "DLE";    // Original DLE
                i += 5;                // Skip stuffed part
            } else {
                destuffed += inside[i];
            }
        }

        cout << "Destuffed Data: " << destuffed << endl;
    } else {
        cout << "Invalid stuffed frame format!" << endl;
    }

    return 0;
}