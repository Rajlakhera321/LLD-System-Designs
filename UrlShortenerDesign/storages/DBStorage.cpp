#include "./DBStorage.h"

void DBStorage::saveUrlMapping(std::string shortUrl, std::string originalUrl)
{
    urlMapping[shortUrl] = originalUrl;
}

std::string DBStorage::getOriginalUrl(std::string shortUrl)
{
    if (urlMapping.find(shortUrl) != urlMapping.end())
    {
        return urlMapping[shortUrl];
    }
    return ""; // Return empty string if short URL not found
}