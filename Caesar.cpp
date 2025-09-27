#include <iostream>
#include <string>
using namespace std;

string caesarEncrypt(string text, int key) {
    string result = "";
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            result += char((c - base + key) % 26 + base);
        } else result += c;
    }
    return result;
}

string caesarDecrypt(string text, int key) {
    return caesarEncrypt(text, 26 - key);
}

int main() {
    string text;
    int key;
    cout << "Nhap van ban: ";
    getline(cin, text);
    cout << "Nhap khoa (key): ";
    cin >> key;

    string encrypted = caesarEncrypt(text, key);
    string decrypted = caesarDecrypt(encrypted, key);

    cout << "Ma hoa (Caesar): " << encrypted << endl;
    cout << "Giai ma (Caesar): " << decrypted << endl;
}
