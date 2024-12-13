#ifndef TASK2_RULEPARSER_H
#define TASK2_RULEPARSER_H

#include <string>
#include <set>

enum {
    INVALID_RULE_FORMAT,
    RULES_PARSED
};

class RuleParser {
public:
    static short parseRules(const std::string& rules, std::set<int>& birth, std::set<int>& survival);
};

#endif //TASK2_RULEPARSER_H
