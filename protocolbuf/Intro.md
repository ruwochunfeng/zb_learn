**Introduction of Protocol Buffer**

the reference google document.

Protocol Buffers are Google's language-neutral, platform-neutral, extensible mechanism for serializing structured data.

for c++ developer:

**first we need protocol compiler installation.**

tools needed:

- autoconf

- automake

- libtool

- make

- g++

- unzip

  

the install command:

sudo apt-get install autoconf automake libtool curl make g++ unzip

currently, i only need c++ version protocol buffer, so i just download protobuf-cpp-[VERSION].tar.gz.

To build and install the C++ Protocol Buffer runtime:

./configure
make 
make check
sudo make install
sudo ldconfig # refresh shared library cache.



