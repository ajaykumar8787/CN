#include <iostream>
#include <string>
using namespace std;

// Function to perform modulo-2 division (XOR division)
// This simulates polynomial division in CRC
string mod2div(string dividend, string divisor) {
    int n = divisor.length();
    string temp = dividend;

    // Loop through each bit of dividend until (length - divisor length)
    for (int i = 0; i <= temp.length() - n; i++) {
        // Only divide when the current bit is '1'
        if (temp[i] == '1') {
            // Perform XOR with divisor
            for (int j = 0; j < n; j++) {
                // If bits are same → result '0', else '1'
                temp[i + j] = (temp[i + j] == divisor[j]) ? '0' : '1';
            }
        }
    }

    // Remainder = last (n-1) bits
    return temp.substr(temp.length() - (n - 1));
}

int main() {
    string data, poly;
    cout << "Enter Data Bits: ";
    cin >> data;
    cout << "Enter Generator Polynomial: ";
    cin >> poly;

    int n = poly.length();

    // ================= Sender Side =================
    // Append (n-1) zeros to data (for division)
    string appended = data + string(n - 1, '0');

    // Calculate CRC remainder
    string crc = mod2div(appended, poly);

    // Transmitted frame = original data + CRC
    string transmitted = data + crc;

    cout << "\n--- Sender Side ---" << endl;
    cout << "Data: " << data << endl;
    cout << "Generator Polynomial: " << poly << endl;
    cout << "CRC: " << crc << endl;
    cout << "Transmitted Frame: " << transmitted << endl;

    // ================= Receiver Side =================
    cout << "\n--- Receiver Side ---" << endl;
    cout << "Enter Received Frame: ";
    string received;
    cin >> received;

    // Perform division again on received frame
    string remainder = mod2div(received, poly);

    // If remainder is all zeros → No Error
    if (remainder.find('1') == string::npos) {
        cout << "No Error Detected " << endl;
    } else {
        cout << "Error Detected " << endl;
    }

    return 0;
}