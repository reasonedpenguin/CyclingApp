#include "IDataSource.h"


IDataSource::IDataSource()
{
}


QString IDataSource::getErrorMsg() {
    return m_errorMsg;
}
