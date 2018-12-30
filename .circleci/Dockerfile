FROM archlinux/base

## Pacman config customization
# Use /tmp for package cache dir
RUN sed -i s/#CacheDir/CacheDir/ /etc/pacman.conf
RUN sed -i s/var\\/cache/tmp/ /etc/pacman.conf

## Upgrade system
RUN pacman -Suy --noconfirm

## Install CircleCI dependencies
RUN pacman -S --noconfirm awk binutils diffutils fakeroot file gcc git make
RUN pacman -S --noconfirm pkg-config sudo tar yajl

## Setup circleci user and group
RUN groupadd -g 3434 circleci
RUN useradd -u 3434 -g circleci -s /bin/bash --create-home circleci
RUN echo 'circleci ALL=NOPASSWD: ALL' > /etc/sudoers.d/50-circleci

USER circleci
WORKDIR /home/circleci
RUN mkdir -p /home/circleci/.local/bin
ENV PATH=/home/circleci/.local/bin:$PATH

## Install yaourt for easy access to AUR repos
RUN git clone https://aur.archlinux.org/package-query.git
RUN cd package-query && makepkg -si --noconfirm
RUN git clone https://aur.archlinux.org/yaourt.git
RUN cd yaourt && makepkg -si --noconfirm
ENV TERM vt100

## Install common language dependencies
RUN yaourt -S --noconfirm glpk lua patch z3
RUN echo "/usr/bin/glpsol \$* > /dev/null" > /home/circleci/.local/bin/glpsol
RUN chmod a+x /home/circleci/.local/bin/glpsol

## Install languages
# Common Lisp
RUN yaourt -S --noconfirm sbcl

# Crystal
RUN yaourt -S --noconfirm crystal

# D
RUN yaourt -S --noconfirm dmd

# Factor
RUN yaourt -S --noconfirm factor

# JavaScript
RUN yaourt -S --noconfirm nodejs

# Julia
RUN yaourt -S --noconfirm julia

# Haxe
RUN yaourt -S --noconfirm haxe

# Go
RUN yaourt -S --noconfirm go

# MoonScript
RUN yaourt -S --noconfirm moonscript

# Nim
# Package doesn't work properly, use choosenim instead
RUN curl https://nim-lang.org/choosenim/init.sh -sSf > choosenim-init.sh
RUN sh choosenim-init.sh -y
ENV PATH=/home/circleci/.nimble/bin:$PATH

# OCaml
RUN yaourt -S --noconfirm ocaml
RUN yaourt -S --noconfirm ocaml-base ocaml-bin_prot ocaml-configurator
RUN yaourt -S --noconfirm ocaml-fieldslib ocaml-jane-street-headers
RUN yaourt -S --noconfirm ocaml-ppx_assert ocaml-ppx_base ocaml-ppx_hash
RUN yaourt -S --noconfirm ocaml-ppx_inline_test ocaml-ppx_jane
RUN yaourt -S --noconfirm ocaml-ppx_sexp_conv ocaml-ppx_sexp_message
RUN yaourt -S --noconfirm ocaml-sexplib ocaml-splittable_random ocaml-stdio
RUN yaourt -S --noconfirm ocaml-typerep ocaml-variantslib
RUN yaourt -S --noconfirm ocaml-migrate-parsetree ocaml-ppxlib ocaml-spawn
RUN git clone https://github.com/abeaumont/aur-ocaml-core_kernel.git
RUN cd aur-ocaml-core_kernel && makepkg -si --noconfirm
RUN git clone https://github.com/abeaumont/aur-ocaml-core.git
RUN cd aur-ocaml-core && makepkg -si --noconfirm

# ooc
RUN yaourt -S --noconfirm rock

# OpenDylan
RUN yaourt -S --noconfirm opendylan
ENV OPEN_DYLAN_USER_ROOT=/home/circleci/.od
RUN make-dylan-app dylan-prebuild
RUN dylan-compiler -build dylan-prebuild/dylan-prebuild.lid

# Picat
RUN yaourt -S --noconfirm picat

# Pony
RUN yaourt -S --noconfirm ponyc

# Python2
RUN yaourt -S --noconfirm python2

# Python3
RUN yaourt -S --noconfirm --needed python python-numpy python-scipy

# PyPy 3
RUN yaourt -S --noconfirm pypy3

# Racket
RUN yaourt -S --noconfirm racket

# Ruby
RUN yaourt -S --noconfirm ruby

# Rust
RUN yaourt -S --noconfirm rust

# Standard ML
RUN yaourt -S --noconfirm mlton

# Stanza
RUN git clone https://github.com/abeaumont/aur-stanza.git
RUN cd aur-stanza && makepkg -si --noconfirm
RUN cd /opt/stanza/ && ./stanza install -platform linux

# Wren
RUN yaourt -S --noconfirm wren

# Zig
RUN yaourt -S --noconfirm zig-git
