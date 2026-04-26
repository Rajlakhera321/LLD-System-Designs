#include "./LFU.h"

void LFU::keyAccessed(Node *node)
{
    int freq = nodeFreq[node];
    freqMap[freq].remove(node);
    if (freqMap[freq].empty() && freq == minFreq)
        minFreq++;

    nodeFreq[node] = freq + 1;
    freqMap[freq + 1].push_back(node);
}

void LFU::addNode(Node *node)
{
    nodeFreq[node] = 1;
    freqMap[1].push_back(node);
    minFreq = 1;
}

Node *LFU::evict()
{
    Node *node = freqMap[minFreq].front();
    freqMap[minFreq].pop_front();
    nodeFreq.erase(node);
    return node;
}