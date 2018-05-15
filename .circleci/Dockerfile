FROM circleci/python:2.7.14-stretch

# Common Lisp, OCaml, Ruby, Rust and some additional libraries
RUN sudo apt-get update && sudo apt-get install nim sbcl rustc ruby ocaml opam glpk-utils python3-numpy python3-scipy

# OCaml's Core
RUN opam init -a
RUN opam install core

# Picat
RUN wget http://picat-lang.org/download/picat24_linux64.tar.gz -O /tmp/picat24_linux64.tar.gz \
         && tar zxvf /tmp/picat24_linux64.tar.gz -C /tmp --no-same-owner \
         && sudo mv /tmp/Picat/picat /usr/bin

# PyPy3
RUN wget https://bitbucket.org/squeaky/portable-pypy/downloads/pypy3.5-5.10.1-linux_x86_64-portable.tar.bz2 -O /tmp/pypy3.5-5.10.1-linux_x86_64-portable.tar.bz2 \
         && tar jxvf /tmp/pypy3.5-5.10.1-linux_x86_64-portable.tar.bz2 -C /tmp --no-same-owner \
         && sudo ln -s /tmp/pypy3.5-5.10.1-linux_x86_64-portable/bin/pypy3 /usr/bin/pypy3

# OpenDylan
RUN wget http://opendylan.org/downloads/opendylan/2014.1/opendylan-2014.1-x86_64-linux.tar.bz2 -O /tmp/opendylan-2014.1-x86_64-linux.tar.bz2 \
				 && tar jxvf /tmp/opendylan-2014.1-x86_64-linux.tar.bz2 -C /tmp --no-same-owner \
				 && sudo ln -s /tmp/opendylan-2014.1/bin/dylan-compiler /usr/bin/dylan-compiler
