#ifndef SERVER
#define SERVER
#include "mongoose.h"
#include "defs.h"
#include "response.h"
#include "setup.h"

#include "view.h"
#include "url.h"
class Server
{
public:
    static std::string url;
    static void run(std::string url = "http://localhost:8000");
    static std::string geturl();
    static std::string getconfig();
    static bool loadconfigfrom();

private:
    static void start_mg_server(struct mg_connection *c, int ev, void *ev_data, void *fn_data);
};

#endif