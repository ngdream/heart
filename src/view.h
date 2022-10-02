#ifndef VIEW
#define VIEW

#include "defs.h"
#include "Request.h"
#include "response.h"
class View
{
public:
    virtual Httpresponse def(Request request);


    virtual Httpresponse get(Request request);//this function is called for get request 
    virtual Httpresponse post(Request request);//this function is called for post request 
    virtual Httpresponse put(Request request);//this function is called for put request 
    virtual Httpresponse del(Request request);//this function is called for delete request 
};

#endif
