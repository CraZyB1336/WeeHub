# Install vcpkg
```sh
$ git clone https://github.com/Microsoft/vcpkg.git # To any directory (recommended home directory) (cd ~)
$ cd vcpkg
$ ./bootstrap-vcpkg.sh
```
Also add vcpkg directory to path

# Install libraries
```sh
$ cmake --preset=default
```


# Build and Run
```sh
$ cmake --build build
$ ./build/WeeHub
```