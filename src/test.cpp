#include "heart.h"

class home : public View
{
    Httpresponse get(Request request)
    {
        throw Http404();
    }
};

class doc : public View
{
};

int main(int argc, char const *argv[])
{
    Url::add(new home, "", "");
    Server::run();
    return 0;
}
