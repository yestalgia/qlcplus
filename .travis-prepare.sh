#!/bin/bash

# This script is triggered from the bfore_script section of .travis.yml
# It runs the appropriate commands depending on the task requested.

if [ "$QT" = "qt5qml" ]; then
  export QMAKE=/opt/qt514/bin/qmake
else
  export QMAKE=/opt/qt56/bin/qmake

  # Remove the old g++/gcc to ensure we're using the latest ones
  if [ "$CXX" = "g++" ]; then
    sudo rm /usr/bin/gcc
    sudo rm /usr/bin/g++
    sudo ln -s /usr/bin/gcc-7 /usr/bin/gcc
    sudo ln -s /usr/bin/g++-7 /usr/bin/g++
    export CXX="g++-7" CC="gcc-7"
  fi

  # Start xvfb so UI tests don't fail
  export DISPLAY=:99.0
  /etc/init.d/xvfb start
fi

if [ "$TASK" = "coverage" ]; then
  gem install coveralls-lcov
fi

# Report the compiler version
$CXX --version

# Report the qmake version
$QMAKE -v

exit $?
