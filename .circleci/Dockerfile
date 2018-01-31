FROM alpine:3.7
RUN apk update && apk add git openssh tar gzip ca-certificates python2 g++
RUN wget http://picat-lang.org/download/picat22_linux64.tar.gz -O /tmp/picat22_linux64.tar.gz \
         && tar zxvf /tmp/picat22_linux64.tar.gz -C /tmp --no-same-owner \
         && mv /tmp/Picat/picat /usr/bin
