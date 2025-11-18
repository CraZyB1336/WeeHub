# Linux
## Prepare
### Install vcpkg
```sh
$ git clone https://github.com/Microsoft/vcpkg.git # To any directory (recommended home directory) (cd ~)
$ cd vcpkg
$ ./bootstrap-vcpkg.sh
```
Also add vcpkg directory to path

### Install libraries
```sh
$ cmake --preset=linux
```


### Build and Run
```sh
$ cmake --build build
$ ./build/WeeHub
```

# Windows

## Prepare
### Install Visual Studio Build Tools (Not IDE)
1. Go to Visual Studio download site [here](https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2022) (https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2022).
2. Scroll down to **All Downloads** and go to **Tools for Visual Studio**.
3. Download **Build Tools for Visual Studio**.
4. Run it and select **Desktop development with C++**
5. Ensure these options are selected:
    - MSVC x64/x86 Build tools (Latest (2026))
    - Windows 11 SDK
6. Install

### Install vcpkg
```sh
$ git clone https://github.com/Microsoft/vcpkg.git # To any directory (recommended home directory) (cd ~)
$ cd vcpkg
$ ./bootstrap-vcpkg.bat
```
Also add vcpkg directory to path
Also add a new environment variable `VCPKG_ROOT` with the value of the **vcpkg** directory.

### Install CMake
You can install CMake [here](https://cmake.org/download/) (https://cmake.org/download/).
- Download the Windows Installer Binary Distribution

### Install libraries
```sh
$ cmake --preset=windows
```

### Build and Run
```sh
$ cmake --build build
$ ./build/Debug/WeeHub.exe
```