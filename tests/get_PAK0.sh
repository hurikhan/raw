#! /usr/bin/env bash

mkdir quake106
cd quake106

figlet wget
wget https://github.com/hurikhan/hurikhan.github.io/raw/master/files/gdQuake1/quake106.zip

figlet unzip
unzip quake106.zip

figlet lha
lha x resource.1

figlet cleanup
mv id1/pak0.pak ..
cd ..
rm -Rfv quake106

figlet md5sum
md5sum -c pak0.md5
