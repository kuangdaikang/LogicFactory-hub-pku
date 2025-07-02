FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=Asia/Shanghai

RUN apt-get update && apt-get upgrade -y --no-install-recommends apt-utils

# build essential
RUN apt-get install -y \
    software-properties-common \
    build-essential \
    wget \
    curl \
    cmake \
    ninja-build \
    git

# toolkit related libraries
RUN apt-get install -y \
    libreadline6-dev \
    tcl-dev \
    pkg-config \
    bison \
    flex \
    rustc \
    cargo


RUN apt-get install -y \
    libboost-all-dev \
    libeigen3-dev \
    libgtest-dev \
    libgoogle-glog-dev \
    libyaml-cpp-dev \
    libcairo2-dev \
    libunwind-dev \
    libgmp-dev \
    libgmpxx4ldbl \
    libhwloc-dev \
    libffi-dev \
    libgflags-dev \
    libmetis-dev

RUN add-apt-repository ppa:ubuntu-toolchain-r/test -y \
    && apt-get update \
    && apt-get install -y gcc-10 g++-10

# python and distutils
RUN apt-get update && apt-get install -y \
    python3.8 \
    python3.8-dev \
    python3.8-distutils \
    python3-pip

RUN python3.8 -m pip install --upgrade pip setuptools wheel

RUN python3.8 -m pip install matplotlib imageio

# rust and cargo
# you can use this mirror for faster download
ENV RUSTUP_DIST_SERVER=https://mirrors.tuna.tsinghua.edu.cn/rustup
RUN curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s -- -y
ENV PATH="/root/.cargo/bin:${PATH}"

RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-10 60 --slave /usr/bin/g++ g++ /usr/bin/g++-10

# Anaconda3 installation
ENV CONDA_DIR=/opt/conda
ENV PATH="$CONDA_DIR/bin:$PATH"

RUN wget --quiet https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh -O ~/miniconda.sh && \
    /bin/bash ~/miniconda.sh -b -p $CONDA_DIR && \
    rm ~/miniconda.sh && \
    # Allow mamba installation
    conda install -y mamba -n base -c conda-forge && \
    # Clean up
    conda clean -ya



WORKDIR /workspace

CMD ["bash"]