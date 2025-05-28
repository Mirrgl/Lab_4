#include <iostream>
#include <vector>
#include <map>

using namespace std;

char methodBord(vector<vector<char>> chains) {
    map<char,int> scores;

    for(int i = 0; i < chains[0].size(); i++) {
        scores[chains[0][i]] = 0;
    }

    for (auto& chain : chains) {
        for (int i = 0; i < chain.size(); i++) {
            scores[chain[i]] += chain.size() - 1 - i;
        }
    }

    int max = 0;
    char max_key = ' ';
    for (auto& [a, b] : scores) {
        if (b > max) {
            max_key = a;
            max = b;
        }
    }

    return max_key;
}

char methodCondorse(vector<vector<char>> chains) {
    map<char,int> scores;

    for(int i = 0; i < chains[0].size(); i++) {
        scores[chains[0][i]] = 0;
    }

    for (auto& chain : chains) {
        scores[chain[0]]++;
    }

    int max = 0;
    char max_key = ' ';
    for (auto& [a, b] : scores) {
        if (b > max) {
            max_key = a;
            max = b;
        }
    }

    return max_key;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<char>> chains;
    chains.resize(k);
    for (int i = 0; i < k; i++) {
        chains[i].resize(n);
    }

    for (int i = 0; i < k; i++) {
        cout << "Цепь для " << i+1 << " избирателя:" << endl;
        for (int j = 0; j < n; j++) {
            char letter;
            cin >> letter;
            chains[i][j] = letter;
        }
        cout << endl;
    }

    cout << "По методу Борда выигрывает кандидат " << methodBord(chains) << endl;
    cout << "По методу Кондорсе выигрывает кандидат " << methodCondorse(chains) << endl;

    return 0;
}