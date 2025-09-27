#include <iostream>
#include <string>
#include <vector>
using namespace std;

string formatText(string text) {
    string res = "";
    for (char c : text) {
        if (isalpha(c)) res += toupper(c == 'J' ? 'I' : c);
    }
    return res;
}

vector<vector<char>> generateKeySquare(string key) {
    bool used[26] = {false};
    used['J' - 'A'] = true;
    vector<vector<char>> square(5, vector<char>(5));
    string combined = formatText(key) + "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    int k = 0;
    for (char c : combined) {
        if (!used[c - 'A']) {
            square[k / 5][k % 5] = c;
            used[c - 'A'] = true;
            k++;
        }
    }
    return square;
}

pair<int,int> findPos(vector<vector<char>> &sq, char c) {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (sq[i][j] == c) return {i,j};
    return {-1,-1};
}

string playfairEncrypt(string text, string key) {
    vector<vector<char>> sq = generateKeySquare(key);
    string ftext = formatText(text);
    string res = "";
    for (int i = 0; i < ftext.size(); i += 2) {
        char a = ftext[i], b = (i+1 < ftext.size() ? ftext[i+1] : 'X');
        if (a == b) b = 'X';
        auto [r1,c1] = findPos(sq,a);
        auto [r2,c2] = findPos(sq,b);
        if (r1 == r2) {
            res += sq[r1][(c1+1)%5];
            res += sq[r2][(c2+1)%5];
        } else if (c1 == c2) {
            res += sq[(r1+1)%5][c1];
            res += sq[(r2+1)%5][c2];
        } else {
            res += sq[r1][c2];
            res += sq[r2][c1];
        }
    }
    return res;
}

string playfairDecrypt(string text, string key) {
    vector<vector<char>> sq = generateKeySquare(key);
    string res = "";
    for (int i = 0; i < text.size(); i += 2) {
        char a = text[i], b = text[i+1];
        auto [r1,c1] = findPos(sq,a);
        auto [r2,c2] = findPos(sq,b);
        if (r1 == r2) {
            res += sq[r1][(c1+4)%5];
            res += sq[r2][(c2+4)%5];
        } else if (c1 == c2) {
            res += sq[(r1+4)%5][c1];
            res += sq[(r2+4)%5][c2];
        } else {
            res += sq[r1][c2];
            res += sq[r2][c1];
        }
    }
    return res;
}

int main() {
    string text, key;
    cout << "Nhap van ban: ";
    getline(cin, text);
    cout << "Nhap khoa (chuoi): ";
    cin >> key;

    string encrypted = playfairEncrypt(text, key);
    string decrypted = playfairDecrypt(encrypted, key);

    cout << "Ma hoa (Playfair): " << encrypted << endl;
    cout << "Giai ma (Playfair): " << decrypted << endl;
}
