#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

bool alwaysCoop(int32_t& round_number, vector<bool>& self_choices, vector<bool>& enemy_choices) {
    return 1;
}

bool mirror(int32_t& round_number, vector<bool>& self_choices, vector<bool>& enemy_choices) {
    if(round_number == 0) {return 1;}
    return (enemy_choices[round_number-1]);
}

bool reverse(int32_t& round_number, vector<bool>& self_choices, vector<bool>& enemy_choices) {
    if(round_number == 0) {return 1;}
    return ((self_choices[round_number-1]+1)%2);
}

void scoreCount(pair<int,int>& scores, bool A, bool B) {
    if (A == 0 && B == 0) {
        scores.first+=4;
        scores.second+=4;
    }
    else if (A == 1 && B == 1) {
        scores.first+=24;
        scores.second+=24;
    }
    else if (A == 1 && B == 0) {
        scores.first+=0;
        scores.second+=20;
    }
    else if (A == 0 && B == 1) {
        scores.first+=20;
        scores.second+=0;
    }
}

int main() {
    mt19937_64 engine;
    engine.seed(time(nullptr));
    int32_t round_number = -1;
    vector<bool> AChoices;
    vector<bool> BChoices;
    pair<int,int> scores;
    uniform_int_distribution<> distribution(100,200);
    int max_round = distribution(engine);

    cout << "Всегда сотрудничество" << endl;
    while (round_number < max_round) {
        round_number++;
        AChoices.push_back(alwaysCoop(round_number, AChoices, BChoices));
        BChoices.push_back(alwaysCoop(round_number, BChoices, AChoices));
        scoreCount(scores, AChoices[round_number], BChoices[round_number]);
    }
    cout << "A: " << scores.first << endl << "B: " << scores.second << endl;

    round_number = -1;
    AChoices = {};
    BChoices = {};
    scores = {};

    cout << "Зерклальное против обратного" << endl;
    while (round_number < max_round) {
        round_number++;
        AChoices.push_back(mirror(round_number, AChoices, BChoices));
        BChoices.push_back(reverse(round_number, BChoices, AChoices));
        scoreCount(scores, AChoices[round_number], BChoices[round_number]);
    }
    cout << "A: " << scores.first << endl << "B: " << scores.second << endl;

    cout << "Сотрудничество против обратного" << endl;
    while (round_number < max_round) {
        round_number++;
        AChoices.push_back(alwaysCoop(round_number, AChoices, BChoices));
        BChoices.push_back(reverse(round_number, BChoices, AChoices));
        scoreCount(scores, AChoices[round_number], BChoices[round_number]);
    }
    cout << "A: " << scores.first << endl << "B: " << scores.second << endl;
    
    return 0;
}