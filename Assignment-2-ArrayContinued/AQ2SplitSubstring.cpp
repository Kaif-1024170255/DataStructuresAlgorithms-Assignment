#include <iostream>
#include <string>
using namespace std;
bool isSubstring(const string &str1, const string &str2) {
    int n1 = str1.length();
    int n2 = str2.length();

    for (int i = 0; i <= n1 - n2; i++) {
        int j;
        for (j = 0; j < n2; j++) {
            if (str1[i + j] != str2[j])
                break;
        }
        if (j == n2) return true;
    }
    return false;
}
bool canSplit(const string &s) {
    int n = s.length();
    for (int i = 1; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            string a = s.substr(0, i);
            string b = s.substr(i, j - i);
            string c = s.substr(j);
            if ((isSubstring(a, b) && isSubstring(c, b)) ||
                (isSubstring(b, a) && isSubstring(c, a)) ||
                (isSubstring(a, c) && isSubstring(b, c)))
                return true;
        }
    }
    return false;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    if (canSplit(s))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
