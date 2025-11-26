#include <iostream>
#include <vector>
using namespace std;

// Function to add two 8-bit binary numbers as strings
string addBinary(string a, string b) {
    string result = "";
    int carry = 0;

    for (int i = 7; i >= 0; i--) {
        int bitA = a[i] - '0';
        int bitB = b[i] - '0';

        int sum = bitA + bitB + carry;
        result = char((sum % 2) + '0') + result;
        carry = sum / 2;
    }

    // End-around carry
    if (carry == 1) {
        // Add carry to result
        for (int i = 7; i >= 0; i--) {
            int bit = result[i] - '0';
            int sum = bit + carry;
            result[i] = char((sum % 2) + '0');
            carry = sum / 2;
        }
    }

    return result;
}

// Function to take 1’s complement
string onesComplement(string s) {
    for (int i = 0; i < 8; i++) {
        s[i] = (s[i] == '0') ? '1' : '0';
    }
    return s;
}

int main() {
    int n;
    cout << "Enter number of 8-bit data blocks: ";
    cin >> n;

    vector<string> data(n);

    cout << "Enter each 8-bit binary block:\n";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    // Add all blocks
    string sum = data[0];
    for (int i = 1; i < n; i++) {
        sum = addBinary(sum, data[i]);
    }
    /* Sender side

        // Calculate checksum
        string checksum = onesComplement(sum);

        cout << "Checksum: " << checksum << endl;
    */
   /* Receiver side
         string result = onesComplement(sum);

        if (result == "00000000")
            cout << "No Error (Data Correct)\n";
        else
            cout << "Error Detected!\n";
   
   */
    return 0;
}
