#include "./UrlShortenerService.h"

std::string UrlShortenerService::shortenUrl(const std::string &longUrl)
{
    // Check if the long URL has already been shortened
    if (reverseUrlMap.find(longUrl) != reverseUrlMap.end())
    {
        return reverseUrlMap[longUrl];
    }

    // Generate a unique ID and encode it to get the short URL
    int id = IDGenerator::generateId();
    std::string shortUrl = encoder->encode(id);

    // Store the mapping between short URL and long URL
    urlMap[shortUrl] = longUrl;
    reverseUrlMap[longUrl] = shortUrl;

    return shortUrl;
}

std::string UrlShortenerService::getLongUrl(const std::string &shortUrl)
{
    // Check if the short URL exists in the map
    if (urlMap.find(shortUrl) != urlMap.end())
    {
        return urlMap[shortUrl];
    }
    return ""; // Return an empty string if the short URL does not exist
}