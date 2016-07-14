#!/bin/bash
#Running Docker
docker run -v ${PWD}:/home/QtApps -i --entrypoint /bin/bash jcgcecilia/qt:5.7 -c 'cd /home/QtApps;/usr/local/bin/qmake QtDemo.pro CONFIG+=agi;make -j4;make clean'
