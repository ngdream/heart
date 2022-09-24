#ifndef VIEW
#define VIEW

#include "defs.h"
#include "Request.h"
#include "response.h"
class View
{
public:
    virtual Httpresponse get(Request request);
    virtual Httpresponse post(Request request);
};

#endif