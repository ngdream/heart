#include "response.h"

Httpresponse::Httpresponse(std::string content, std::string type) : m_type(type),
                                                                    m_content(content)
{
}

Httpresponse::Httpresponse(std::string content) : Httpresponse(content, "text/html")
{
}

Httpresponse::Httpresponse(const char *content) : Httpresponse(std::string(content))
{
}

Httpresponse::Httpresponse(bool value) : Httpresponse(std::to_string(true))
{
}

Httpresponse::Httpresponse(int value) : Httpresponse(std::to_string(value))
{
}

std::string Httpresponse::contenttype()
{
    return m_type;
}

std::string Httpresponse::content()
{

    return m_content;
}
