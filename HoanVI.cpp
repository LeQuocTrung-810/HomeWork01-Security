#include <iostream>
#include <string>
#include <vector>
using namespace std;

string transposeEncrypt(string text, int key) {
    string result = "";
    vector<string> grid(key, "");
    for (int i = 0; i < text.size(); i++) {
        grid[i % key] += text[i];
    }
    for (int i = 0; i < key; i++) result += grid[i];
    return result;
}

string transposeDecrypt(string text, int key) {
    int n = text.size();
    int colSize = (n + key - 1) / key;
    vector<string> grid(key, "");
    int index = 0;

    for (int i = 0; i < key; i++) {
        int len = colSize;
        if (i >= n % key && n % key != 0) len--;
        grid[i] = text.substr(index, len);
        index += len;
    }

    string result = "";
    for (int i = 0; i < colSize; i++) {
        for (int j = 0; j < key; j++) {
            if (i < grid[j].size()) result += grid[j][i];
        }
    }
    return result;
}

int main() {
    string text;
    int key;
    cout << "Nhap van ban: ";
    getline(cin, text);
    cout << "Nhap khoa (so cot): ";
    cin >> key;

    string encrypted = transposeEncrypt(text, key);
    string decrypted = transposeDecrypt(encrypted, key);

    cout << "Ma hoa (Hoan vi): " << encrypted << endl;
    cout << "Giai ma (Hoan vi): " << decrypted << endl;
}
