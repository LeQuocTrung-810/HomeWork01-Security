#include <iostream>
#include <string>
using namespace std;

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1) return x;
    return -1;
}

string affineEncrypt(string text, int a, int b) {
    string result = "";
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            result += char(((a * (c - base) + b) % 26) + base);
        } else result += c;
    }
    return result;
}

string affineDecrypt(string text, int a, int b) {
    string result = "";
    int inv = modInverse(a, 26);
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            result += char(((inv * ((c - base - b + 26)) % 26) + 26) % 26 + base);
        } else result += c;
    }
    return result;
}

int main() {
    string text;
    int a, b;
    cout << "Nhap van ban: ";
    getline(cin, text);
    cout << "Nhap khoa a (gcd(a,26)=1): ";
    cin >> a;
    cout << "Nhap khoa b: ";
    cin >> b;

    string encrypted = affineEncrypt(text, a, b);
    string decrypted = affineDecrypt(encrypted, a, b);

    cout << "Ma hoa (Affine): " << encrypted << endl;
    cout << "Giai ma (Affine): " << decrypted << endl;
}
