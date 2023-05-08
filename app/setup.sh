#!/bin/bash

echo "X"

# Обновляем пакеты

echo "UPD"

apt-get update
apt-get upgrade -y

# Устанавливаем необходимые пакеты

echo "Packs"

apt-get install -y \
build-essential \
cmake \
git \
wget \
unzip \
g++ \
libssl-dev \
libboost-all-dev 

# Wt

echo "Wt"

cd /
mkdir .tmp && cd .tmp
wget https://github.com/emweb/wt/archive/4.9.2.tar.gz
tar -zxvf 4.9.2.tar.gz && cd wt-4.9.2
mkdir build && cd build
cmake ../
make
make install
ls /usr/local/include/Wt