#pragma once
#include "bits/stdc++.h"
#include "./interfaces/IEncoder.h"

class UrlShortenerService
{
private:
    IEncoder *encoder;
    unordered_map<std::string, std::string> urlMap;        // shortUrl -> longUrl
    unordered_map<std::string, std::string> reverseUrlMap; // longUrl -> shortUrl

public:
    UrlShortenerService(IEncoder *encoder) : encoder(encoder) {}

    std::string shortenUrl(const std::string &longUrl) {}

    std::string getLongUrl(const std::string &shortUrl) {}
};