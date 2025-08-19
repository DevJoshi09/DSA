#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
    string str = "abc";
    vector<string> s = {""};

    for (auto ch : str) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            string temp_s = s[i] + ch;
            s.push_back(temp_s); // add current char to existing subsequences
        }
    }

    for (auto st : s) {
        cout << st << " ";
    }
    cout << endl;

    return 0;
}
