#include <iostream>
#include <string>
using namespace std;

string bitStuffing(const string &data) {
    string stuffed = "";
    int count = 0;

    for (char bit : data) {
        stuffed += bit;

        if (bit == '1') {
            count++;
            if (count == 5) {
                stuffed += '0';  // insert 0 after 5 consecutive 1s
                count = 0;
            }
        } else {
            count = 0;
        }
    }
    return stuffed;
}

string bitDestuffing(const string &data) {
    string destuffed = "";
    int count = 0;

    for (int i = 0; i < data.length(); i++) {
        destuffed += data[i];

        if (data[i] == '1') {
            count++;

            if (count == 5) {
                i++;          // skip the stuffed 0
                count = 0;
            }
        } else {
            count = 0;
        }
    }

    return destuffed;
}

int main() {
    string data;
    cout << "Enter binary data: ";
    cin >> data;

    string result = bitStuffing(data);
    cout << "Stuffed Data: " << result << endl;

    cout << "Destuffed Data: " << bitDestuffing(data) << endl;
    return 0;
}
