#!/bin/bash

cd ch9344ser_linux_V1.9
cd driver

make
sudo make unload
sudo make uninstall

cd ..
cd ..
