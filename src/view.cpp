#include "view.h"
Httpresponse View::get(Request request)
{
    return "get request handler";
}

Httpresponse View::post(Request request)
{
    return get(request);
}

Httpresponse View::del(Request request)
{
    return get(request);
}

Httpresponse View::put(Request request)
{
    return get(request);
}