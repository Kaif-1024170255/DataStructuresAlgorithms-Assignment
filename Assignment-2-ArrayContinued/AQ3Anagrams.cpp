#include <iostream>
using namespace std;
bool areAnagrams(string str1, string str2) {
    if (str1.length() != str2.length())
        return false;
    int count[26] = {0};
    for (int i = 0; str1[i] != '\0'; i++) {
        count[str1[i] - 'a']++;
        count[str2[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0)
            return false;
    }

    return true;
}
int main() {
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    if (areAnagrams(str1, str2))
        cout << "YES, they are anagrams.";
    else
        cout << "NO, they are not anagrams.";

    return 0;
}
