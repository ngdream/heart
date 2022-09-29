#include "setup.h"
#include "view.h"
#include "server.h"
#include <fstream>
using namespace rapidjson;
std::vector<std::string> Template::__templates_dirs;
void setup()
{
    static bool is_set = false;
    if (!is_set)
    {
        FILE *fp = fopen("config.json", "rb");
        if (fp == NULL)
        {
            std::fstream file;
            file.open("config.json", std::ios::out | std::ios::binary);

            std::string json = "[\n"
                               "{\n"
                               "\"debug\":\"True\",\n"
                               "\n"
                               "\"templates\":{\n"
                               "\"dirs\":[\"template\"]\n"
                               "}\n"
                               "}\n"
                               "\n"
                               "]";

            file.write(json.data(), json.size());

            file.close();
            fp = fopen("config.json", "rb");
        }
        if (fp == NULL)
            std ::cout << "cannot load config file";
        else
        {
            char readBuffer[65536];
            FileReadStream is(fp, readBuffer, sizeof(readBuffer));
            Document d;
            d.ParseStream(is);
        }

        if (Template::__templates_dirs.empty())
        {
            Template::add("templates");
        }

        is_set = true;
    }
}
