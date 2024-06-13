FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get upgrade -y

# build essential
RUN apt-get install -y \
    software-properties-common \
    build-essential \
    wget \
    cmake \
    git

# toolkit related libraries
RUN apt-get install -y \
    libreadline6-dev \
    tcl-dev \
    pkg-config \
    bison \
    flex \
    libffi-dev

RUN add-apt-repository ppa:ubuntu-toolchain-r/test -y \
    && apt-get update \
    && apt-get install -y gcc-10 g++-10


RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-10 60 --slave /usr/bin/g++ g++ /usr/bin/g++-10


WORKDIR /workspace

CMD ["bash"]
