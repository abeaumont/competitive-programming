FROM circleci/python:2.7.14-stretch
RUN sudo apt-get update && sudo apt-get install nim sbcl rustc ruby ocaml opam glpk-utils python-numpy python-scipy
RUN opam init -a
RUN opam install core
RUN wget http://picat-lang.org/download/picat24_linux64.tar.gz -O /tmp/picat24_linux64.tar.gz \
         && tar zxvf /tmp/picat24_linux64.tar.gz -C /tmp --no-same-owner \
         && sudo mv /tmp/Picat/picat /usr/bin
RUN wget https://bitbucket.org/squeaky/portable-pypy/downloads/pypy3.5-5.10.1-linux_x86_64-portable.tar.bz2 -O /tmp/pypy3.5-5.10.1-linux_x86_64-portable.tar.bz2 \
         && tar jxvf /tmp/pypy3.5-5.10.1-linux_x86_64-portable.tar.bz2 -C /tmp --no-same-owner \
         && sudo ln -s /tmp/pypy3.5-5.10.1-linux_x86_64-portable/bin/pypy3 /usr/bin/pypy3
