#include "server.h"
#include <map>
std::string index_html = "<html lang=\"en\">\n"
                         "<head>\n"
                         "    <meta charset=\"UTF-8\">\n"
                         "    <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\n"
                         "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n"
                         "    <title>heart index</title>\n"
                         "</head>\n"
                         "<body>\n"
                         "    <style>\n"
                         "\n"
                         "    body{ \n"
                         "        margin: 0;\n"
                         "        box-sizing: border-box;\n"
                         "    }\n"
                         "  header\n"
                         "   {\n"
                         "     padding: 18px 20px;\n"
                         "     background-color: #111;\n"
                         "     box-shadow: 0px 1px 5px 2px #888;\n"
                         "    font-family:system-ui, -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif\n"
                         "   }\n"
                         "\n"
                         "   #banner-name \n"
                         "   {\n"
                         "    font-size: 7em;\n"
                         "    font-weight: bold;\n"
                         "    font-family:'Franklin Gothic Medium', 'Arial Narrow', Arial, sans-serif;\n"
                         "    background: -webkit-linear-gradient(rgb(171, 3, 95),rgb(250, 2, 134));\n"
                         "    -webkit-background-clip: text;\n"
                         "    -webkit-text-fill-color: transparent;\n"
                         "    filter: drop-shadow(0px 10px 5px rgba(255, 12, 146, 0.4))\n"
                         "   }\n"
                         "   #banner\n"
                         "   {\n"
                         "    display: flex;\n"
                         "    padding: 100px;\n"
                         "    align-items: center;\n"
                         "    justify-content: center;\n"
                         "    flex-direction: column;\n"
                         "   }\n"
                         "\n"
                         "   .presentation{\n"
                         " background-color: #111;\n"
                         " height: 400px;\n"
                         " box-shadow: 0px 0px 5px 2px #888;\n"
                         " display: flex;\n"
                         " align-items: center;\n"
                         " justify-content: center;\n"
                         " color: white;\n"
                         "\n"
                         "   }\n"
                         "   #k1\n"
                         "{\n"
                         "    font-size:5em\n"
                         "}\n"
                         "\n"
                         "h2{\n"
                         "font-size: 5em;\n"
                         "\n"
                         "}\n"
                         "li{\n"
                         "    font-size: 3em;\n"
                         "}\n"
                         "\n"
                         "    header a\n"
                         "   {\n"
                         "    color: white;\n"
                         "    text-decoration: none;\n"
                         "    font-size: 1.3em;\n"
                         "   }\n"
                         "   .button\n"
                         "   {\n"
                         "    margin-top: 20px;\n"
                         "    border: #111 1px solid;\n"
                         "    padding: 20px 30px;\n"
                         "    text-decoration: none;\n"
                         "    color: rgb(0, 0, 0);\n"
                         "    font-size:1.5em;\n"
                         "    position:relative;\n"
                         "   }\n"
                         "\n"
                         "   .button:hover div\n"
                         "   {\n"
                         "    background-color: black;\n"
                         "    height: 100%;\n"
                         "    width: 100%;\n"
                         "    position: absolute;\n"
                         "    top:0;\n"
                         "    right: 0;\n"
                         "   }\n"
                         "\n"
                         "   .button:hover\n"
                         "   {\n"
                         "    color: white!important;\n"
                         "   }\n"
                         "    </style>\n"
                         "    <header>\n"
                         "            <a href=\"\">&hearts; heart</a>\n"
                         "    </header>\n"
                         "    <div id=\"banner\">\n"
                         "\n"
                         "        <div>\n"
                         "            <span id=\"banner-name\">HEART &hearts;</span>\n"
                         "\n"
                         "        </div>\n"
                         "        \n"
                         "            <span id=\"k1\">for who love c++</span>\n"
                         "\n"
                         "            <a href=\"\" class=\"button\">\n"
                         "                <div></div>\n"
                         "                 <span style=\"position: relative;\">Contribute on github</span>\n"
                         "            </a>\n"
                         "        \n"
                         "    </div>\n"
                         "\n"
                         "    <div class=\"presentation\">\n"
                         "        <div style=\"padding:40px\">\n"
                         "                   <h2>\n"
                         "            Why using heart\n"
                         "        </h2> \n"
                         "        </div>\n"
                         "\n"
                         "        <div>\n"
                         "            <ul>\n"
                         "                <li>easy to use</li>\n"
                         "                <li>open source</li>\n"
                         "                <li>highly maintained</li>\n"
                         "                <li>fast</li>\n"
                         "            </ul>\n"
                         "        </div>\n"
                         "\n"
                         "    </div>\n"
                         "\n"
                         "</body>\n"
                         "</html>\n"
                         "";
class Bridje : public View
{
    Httpresponse get(Request Request)
    {
        return Template::renderstring(index_html);
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
                try
                {
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
                catch (const std::exception &e)
                {

                    mg_printf(c, "HTTP/1.1 400 OK\r\nContent-Length: %d\r\nContent-Type: %s\r\n\r\n%s\n",
                              res.content().size(), res.contenttype().c_str(), res.content().c_str());
                }
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
    if (!Url::exist("/"))
    {
        Url::add(new Bridje, "/", "index");
    }

    mg_mgr_init(&mgr);
    mg_http_listen(&mgr, url.c_str(), Server::start_mg_server, NULL);
    for (;;)
        mg_mgr_poll(&mgr, 50);
    mg_mgr_free(&mgr);
}
