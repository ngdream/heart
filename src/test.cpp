#include "heart.h"

class Test : public View
{
    Httpresponse get(Request request)
    {
        throw Http404();
    }
};

int main(int argc, char const *argv[])
{
    Url::add(new Test, "/yo", "yo");
    Server::run();
    return 0;
}