#include "./Request.h"

int Request::getUserId() const
{
    return userId;
}

int Request::getTimestamp() const
{
    return timestamp;
}

int Request::getRequestCount() const
{
    return requestCount;
}

void Request::incrementRequestCount()
{
    requestCount++;
}

string Request::getEndpoint() const
{
    return endpoint;
}