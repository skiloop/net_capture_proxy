/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   proxy_config.h
 * Author: skiloop
 *
 * Created on 2017年7月18日, 下午6:21
 */

#ifndef PROXY_CONFIG_H
#define PROXY_CONFIG_H
#include "capture_rules.h"
#include "webpage_db.h"

class proxy_config {
public:

    proxy_config(const int port, const capture_rules* rules_ptr,
            const webpage_db* db_ptr, const std::string& addr)
    : port(port), rules_ptr(rules_ptr), db_ptr(db_ptr), address(addr) {

    }

    proxy_config(const proxy_config& orig) : port(orig.port),
    rules_ptr(orig.rules_ptr), db_ptr(orig.db_ptr), address(orig.address) {
    }
    virtual ~proxy_config();

    const int port;
    const capture_rules *rules_ptr;
    const webpage_db* db_ptr;
    const std::string address;
};

#endif /* PROXY_CONFIG_H */

