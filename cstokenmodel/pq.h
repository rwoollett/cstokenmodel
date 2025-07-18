#pragma once

#include "ClientCS.h"

#ifdef LIBPQ_FOUND
#include <libpq-fe.h>
namespace CSTokenModel::PG
{
  namespace ClientCS
  {
    CSTokenModel::ClientCS fromPGRes(PGresult *res, int nCols, int rowIndex = 0);
  }

  namespace ClientConnectCS
  {
    CSTokenModel::ClientConnectCS fromPGRes(PGresult *res, int nCols, int rowIndex = 0);
  }

  namespace ClientDisconnectCS
  {
    CSTokenModel::ClientDisconnectCS fromPGRes(PGresult * res, int nCols, int rowIndex = 0);
  }

} // namespace Model
#endif //LIBPQ_FOUND
