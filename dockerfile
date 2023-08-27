# Use Ubuntu 20.04 as the base image
FROM ubuntu:20.04

# Set the working directory inside the container
WORKDIR /app

# Install required packages
RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y \
    sudo \
    build-essential \
    git \
    m4 \
    scons \
    zlib1g \
    zlib1g-dev \
    libprotobuf-dev \
    protobuf-compiler \
    libprotoc-dev \
    libgoogle-perftools-dev \
    python3-dev \
    python-is-python3 \
    libboost-all-dev \
    pkg-config

# Set up the shared folder with the local machine
VOLUME ["/media/tanawin/tanawin1701e/Project/gem5base/gem5"]

# Start the container with an interactive shell
CMD ["/bin/bash"]