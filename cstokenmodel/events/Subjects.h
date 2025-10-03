
#ifndef EVENT_SUBJECTS_H
#define EVENT_SUBJECTS_H

#include <string>
#include <map>

namespace CSTokenEvents
{
  
  enum class Subject
  {
    Invalid = -1,
    ClientCSConnected,
    ClientCSDisconnected,
    CSTokenRequest,
    CSTokenAcquire
  };

  static const std::map<Subject, std::string_view> SubjectNames = {
      {Subject::ClientCSConnected, "cstoken_client_Connected"},
      {Subject::ClientCSDisconnected, "cstoken_client_Disconnected"},
      {Subject::CSTokenRequest, "cstoken_token_Request"},
      {Subject::CSTokenAcquire, "cstoken_token_Acquire"}};

  static const std::map<std::string_view, Subject> SubjectFromNames = {
      {"cstoken_client_Connected", Subject::ClientCSConnected},
      {"cstoken_client_Disconnected", Subject::ClientCSDisconnected},
      {"cstoken_token_Request", Subject::CSTokenRequest},
      {"cstoken_token_Acquire", Subject::CSTokenAcquire}};

}
#endif // EVENT_SUBJECTS_H
