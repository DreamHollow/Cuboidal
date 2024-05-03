#ifndef GLOBAL_VARIABLES_H_INCLUDED
#define GLOBAL_VARIABLES_H_INCLUDED 1
#include "Config.h"
#include "debugger/Debugger.hpp"

// config should only be modified on initialization or while active in menu

static const bool debug = true;
//static const char db_string[8] = "DEBUG: "; // deprecated
static Config config;

#endif
