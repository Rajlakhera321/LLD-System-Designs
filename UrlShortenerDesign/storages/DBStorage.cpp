#include "./DBStorage.h"

void DBStorage::saveUrlMapping(std::string shortUrl, std::string originalUrl)
{
    shortToLongMapping[shortUrl] = originalUrl;
    longToShortMapping[originalUrl] = shortUrl;
}

std::string DBStorage::getOriginalUrl(std::string shortUrl)
{
    if (shortToLongMapping.find(shortUrl) != shortToLongMapping.end())
    {
        return shortToLongMapping[shortUrl];
    }
    return ""; // Return empty string if short URL not found
}

std::string DBStorage::getShortUrl(std::string longUrl)
{
    if (longToShortMapping.find(longUrl) != longToShortMapping.end())
    {
        return longToShortMapping[longUrl];
    }
    return ""; // Return empty string if long URL not found
}