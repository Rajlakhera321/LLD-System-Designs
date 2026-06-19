#include "./UploadService.h"

UploadService::UploadService(std::unique_ptr<IStorage> stor) : storage(std::move(stor)) {}

void UploadService::upload(const std::string &path, const std::string &content)
{
    storage->saveFile(path, content);
}