FROM ubuntu:16.04
MAINTAINER Yung-Jin (Joey) Hu <yungjinhu@gmail.com>

RUN apt-get update && apt-get install -y \
    build-essential \
    clang \
    clang-3.8 \
    doxygen \
    graphviz \
    lldb \
    python-lldb-3.8 \
    python3.5 \
    valgrind \
    vim \
    && rm -rf /var/lib/apt/lists/*
RUN printf "\n# set bash prompt to vi mode\nset -o vi" >> /root/.bashrc
