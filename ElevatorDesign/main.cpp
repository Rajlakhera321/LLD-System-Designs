#include <iostream>
#include "services/ElevatorService.h"

int main()
{
    ElevatorService service(3, SchedulerType::LOOK);

    service.handleExternal(ExternalRequest(5, Direction::UP));
    service.handleExternal(ExternalRequest(2, Direction::DOWN));

    for (int i = 0; i < 5; i++)
        service.step();

    return 0;
}