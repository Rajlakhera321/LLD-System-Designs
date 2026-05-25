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

std::string Request::getEndpoint() const
{
    return endpoint;
}