#ifndef TASK2_RULEPARSER_H
#define TASK2_RULEPARSER_H

#include <string>
#include <set>

class RuleParser {
public:
    static short parseRules(const std::string& rules, std::set<int>& birth, std::set<int>& survival);
};

#endif //TASK2_RULEPARSER_H
