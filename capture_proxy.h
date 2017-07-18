/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   net_capture_proxy.h
 * Author: skiloop
 *
 * Created on 2017年7月18日, 下午5:32
 */

#ifndef NET_CAPTURE_PROXY_H
#define NET_CAPTURE_PROXY_H

#include <ctime>
#include <iostream>
#include <string>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include "proxy_connection.h"
#include "proxy_config.h"
using boost::asio::ip::tcp;

class capture_proxy {
public:
    capture_proxy(boost::asio::io_service& io_service, const proxy_config& config);
    capture_proxy(const capture_proxy& orig);
    virtual ~capture_proxy();
private:
    tcp::acceptor acceptor_;
    proxy_config config;
    
    void start_accept();
    void handle_accept(proxy_connection::pointer,const boost::system::error_code& error);
};

#endif /* NET_CAPTURE_PROXY_H */

