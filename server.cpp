#include "server.h"
#include <map>

class Bridje : public View
{
    Httpresponse get(Request r)
    {
        return "my name is madara uchiwa";
    }
};

void Server::start_mg_server(struct mg_connection *c, int ev, void *ev_data, void *fn_data)
{
    if (ev == MG_EV_HTTP_MSG)
    {
        struct mg_http_message *hm = (struct mg_http_message *)ev_data, tmp = {0};

        struct mg_str unknown = mg_str_n("?", 1), *cl;
        std::map<std::string, View *>::iterator i;
        for (i = Url::views_mapping.begin(); i != Url::views_mapping.end(); i++)
        {
            if (mg_http_match_uri(hm, i->first.c_str()))
            {

                Request request;
                Httpresponse res = i->second->get(request);
                std::cout << i->first;
                mg_printf(c, "GET HTTP/1.1 200 OK\r\nContent-Length: %d\r\nContent-Type: %s\r\n\r\n%s\n",
                          res.content().size(), res.contenttype().c_str(), res.content().c_str());
            }
        }
        cl = mg_http_get_header(&tmp, "Content-Length");
        if (cl == NULL)
            cl = &unknown;

        /*MG_INFO(("%.*s %.*s %.*s %.*s", (int)hm->method.len, hm->method.ptr,
                 (int)hm->uri.len, hm->uri.ptr, (int)tmp.uri.len, tmp.uri.ptr,
                 (int)cl->len, cl->ptr));*/
    }
}

//
void Server::run(std::string url)
{
    struct mg_mgr mgr;
    Url::add(new Bridje, "/", "index");
    mg_mgr_init(&mgr);
    mg_http_listen(&mgr, url.c_str(), Server::start_mg_server, NULL);
    for (;;)
        mg_mgr_poll(&mgr, 50);
    mg_mgr_free(&mgr);
}
