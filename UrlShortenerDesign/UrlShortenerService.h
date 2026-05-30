#pragma once
#include "bits/stdc++.h"
#include "./interfaces/IEncoder.h"
#include "./interfaces/IStorage.h"
#include "./models/IDGenerator.h"

class UrlShortenerService
{
private:
    IEncoder *encoder;
    IStorage *storage;
    std::unordered_map<std::string, std::string> urlMap; // shortUrl -> longUrl
    std::unordered_map<std::string, std::string> reverseUrlMap;
    std::string domain = "https://tinyurl.com/"; // longUrl -> shortUrl

public:
    UrlShortenerService(IEncoder *encoder, IStorage *storage) : encoder(encoder), storage(storage) {}

    std::string shortenUrl(const std::string &longUrl);

    std::string getLongUrl(const std::string &shortUrl);
};