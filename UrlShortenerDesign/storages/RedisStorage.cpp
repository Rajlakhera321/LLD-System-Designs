#include "./RedisStorage.h"

void RedisStorage::saveUrlMapping(std::string shortUrl, std::string originalUrl)
{
    urlMapping[shortUrl] = originalUrl;
}

std::string RedisStorage::getOriginalUrl(std::string shortUrl)
{
    if (urlMapping.find(shortUrl) != urlMapping.end())
    {
        return urlMapping[shortUrl];
    }
    return ""; // Return empty string if short URL not found
}