#ifndef TEMPLATE
#define TEMPLATE

#include <map>
#include <vector>
#include "defs.h"
#include "response.h"

class Template
{
private:
    static std::vector<std::string> __templates_dirs;

public:
    static bool add(std::string path);
    static Httpresponse render(std::string path);
    friend void setup();
};

#endif