FROM alpine:3.17

RUN apk update && apk add --no-cache \
    g++ \
    make \
    cmake \
    git \
    ca-certificates

COPY . /elevator

WORKDIR /elevator/build

ARG tests=ON
RUN cmake -DBUILD_TESTING=$tests ..
RUN cmake --build .
