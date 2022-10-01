#include "url.h"

std::map<std::string, std::string> Url::names_mapping;
std::map<std::string, View *> Url::views_mapping;

// add a new url
void Url::add(View *view, std::string url, std::string name)
{
    if (views_mapping.find(url) == views_mapping.end())
    {
        delete Url::views_mapping[url];
    }
    Url::views_mapping[url] = view;
    Url::names_mapping[name] = url;
}

// get url using name
std::string Url::geturlwithname(std::string name)
{
    return names_mapping[name];
}

bool Url::exist(std::string url)
{
    return !(views_mapping.find(url) == views_mapping.end());
}
