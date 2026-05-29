#pragma once
#include "bits/stdc++.h"
#include "../interfaces/IEncoder.h"

class Base62Encoder : public IEncoder
{
private:
    const std::string base62Chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

public:
    std::string encode(long long id) override {}
};