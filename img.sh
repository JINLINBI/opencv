#########################################################################
# File Name: img.sh
# Author: jinlin
# mail:898141731@qq .com
# Created Time: Thursday, September 22, 2016 AM12:28:59 GMT
#########################################################################
#!/bin/bash
g++ img.cpp `pkg-config --cflags --libs opencv` -o img
./img ~/Downloads/img.jpg
