#include "view.h"

Httpresponse View::def(Request request)
{
    return "its cool";
}

Httpresponse View::get(Request request)
{
    return def(request);
}

Httpresponse View::post(Request request)
{
    return def(request);
}

Httpresponse View::del(Request request)
{
    return def(request);
}

Httpresponse View::put(Request request)
{
    return def(request);
}