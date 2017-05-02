FROM ubuntu:16.04
MAINTAINER Yung-Jin (Joey) Hu <yungjinhu@gmail.com>

RUN apt-get update && apt-get install -y \
    build-essential \
    clang \
    clang-3.8 \
    curl \
    doxygen \
    graphviz \
    lldb \
    python-lldb-3.8 \
    python3.5 \
    valgrind \
    vim \
    && rm -rf /var/lib/apt/lists/*
RUN curl -sSL https://cmake.org/files/v3.8/cmake-3.8.0-Linux-x86_64.tar.gz | tar -xzC /opt && \
    ln -s /opt/cmake-3.8.0-Linux-x86_64/bin/cmake /usr/local/bin/cmake
ENV CC /usr/bin/clang
ENV CXX /usr/bin/clang++
RUN printf "\n# set bash prompt to vi mode\nset -o vi" >> /root/.bashrc
