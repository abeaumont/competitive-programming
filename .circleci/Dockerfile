FROM circleci/python:2.7.14-stretch


## Install dependencies to add new package sources
RUN sudo apt-get update
RUN sudo apt-get install apt-transport-https ca-certificates curl gnupg2
RUN sudo apt-get install software-properties-common


## Add additional package sources
# Crystal
RUN curl -sL "https://keybase.io/crystal/pgp_keys.asc" | sudo apt-key add -
RUN echo "deb https://dist.crystal-lang.org/apt crystal main" \
  | sudo tee /etc/apt/sources.list.d/crystal.list

# D
RUN sudo wget http://master.dl.sourceforge.net/project/d-apt/files/d-apt.list \
    -O /etc/apt/sources.list.d/d-apt.list
RUN sudo apt-get update
RUN sudo apt-get -y --allow-unauthenticated install --reinstall d-apt-keyring

# Pony
RUN sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys E04F0923 B3B48BDA
RUN sudo add-apt-repository "deb https://dl.bintray.com/pony-language/ponylang-debian $(lsb_release -cs) main"


## Add debian packages
RUN sudo apt-get update

# Common Lisp
RUN sudo apt-get install sbcl

# Crystal
RUN sudo apt-get install crystal

# D
RUN sudo apt-get install dmd-compiler

# Haxe
RUN sudo apt-get install haxe

# Lua
RUN sudo apt-get install lua5.3

# MoonScript dependencies
RUN sudo apt-get install liblua5.3-dev luarocks

# OCaml
RUN sudo apt-get install ocaml

# OCaml packages
RUN sudo apt-get install opam

# OpenDylan dependencies
RUN sudo apt-get install libgc-dev

# Picat dependencies
RUN sudo apt-get install glpk-utils

# Pony
RUN sudo apt-get install ponyc

# Python libraries
RUN sudo apt-get install python3-numpy python3-scipy

# Racket
RUN sudo apt-get install racket

# Ruby
RUN sudo apt-get install ruby

# Rust
RUN sudo apt-get install rustc

# Standard ML
RUN sudo apt-get install mlton


## Installation of tools / libraries
# MoonScript
RUN sudo luarocks install moonscript

# OCaml 4.07.0 and Core
RUN opam init -a
RUN opam switch 4.04.0 # Direct switch to 4.07.0 fails
RUN opam switch 4.07.0
RUN opam install core


## Custom binary installations
# Factor
RUN wget http://downloads.factorcode.org/releases/0.98/factor-linux-x86-64-0.98.tar.gz \
  -O /tmp/factor-linux-x86-64-0.98.tar.gz
RUN tar zxvf /tmp/factor-linux-x86-64-0.98.tar.gz -C /tmp --no-same-owner
RUN sudo ln -s /tmp/factor/factor /usr/bin/factor-vm

# Go
RUN wget https://dl.google.com/go/go1.11.4.linux-amd64.tar.gz \
  -O /tmp/go1.11.4.linux-amd64.tar.gz
RUN tar zxvf /tmp/go1.11.4.linux-amd64.tar.gz -C /tmp --no-same-owner
RUN sudo ln -s /tmp/go/bin/go /usr/bin/go

# JavaScript
RUN wget https://nodejs.org/dist/v10.14.2/node-v10.14.2-linux-x64.tar.xz \
  -O /tmp/node-v10.14.2-linux-x64.tar.xz
RUN tar Jxvf /tmp/node-v10.14.2-linux-x64.tar.xz -C /tmp --no-same-owner
RUN sudo ln -s /tmp/node-v10.14.2-linux-x64/bin/node /usr/bin/node

# Julia
RUN wget https://julialang-s3.julialang.org/bin/linux/x64/1.0/julia-1.0.2-linux-x86_64.tar.gz \
  -O /tmp/julia-1.0.2-linux-x86_64.tar.gz
RUN tar zxvf /tmp/julia-1.0.2-linux-x86_64.tar.gz -C /tmp --no-same-owner
RUN sudo ln -s /tmp/julia-1.0.2/bin/julia /usr/bin/julia

# OpenDylan
RUN wget http://opendylan.org/downloads/opendylan/2014.1/opendylan-2014.1-x86_64-linux.tar.bz2 \
  -O /tmp/opendylan-2014.1-x86_64-linux.tar.bz2
RUN tar jxvf /tmp/opendylan-2014.1-x86_64-linux.tar.bz2 -C /tmp --no-same-owner
RUN sudo ln -s /tmp/opendylan-2014.1/bin/dylan-compiler /usr/bin/dylan-compiler

# Picat
RUN wget http://picat-lang.org/download/picat24_linux64.tar.gz \
  -O /tmp/picat24_linux64.tar.gz
RUN tar zxvf /tmp/picat24_linux64.tar.gz -C /tmp --no-same-owner
RUN sudo mv /tmp/Picat/picat /usr/bin

# PyPy3
RUN wget https://bitbucket.org/squeaky/portable-pypy/downloads/pypy3.5-5.10.1-linux_x86_64-portable.tar.bz2 \
  -O /tmp/pypy3.5-5.10.1-linux_x86_64-portable.tar.bz2
RUN tar jxvf /tmp/pypy3.5-5.10.1-linux_x86_64-portable.tar.bz2 -C /tmp --no-same-owner
RUN sudo ln -s /tmp/pypy3.5-5.10.1-linux_x86_64-portable/bin/pypy3 /usr/bin/pypy3

# Stanza
RUN mkdir -p /tmp/stanza
RUN wget http://lbstanza.org/resources/stanza/lstanza_0_12_14.zip \
  -O /tmp/stanza/lstanza_0_12_14.zip
RUN cd /tmp/stanza/ \
  && unzip lstanza_0_12_14.zip && ./stanza install -platform linux
RUN sudo ln -s /tmp/stanza/stanza /usr/bin/stanza

# Zig
RUN wget https://ziglang.org/builds/zig-linux-x86_64-0.3.0+a9eab69b.tar.xz \
  -O /tmp/zig-linux-x86_64-0.3.0+a9eab69b.tar.xz
RUN tar Jxvf /tmp/zig-linux-x86_64-0.3.0+a9eab69b.tar.xz -C /tmp --no-same-owner
RUN sudo ln -s /tmp/zig-linux-x86_64-0.3.0+a9eab69b/zig /usr/bin/zig

## Custom source installations
# ooc
RUN cd /tmp/ \
  && git clone https://github.com/ooc-lang/rock.git \
  && cd rock && make rescue

# Wren
RUN cd /tmp/ \
  && git clone https://github.com/munificent/wren.git \
  && cd wren && make
RUN sudo ln -s /tmp/wren/wren /usr/bin/wren
