#include "defs.h"
#ifndef EXCEPTION
#define EXCEPTION
class Httpexception : public std::exception
{
private:
    static std::string msg;

public:
    Httpexception(std::string msg = "page not found");
};
class Http404 : public Httpexception
{

    const char *what();
};
class Http403 : public Httpexception
{
    const char *what();
};

#define error(x) throw Http##x()

#endif