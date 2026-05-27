#include "./UrlModel.h"

UrlModel::UrlModel(std::string originalUrl, std::string shortUrl)
{
    this->id = IDGenerator::generateId();
    this->originalUrl = originalUrl;
    this->shortUrl = shortUrl;
    this->expiryTime = 0;           // Set default expiry time
    this->createdAt = std::time(0); // Set created time to current time
    this->clicks = 0;               // Initialize clicks to 0
}

std::string UrlModel::getOriginalUrl()
{
    return this->originalUrl;
}

std::string UrlModel::getShortUrl()
{
    return this->shortUrl;
}

long long UrlModel::getExpiryTime()
{
    return this->expiryTime;
}

long long UrlModel::getCreatedAt()
{
    return this->createdAt;
}

long long UrlModel::getClicks()
{
    return this->clicks;
}

void UrlModel::incrementClicks()
{
    this->clicks++;
}