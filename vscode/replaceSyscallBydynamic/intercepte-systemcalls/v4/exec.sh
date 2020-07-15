#!/bin/bash
g++ -o tcp_client tcp_client.cc
export LD_PRELOAD="./foo.so"
./tcp_client
