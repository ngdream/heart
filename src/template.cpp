#include "template.h"
#include "setup.h"
#include <fstream>

bool Template::add(std::string path)
{
    Template::__templates_dirs.push_back(path);
    return true;
}

Httpresponse Template::render(std::string path)
{
    for (auto c = Template::__templates_dirs.begin(); c < Template::__templates_dirs.end(); c++)
    {

        char *buf;
        std::fstream t(std::string(c->data()) + "/" + path, std::ios::in | std::ios::binary | std::ios::ate);
        if (t.is_open())
        {
            int length = t.tellg();
            t.seekg(0, std::ios::beg);
            buf = new char[length + 1];
            t.read(buf, length);
            return renderstring(buf);
        }
    }
    throw Http404();
    return Httpresponse("cannot load templates");
}

Httpresponse Template::renderstring(std::string buffer)
{
    return Httpresponse(buffer);
}