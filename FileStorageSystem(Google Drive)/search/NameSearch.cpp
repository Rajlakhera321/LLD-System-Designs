#include "./NameSearch.h"

std::vector<std::string> NameSearch::search(const std::string &query)
{
    std::vector<std::string> results;

    std::string content = storage->readFile(query);
    if (!content.empty())
    {
        results.push_back(query);
    }

    return results;
}