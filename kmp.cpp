#include <iostream>
using namespace std;

void get_next(string T, int next[]) {
    int i = 0, j = -1;
    next[i] = -1;
    while(i < T.size()) {
        if(j == -1 || T[i] == T[j]) {
            i++; j++;

            if(T[i] == T[j]) next[i] = next[j];
            else             next[i] = j;
        }
        else {
            j = next[j];
        }
    }
}

int kmp(string S, string T, int next[]) {
    int i = 0, j = 0;
    while(j == -1 || (i < S.size()) && (j < T.size())) {
        if(j == -1 || S[i] == T[j]){ i++; j++;}
        else j = next[j];
        cout << "j" << j << endl;
    }

    if(j >= T.size()) 
        return i - T.size();
    else return -1; 
}

int main() {
    string S = "asdaabacabcabsds";
    string s = "abacabcab";
    int next[s.size()];
    get_next(s, next);
    for(auto a:next) cout << "next "<< a << endl;
    int k = kmp(S, s, next);
    cout << k << endl;
    return 0;
}