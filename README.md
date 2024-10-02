# LogicFactory

![Framework](LogicFactory.svg "framework")

# Build
- method1: build with docker env (recommend)
```
$ git clone https://github.com/Logic-Factory/LogicFactory.git
$ cd LogicFactory
$ git submodule update --init --recursive
$ docker build -t logic-factory:latest .
$ docker run -it -v ./LogicFactory:/workspace logic-factory:latest
$ cd /workspace
$ mkdir -p build && cd build
$ cmake -G Ninja ..
$ ninja
```

- method2: install dependencies and compile 
    - install build essential
    ```
    $ sudo apt-get update && sudo apt-get upgrade -y --no-install-recommends apt-utils
    $ sudo apt-get install -y software-properties-common build-essential wget curl cmake ninja-build git
    $ sudo apt-get install -y libreadline6-dev tcl-dev pkg-config bison flex rustc cargo libboost-all-dev libeigen3-dev libgtest-dev libgoogle-glog-dev libyaml-cpp-dev libcairo2-dev libunwind-dev libgmp-dev libgmpxx4ldbl libhwloc-dev libffi-dev libgflags-dev libmetis-dev
    ```
    - install gcc-10/g++-10
    ```
    $ sudo add-apt-repository ppa:ubuntu-toolchain-r/test -y
    $ sudo apt-get update
    $ sudo apt-get install -y gcc-10 g++-10
    $ sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-10 60 --slave /usr/bin/g++ g++ /usr/bin/g++-10
    ```
    - install rust
    ```
    $ export RUSTUP_DIST_SERVER=https://mirrors.tuna.tsinghua.edu.cn/rustup
    $ curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s -- -y
    $ export PATH="/root/.cargo/bin:${PATH}"
    ```
    - compile
    ```
    $ git clone https://github.com/Logic-Factory/LogicFactory.git
    $ cd LogicFactory
    $ git submodule update --init --recursive
    $ mkdir -p build && cd build
    $ cmake -G Ninja ..
    $ ninja
    ```


# Getting Started
- RUN with tcl
```
$ ./build/app/logicfactory -s "demo/test.tcl"
```

- RUN with command sequence
```
$ ./build/app/logicfactory -c "help; start;"
```

- RUN with command line
```
$ ./build/app/logicfactory
--------------------------------------------
*    Welcome to LogicFactory (Platform)    *
*               Version 0.1                *
*     https://github.com/Logic-Factory     *
--------------------------------------------
% help
```