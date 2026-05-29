#include "./Base62Encoder.h"

std::string Base62Encoder::encode(long long id)
{
    std::string shortUrl;
    while (id > 0)
    {
        int remainder = id % 62;
        shortUrl = base62Chars[remainder] + shortUrl;
        id /= 62;
    }
    return shortUrl;
}