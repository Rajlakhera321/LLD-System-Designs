#include "./IDGenerator.h"

int IDGenerator::id = 0;

int IDGenerator::generateId()
{
    return ++id;
}