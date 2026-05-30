#include "./UrlShortenerService.h"
#include "./storages/DBStorage.h"
#include "./Base62Encoder/Base62Encoder.h"
#include "./factories/StorageFactoryCreation.h"

int main()
{
    Base62Encoder *encoder = new Base62Encoder();
    IStorage *storage = StorageFactoryCreation::createStorage("DB");
    UrlShortenerService urlShortener(encoder, storage);

    std::string longUrl1 = "https://www.example.com/some/long/url";
    std::string longUrl2 = "https://www.anotherexample.com/another/long/url";

    std::string shortUrl1 = urlShortener.shortenUrl(longUrl1);
    std::string shortUrl2 = urlShortener.shortenUrl(longUrl2);

    std::cout << "Long URL: " << longUrl1 << " -> Short URL: " << shortUrl1 << std::endl;
    std::cout << "Long URL: " << longUrl2 << " -> Short URL: " << shortUrl2 << std::endl;

    std::cout << "Retrieving Long URL from Short URL: " << shortUrl1 << " -> Long URL: " << urlShortener.getLongUrl(shortUrl1) << std::endl;
    std::cout << "Retrieving Long URL from Short URL: " << shortUrl2 << " -> Long URL: " << urlShortener.getLongUrl(shortUrl2) << std::endl;

    return 0;
}