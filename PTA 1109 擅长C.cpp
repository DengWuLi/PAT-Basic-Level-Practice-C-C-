/// PTA 1109 擅长C
/// 2023/01/13
/// 大佬的思路就是厉害啊, 有必要跟随大佬的思路打题

#include <algorithm>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    setbuf(stdout, nullptr);
    vector<string> w;
    string str;
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 7; j++) {
            getline(cin, str);
            w.push_back(str);
        }
    // 读入句子
    getline(cin, str);
    // 对句子进行拆分处理
    vector<string> words;
    int size = str.size();
    int j;

    // 双指针处理字符串, 挑出句子里面的单词
    for (int i = 0; i < size;) {
        if (!isupper(str[i])) {
            i++;
            continue;
        }
        j = i;
        while (j < size && isupper(str[j]))
            j++;
        words.push_back(str.substr(i, j - i));
        i = j;
    }
    size = words.size();
    // 输出每个单词
    string word;
    int letter;
    for (int i = 0; i < size; i++) {
        word = words[i];

        // 记住要一行一行的遍历
        for (j = 0; j < 7; j++) {
            for (int k = 0; k < word.size(); k++) {
                letter = word[k] - 'A';
                if (k != 0)
                    cout << ' ';
                cout << w[letter * 7 + j];
            }
            cout << endl;
        }
        if (i != size - 1)
            cout << endl;
    }
}
