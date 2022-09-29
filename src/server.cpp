#include "server.h"
#include <map>

class Bridje : public View
{
    Httpresponse get(Request Request)
    {
        return Template::render("index.html");
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
                Httpresponse res;

                if (strncmp(hm->method.ptr, "POST", hm->method.len) == 0)
                {
                    std::cout << "POST DETECTED" << std::endl;
                    res = i->second->post(request);
                }
                else if (strncmp(hm->method.ptr, "GET", hm->method.len) == 0)
                {
                    res = i->second->get(request);
                }
                else if (strncmp(hm->method.ptr, "DELETE", hm->method.len) == 0)
                {
                    res = i->second->del(request);
                }
                else if (strncmp(hm->method.ptr, "PUT", hm->method.len) == 0)
                {
                    res = i->second->put(request);
                }

                mg_printf(c, "HTTP/1.1 200 OK\r\nContent-Length: %d\r\nContent-Type: %s\r\n\r\n%s\n",
                          res.content().size(), res.contenttype().c_str(), res.content().c_str());
            }
        }
        cl = mg_http_get_header(&tmp, "Content-Length");
        if (cl == NULL)
            cl = &unknown;
    }
}

//
void Server::run(std::string url)
{
    setup();
    struct mg_mgr mgr;
    Url::add(new Bridje, "/", "index");

    mg_mgr_init(&mgr);
    mg_http_listen(&mgr, url.c_str(), Server::start_mg_server, NULL);
    for (;;)
        mg_mgr_poll(&mgr, 50);
    mg_mgr_free(&mgr);
}
