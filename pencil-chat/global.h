#ifndef GLOBAL_H
#define GLOBAL_H

// Identifies the kind of HTTP request whose response is being handled.
enum ReqId
{
    ID_GET_VARIFY_CODE = 1001
};

// Describes whether an HTTP request and its response were handled successfully.
enum ErrorCodes
{
    SUCCESS = 0,
    ERR_JSON = 1,
    ERR_NETWORK = 2
};

// Routes a completed HTTP request to the corresponding business module.
enum Modules
{
    REGISTERMOD = 0
};

#endif // GLOBAL_H
