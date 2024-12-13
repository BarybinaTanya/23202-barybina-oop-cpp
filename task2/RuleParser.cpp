#include "RuleParser.h"

short RuleParser::parseRules(const std::string& rules, std::set<int>& birth, std::set<int>& survival) {
    if (rules.substr(0, 3) != "#R " || rules[3] != 'B') {
        return INVALID_RULE_FORMAT;
    }
    size_t i = 4;
    while (isdigit(rules[i])) {
        birth.insert(rules[i] - '0');
        i++;
    }
    if (rules[i++] != '/' || rules[i++] != 'S') {
        return INVALID_RULE_FORMAT;
    }
    while (isdigit(rules[i])) {
        survival.insert(rules[i] - '0');
        i++;
    }
    return RULES_PARSED;
}