#include "./UploadService.h"

UploadService::UploadService(IStorage *stor) : storage(stor) {}

void UploadService::upload(const std::string &path, const std::string &content)
{
    storage->writeFile(path, content);
}