#include "Msg.h"

Msg::Msg(const std::string &info) : info(info) {}

int EmailMsg::n = 1; 
EmailMsg::EmailMsg(const std::string &info, const std::string &src, const std::string &dst)
    : Msg(info), srcAddr(src), dstAddr(dst), ID(n++) {}
std::string EmailMsg::getType() const { return "EmailMsg"; }

int MobileMsg::n = 1000; 
MobileMsg::MobileMsg(const std::string &info, const std::string &src, const std::string &dst)
    : Msg(info), srcPhoneNo(src), dstPhoneNo(dst), ID(n++) {}
std::string MobileMsg::getType() const { return "MobileMsg"; }
