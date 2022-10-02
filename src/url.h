#ifndef URL
#define URL

#include "view.h"
#include <map>
typedef Httpresponse(__stdcall *Viewfunc)(Request);

class Url
{

public:
    static std::map<std::string, std::string> names_mapping;
    static std::map<std::string, View *> views_mapping;
    static void add(View *view, std::string url, std::string name = "");
    static void add(Viewfunc function, std::string url, std::string name = "");
    static std::string geturlwithname(std::string name);
    static bool exist(std::string url);
};
#endif