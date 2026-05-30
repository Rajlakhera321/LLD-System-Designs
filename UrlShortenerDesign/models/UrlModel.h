#pragma once
#include "bits/stdc++.h"
#include "./IDGenerator.h"

class UrlModel
{
private:
    int id;
    std::string originalUrl;
    std::string shortUrl;
    long long expiryTime;
    long long createdAt;
    long long clicks;

private:
    UrlModel(std::string originalUrl, std::string shortUrl);

    std::string getOriginalUrl();

    std::string getShortUrl();

    long long getExpiryTime();

    long long getCreatedAt();

    long long getClicks();

    void incrementClicks();
};