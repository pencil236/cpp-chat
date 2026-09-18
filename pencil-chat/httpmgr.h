#ifndef HTTPMGR_H
#define HTTPMGR_H

#include "singleton.h"

#include <memory>
#include <QNetworkAccessManager>
#include <QObject>

class HttpMgr : public QObject,
                public Singleton<HttpMgr>,
                public std::enable_shared_from_this<HttpMgr>
{
    Q_OBJECT

public:
    ~HttpMgr();

private:
    friend class Singleton<HttpMgr>;

    HttpMgr();

    QNetworkAccessManager _manager;
};

#endif // HTTPMGR_H
