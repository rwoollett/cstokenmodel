#pragma once

#include "Actions.h"
#include "../timestamp.h"
#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

namespace CSTokenEvents
{

  inline void to_json(json &jsonOut, ClientConnectEvent const &value)
  {
    json obj;
    obj["sourceIp"] = value.sourceIp;
    obj["processId"] = value.processId;
    obj["connectedAt"] = CSTokenModel::formatDate(value.tpConnectedAt);
    jsonOut["payload"] = obj;
    if (value.subject != Subject::ClientCSConnected)
    {
      throw std::string("ClientConnectEvent::to_json - Subject should be ClientCSConnected");
    }
    jsonOut["subject"] = SubjectNames.at(value.subject);
  }

  inline void from_json(json const &jsonIn, ClientConnectEvent &value)
  {
    json obj = jsonIn.at("payload");
    std::string subject;
    jsonIn.at("subject").get_to(subject);
    value.subject = SubjectFromNames.at(subject);
    obj.at("sourceIp").get_to(value.sourceIp);
    obj.at("processId").get_to(value.processId);
    obj.at("connectedAt").get_to(value.connectedAt);
    auto tpOptCA = CSTokenModel::parseDate(value.connectedAt);
    if (tpOptCA)
      value.tpConnectedAt = *tpOptCA;
  };

  inline void to_json(json &jsonOut, ClientDisconnectEvent const &value)
  {
    json obj;
    obj["sourceIp"] = value.sourceIp;
    obj["disconnectedAt"] = CSTokenModel::formatDate(value.tpDisconnectedAt);
    jsonOut["payload"] = obj;
    if (value.subject != Subject::ClientCSDisconnected)
    {
      throw std::string("ClientDisconnectEvent::to_jsonn - Subject should be ClientCSDisconnected");
    }
    jsonOut["subject"] = SubjectNames.at(value.subject);
  }

  inline void from_json(json const &jsonIn, ClientDisconnectEvent &value)
  {
    json obj = jsonIn.at("payload");
    std::string subject;
    jsonIn.at("subject").get_to(subject);
    value.subject = SubjectFromNames.at(subject);
    obj.at("sourceIp").get_to(value.sourceIp);
    obj.at("disconnectedAt").get_to(value.disconnectedAt);
    auto tpOptCA = CSTokenModel::parseDate(value.disconnectedAt);
    if (tpOptCA)
      value.tpDisconnectedAt = *tpOptCA;
  };

  inline void to_json(json &jsonOut, CSTokenRequestEvent const &value)
  {
    json obj;
    obj["sourceIp"] = value.sourceIp;
    obj["originalIp"] = value.originalIp;
    obj["parentIp"] = value.parentIp;
    obj["relayed"] = value.relayed;
    obj["requestedAt"] = CSTokenModel::formatDate(value.tpRequestedAt);
    jsonOut["payload"] = obj;
    if (value.subject != Subject::CSTokenRequest)
    {
      throw std::string("CSTokenRequestEvent::to_json - Subject should be CSTokenRequest");
    }
    jsonOut["subject"] = SubjectNames.at(value.subject);
  }

  inline void from_json(json const &jsonIn, CSTokenRequestEvent &value)
  {
    json obj = jsonIn.at("payload");
    std::string subject;
    jsonIn.at("subject").get_to(subject);
    value.subject = SubjectFromNames.at(subject);
    obj.at("sourceIp").get_to(value.sourceIp);
    obj.at("originalIp").get_to(value.originalIp);
    obj.at("parentIp").get_to(value.parentIp);
    obj.at("relayed").get_to(value.relayed);
    obj.at("requestedAt").get_to(value.requestedAt);
    auto tpOpt = CSTokenModel::parseDate(value.requestedAt);
    if (tpOpt)
      value.tpRequestedAt = *tpOpt;
  };

  inline void to_json(json &jsonOut, CSTokenAcquireEvent const &value)
  {
    json obj;
    obj["sourceIp"] = value.sourceIp;
    obj["ip"] = value.ip;
    obj["acquiredAt"] = CSTokenModel::formatDate(value.tpAcquiredAt);
    jsonOut["payload"] = obj;
    if (value.subject != Subject::CSTokenAcquire)
    {
      throw std::string("CSTokenAcquireEvent::to_json - Subject should be CSTokenAcquire");
    }
    jsonOut["subject"] = SubjectNames.at(value.subject);
  }

  inline void from_json(json const &jsonIn, CSTokenAcquireEvent &value)
  {
    json obj = jsonIn.at("payload");
    std::string subject;
    jsonIn.at("subject").get_to(subject);
    value.subject = SubjectFromNames.at(subject);
    obj.at("sourceIp").get_to(value.sourceIp);
    obj.at("ip").get_to(value.ip);
    obj.at("acquiredAt").get_to(value.acquiredAt);
    auto tpOpt = CSTokenModel::parseDate(value.acquiredAt);
    if (tpOpt)
      value.tpAcquiredAt = *tpOpt;
  };
  
  inline void to_json(json &jsonOut, CSProcessedServiceEvent const &value)
  {
    json obj;
    obj["serviceMessage"] = value.serviceMessage;
    obj["ip"] = value.ip;
    obj["processedAt"] = CSTokenModel::formatDate(value.tpProcessedAt);
    jsonOut["payload"] = obj;
    if (value.subject != Subject::CSProcessedService)
    {
      throw std::string("CSProcessedServiceEvent::to_json - Subject should be CSProcessedService");
    }
    jsonOut["subject"] = SubjectNames.at(value.subject);
  }

  inline void from_json(json const &jsonIn, CSProcessedServiceEvent &value)
  {
    json obj = jsonIn.at("payload");
    std::string subject;
    jsonIn.at("subject").get_to(subject);
    value.subject = SubjectFromNames.at(subject);
    obj.at("serviceMessage").get_to(value.serviceMessage);
    obj.at("ip").get_to(value.ip);
    obj.at("processedAt").get_to(value.processedAt);
    auto tpOpt = CSTokenModel::parseDate(value.processedAt);
    if (tpOpt)
      value.tpProcessedAt = *tpOpt;
  };

} // namespace Events
