#!/bin/bash

cd ch9344ser_linux_V1.9
cd driver

make
sudo make load
sudo make install
sudo echo "ch9344" >> /etc/modules-load.d/modules.conf
cd ..
cd ..
