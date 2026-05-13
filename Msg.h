#ifndef MSG_H
#define MSG_H
#include <string>

class Msg {
private:
    std::string info;
public:
    Msg(const std::string &info);
    virtual ~Msg() = default;
    virtual std::string getType() const = 0;
};

class EmailMsg : public Msg {
private:
    static int n;
    unsigned int ID;
    std::string srcAddr, dstAddr;
public:
    EmailMsg(const std::string &info, const std::string &src, const std::string &dst);
    std::string getType() const override;
};

class MobileMsg : public Msg {
private:
    static int n;
    unsigned int ID;
    std::string srcPhoneNo, dstPhoneNo;
public:
    MobileMsg(const std::string &info, const std::string &src, const std::string &dst);
    std::string getType() const override;
};
#endif
