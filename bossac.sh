#!/bin/bash

port=/dev/ttyACM0

for arg in "$@"
do
case $arg in --port=*)
    port="/dev/${arg:7}"
esac
done


stty -F $port speed 1200 cs8 -cstopb -parenb > /dev/null 2>&1
/home/jgdo/tools/sloeber/arduinoPlugin/packages/arduino/tools/bossac/1.6.1-arduino/bossac "$@"
