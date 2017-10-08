#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int ch[26] = {0};

char *find_no_repet(string str) {

    int s1 = 0, s2 = 0;
    int len = 0, x, y;
    for (; s1 < str.length(); ++s1) {
        ch[str[s1] - 'A']++;
        if (ch[str[s1] - 'A'] == 2) {
            for (; s2 <= s1; ++s2) {
                ch[str[s2] - 'A']--;
                if (ch[str[s2] - 'A']) {
                    ++s2;
                    break;
                }
            }
        }
        if ((s1 - s2) > len) {
            len = s1 - s2;
            x = s2; 
            y = s1;
        }
    }
    char *buffer = (char *)malloc(sizeof(char) * (y - x + 2));
    str.copy(buffer, (y - x + 1), x);
    buffer[y - x + 1] = '\0';
    return buffer;
}

int main() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    cout << find_no_repet(str) << endl;
    return 0;
}