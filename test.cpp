#include "server.h"
#include "view.h"

class Home : public View
{
    Httpresponse get(Request request)
    {
        return Httpresponse();
    }
};

int main(int argc, char const *argv[])
{
    Url::add(new Home, "/jano", "bise");

    Server::run();

    return 0;
}
