#ifndef TASK2_UNIVERSECHARACTERISTICSPARSER_H
#define TASK2_UNIVERSECHARACTERISTICSPARSER_H

#include <sstream>
#include <vector>
#include <string>
#include <set>

#include "UniverseConfig.h"
#include "Reader.h"

class UniverseCharacteristicsParser {
public:
    UniverseConfig parse(std::string &filePath);
};

#endif //TASK2_UNIVERSECHARACTERISTICSPARSER_H
