#include <iostream>
#include <string>
using namespace std;

string vigenereEncrypt(string text, string key) {
    string result = "";
    int j = 0;
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            char k = tolower(key[j % key.size()]) - 'a';
            result += char((c - base + k) % 26 + base);
            j++;
        } else result += c;
    }
    return result;
}

string vigenereDecrypt(string text, string key) {
    string result = "";
    int j = 0;
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            char k = tolower(key[j % key.size()]) - 'a';
            result += char((c - base - k + 26) % 26 + base);
            j++;
        } else result += c;
    }
    return result;
}

int main() {
    string text, key;
    cout << "Nhap van ban: ";
    getline(cin, text);
    cout << "Nhap khoa (chuoi): ";
    cin >> key;

    string encrypted = vigenereEncrypt(text, key);
    string decrypted = vigenereDecrypt(encrypted, key);

    cout << "Ma hoa (Vigenere): " << encrypted << endl;
    cout << "Giai ma (Vigenere): " << decrypted << endl;
}
