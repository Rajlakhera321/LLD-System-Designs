#include "./UrlShortenerService.h"

std::string UrlShortenerService::shortenUrl(const std::string &longUrl)
{
    // Check if the long URL has already been shortened
    std::string existingShortUrl =
        dbStorage->getShortUrl(longUrl);

    if (!existingShortUrl.empty())
    {
        return domain + existingShortUrl;
    }

    // Generate a unique ID and encode it to get the short URL
    int id = IDGenerator::generateId();
    std::string shortUrl = encoder->encode(id);

    // Store the mapping between short URL and long URL
    dbStorage->saveUrlMapping(shortUrl, longUrl);
    redisStorage->saveUrlMapping(shortUrl, longUrl);

    return domain + shortUrl;
}

std::string UrlShortenerService::getLongUrl(const std::string &shortUrl)
{
    // Check if the short URL exists in the map
    std::string shortCode = shortUrl;

    if (shortUrl.find(domain) == 0)
    {
        shortCode = shortUrl.substr(domain.length());
    }

    // Check if the short URL exists in the database
    std::string longUrl = redisStorage->getOriginalUrl(shortCode);

    if (!longUrl.empty())
    {
        return longUrl;
    }

    longUrl = dbStorage->getOriginalUrl(shortCode);

    if (!longUrl.empty())
    {
        redisStorage->saveUrlMapping(
            shortCode,
            longUrl);
        return longUrl;
    }

    return "";
}