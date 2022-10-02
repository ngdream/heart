#ifndef RESPONSE
#define RESPONSE
#include "defs.h"

class Httpresponse
{

    std::string m_type;
    std::string m_content;

public:
    Httpresponse(std::string content, std::string type);
    Httpresponse(std::string content = "thanks for using bridje");
    Httpresponse(int content);
    Httpresponse(bool content);
    Httpresponse(const char *content);

    Httpresponse(const char *content);

    std::string contenttype();
    std::string content();
};
#endif