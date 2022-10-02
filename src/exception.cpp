#include "exception.h"

std::string Httpexception::msg;

Httpexception::Httpexception(std::string msg)
{
    Httpexception::msg = msg;
}
const char *Http404::what()
{
    return "template not found";
}

const char *Http403::what()
{
    return "access denied";
}