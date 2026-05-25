#include "./FixedSizeWindow.h"

void FixedSizeWindow::addRequest(int userId, int timestamp, std::string endpoint)
{
    // Remove expired requests
    while (!userRequests[userId].empty() && userRequests[userId].front() <= timestamp - windowSize)
    {
        userRequests[userId].pop();
    }

    // Add new request if window is not full
    if (userRequests[userId].size() < capacity)
    {
        userRequests[userId].push(timestamp);
    }
}

bool FixedSizeWindow::isRateLimited(int userId, int timestamp, std::string endpoint)
{
    // Remove expired requests
    while (!userRequests[userId].empty() && userRequests[userId].front() <= timestamp - windowSize)
    {
        userRequests[userId].pop();
    }

    // Check if window is full
    return userRequests[userId].size() >= capacity;
}