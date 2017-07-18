/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   net_capture_proxy.cpp
 * Author: skiloop
 * 
 * Created on 2017年7月18日, 下午5:32
 */

#include "capture_proxy.h"
#include "proxy_connection.h"

capture_proxy::capture_proxy(boost::asio::io_service& io_service, const proxy_config& config) {
    tcp::endpoint endpoint=tcp::endpoint()
}

capture_proxy::capture_proxy(const capture_proxy& orig) {
}

capture_proxy::~capture_proxy() {
}

void capture_proxy::start_accept() {
    proxy_connection::pointer new_connection = proxy_connection::create(acceptor_.get_io_service());
    acceptor_.async_accept(new_connection->socket(),
            boost::bind(&capture_proxy::handle_accept,
            this, new_connection, boost::asio::placeholders::error));
}

void capture_proxy::handle_accept(proxy_connection::pointer con_ptr,
        const boost::system::error_code& error) {
    if (!error) {
        con_ptr->start();
    }
    start_accept();
}
