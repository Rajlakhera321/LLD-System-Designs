#include "./interfaces/IStorage.h"
#include "./services/DriveService.h"

int main()
{
    DriveService driveService;
    driveService.upload("/path/to/file", "Hello, World!");
    driveService.download("/path/to/file");
    return 0;
}