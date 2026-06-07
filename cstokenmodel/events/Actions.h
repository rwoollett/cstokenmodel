
#ifndef EVENT_ACTIONS_H
#define EVENT_ACTIONS_H

#include "Subjects.h"
#include <string>
#include <chrono>

namespace CSTokenEvents
{
  // Define a struct to encapsulate Connect/Disconnect ClientCS
  struct ClientConnectEvent
  {
    Subject subject{Subject::ClientCSConnected};
    std::string sourceIp;
    uint64_t seqNo{};
    std::string processId;
    std::string connectedAt;
    std::chrono::system_clock::time_point tpConnectedAt{};
    ClientConnectEvent() = default;
  };

  struct ClientDisconnectEvent
  {
    Subject subject{Subject::ClientCSDisconnected};
    std::string sourceIp;
    uint64_t seqNo{};
    std::string disconnectedAt;
    std::chrono::system_clock::time_point tpDisconnectedAt{};
    ClientDisconnectEvent() = default;
  };

  struct CSTokenRequestEvent
  {
    Subject subject{Subject::CSTokenRequest};
    std::string sourceIp;
    uint64_t seqNo{};
    std::string originalIp;
    std::string parentIp;
    std::string requestedAt;
    bool relayed = false;
    std::chrono::system_clock::time_point tpRequestedAt{};
    CSTokenRequestEvent() = default;
  };

  struct CSTokenAcquireEvent
  {
    Subject subject{Subject::CSTokenAcquire};
    std::string ip;
    uint64_t seqNo{};
    std::string sourceIp;
    std::string acquiredAt;
    std::chrono::system_clock::time_point tpAcquiredAt{};
    CSTokenAcquireEvent() = default;
  };

  struct CSProcessedServiceEvent
  {
    Subject subject{Subject::CSProcessedService};
    std::string ip;
    uint64_t seqNo{};
    std::string serviceMessage;
    std::string processedAt;
    std::chrono::system_clock::time_point tpProcessedAt{};
    CSProcessedServiceEvent() = default;
  };

}
#endif // EVENT_ACTIONS_H
