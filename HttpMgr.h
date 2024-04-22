#ifndef HTTPMGR_H
#define HTTPMGR_H

#include "Singleton.h"
#include <QString>
#include <QUrl>
#include <QObject>
#include <QNetworkAccessManager>
#include <QJsonObject>
#include <QJsonDocument>
#include <global.h>

class HttpMgr:public QObject,public Singleton<HttpMgr>,
                public std::enable_shared_from_this<HttpMgr>{
    Q_OBJECT;
public:
    ~HttpMgr();
private:
    friend class Singleton<HttpMgr>;
    HttpMgr();
    QNetworkAccessManager _manager;
    void post_http_request(QUrl url,QJsonObject json,ReqId req_id,Modules mod);
private slots:
    void slot_http_finish(ReqId id,QString res,ErrorCodes err_code,Modules mod);
 signals:
    void sig_http_finish(ReqId id,QString res,ErrorCodes err_code,Modules mod);
    void sig_reg_mod_finish(ReqId id,QString res,ErrorCodes error_code);
};

#endif // HTTPMGR_H
