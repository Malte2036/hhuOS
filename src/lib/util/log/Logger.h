//
// Created by malte on 05.12.22.
//

#ifndef HHUOS_LOGGER_H
#define HHUOS_LOGGER_H

#include "lib/util/memory/String.h"

class Logger {
public:
    static void logMessage(const Util::Memory::String& message);
};


#endif //HHUOS_LOGGER_H
