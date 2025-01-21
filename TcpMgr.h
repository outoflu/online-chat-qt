#ifndef TCPMGR_H
#define TCPMGR_H

#include <QObject>
#include <QTcpSocket>
#include "Singleton.h"
#include "global.h"
#include "userdata.h"

class TcpMgr:public QObject,public Singleton<TcpMgr>,public std::enable_shared_from_this<TcpMgr>
{
    Q_OBJECT
public:
    TcpMgr();
private:
    QTcpSocket _socket;
    QString _host;
    uint16_t _port;
    QByteArray _buffer;
    bool _b_recv_pending;
    quint16 _message_id;
    quint16 _message_len;
    QMap<ReqId, std::function<void(ReqId id, int len, QByteArray data)>> _handlers;
    void initHandlers();
    void handleMsg(ReqId id, int len, QByteArray data);
signals:
    void sig_con_success(bool success);
    void sig_send_data(ReqId reqId, QByteArray data);
public slots:
    void slot_tcp_connect(ServerInfo serverInfo);
    void slot_send_data(ReqId reqId, QByteArray dataBytes);
signals:
    void sig_slot_chatDlg();
    void sig_load_applyList(QJsonArray jsonArray);
    void sig_login_failed(int);
    void sig_user_search(std::shared_ptr<SearchInfo>);
    void sig_friend_apply(std::shared_ptr<AddFriendApply>);
    void sig_add_auth_friend(std::shared_ptr<AuthInfo>);
    void sig_auth_rsp(std::shared_ptr<AuthRsp>);
    void sig_text_chat_msg(std::shared_ptr<TextChatMsg> msg);
};

#endif // TCPMGR_H
