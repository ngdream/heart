#include "url.h"

std::map<std::string, std::string> Url::names_mapping;
std::map<std::string, View *> Url::views_mapping;

// add a new url
void Url::add(View *view, std::string url, std::string name)
{
    Url::views_mapping[url] = view;
    Url::names_mapping[name] = url;
}

// get url using name
std::string Url::geturlwithname(std::string name)
{
    return names_mapping[name];
}
