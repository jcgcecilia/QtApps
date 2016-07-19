#!/bin/bash
#Running Docker
docker run -v ${PWD}:/home/QtWorkspace -i --entrypoint /bin/bash jcgcecilia/qt:5.7 -c 'cd /home/QtWorkspace;/usr/local/bin/qmake QtDemo.pro CONFIG+=agi;make -j4;make clean'
