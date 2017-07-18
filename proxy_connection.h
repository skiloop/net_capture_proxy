/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   net_capture_proxy_connection.h
 * Author: skiloop
 *
 * Created on 2017年7月18日, 下午5:32
 */

#ifndef NET_CAPTURE_PROXY_CONNECTION_H
#define NET_CAPTURE_PROXY_CONNECTION_H

#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class proxy_connection : public boost::enable_shared_from_this<proxy_connection> {
public:
    typedef boost::shared_ptr<proxy_connection> pointer;
    proxy_connection();
    proxy_connection(const proxy_connection& orig);
    virtual ~proxy_connection();

    static pointer create(boost::asio::io_service& io_service) {
        return pointer(new proxy_connection(io_service));
    }

    tcp::socket& socket() {
        return socket_;
    }
    void start();
private:
    tcp::socket socket_;
};

#endif /* NET_CAPTURE_PROXY_CONNECTION_H */

