#include "StateCounter.h"

using namespace std;

pair<vector<int>, vector<int>> processRules(string &rules) {
    if (rules[0] != '#' || rules[1] != 'R' || rules[2] != ' ' ||
    rules[3] != 'B') {
        cerr << "Error: rule format is invalid!";
        return {{-1,-1}, {-1,-1}};
    }
    pair<vector<int>, vector<int>> res = {{-1, -1},{-1, -1}};
    int iter = 4;
    while (isdigit(rules[iter])) {
        res.first.push_back(rules[iter] - '0');
        iter++;
    }
    if (rules[iter] != '/' || rules[iter + 1] != 'S' || iter == 4) {
        cerr << "Error: rule format is invalid!";
        return {{-1,-1}, {-1,-1}};
    }
    iter += 2;
    int itBeforeSecond = iter;
    while (isdigit(rules[iter])) {
        res.second.push_back(rules[iter] - '0');
        iter++;
    }
    if (iter == itBeforeSecond) {
        cerr << "Error: rule format is invalid!";
        return {{-1,-1}, {-1,-1}};
    }
    return res;
}

void StateCounter::processGeneration(GameState &field) {

}

