<!--
- Copyright (c) 2019-2020, Yesir-Lincoln and Contributors
-
- SPDX-License-Identifier: Apache-2.0
-
- Licensed under the Apache License, Version 2.0 the "License";
- you may not use this file except in compliance with the License.
- You may obtain a copy of the License at
-
-     http://www.apache.org/licenses/LICENSE-2.0
-
- Unless required by applicable law or agreed to in writing, software
- distributed under the License is distributed on an "AS IS" BASIS,
- WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
- See the License for the specific language governing permissions and
- limitations under the License.
-
-->

# OpenGL Learning Step by Step <!-- omit in toc -->

## Contents <!-- omit in toc -->

- [Introduction](#introduction)
  - [Goals](#goals)
- [Tutorials](#tutorials)
- [Setup](#setup)
- [Build](#build)
  - [Supported Platforms](#supported-platforms)
- [Usage](#usage)
- [Testing](#tests)
- [License](#license)
  - [Trademarks](#trademarks)
- [Contributions](#contributions)
- [Related resources](#related-resources)

## Introduction

这是我学习OpenGL的记录，也是对自己的一个督促，另外也方便本地系统出问题后可以快速恢复环境。
代码并不是原创，来自相关的网站，详细的在最后的参考中详细一一罗列，最主要的代码来自[learnopengl](https://learnopengl.com)。
我是在Ubuntu 20的上配置OpenGL环境调试成功的，过程中可能对参考代码进行修改。并会不断的更新Makefile。
后期可能也会基于理解深入，基于自己的需求，写出自己的代码。
(目前这个README文件是我copy的一个现成的README文件，后续慢慢更改)

### Goals
- Create a collection of resources that demonstrate best-practice recommendations in Vulkan
- Create tutorials that explain the implementation of best-practices and include performance analysis guides
- Create a framework that can be used as reference material and also as a sandbox for advanced experimentation with Vulkan

## Tutorials
- **Project Hierarchy**

  - [Directory Tree](./docs/)
  
    OpenGL
    ├── learnOpenGL
    │   ├── Makefile
    │   └── src
    │       ├── hello_triangle.cpp
    │       └── hello_window_clear.cpp
    ├── README.md
    ├── testExperi
    │   ├── hellowindow2.cpp
    │   └── Makefile
    └── thirdParty
        ├── inc
        │   ├── glad
        │   │   └── glad.h
        │   ├── GLFW
        │   │   ├── glfw3.h
        │   │   └── glfw3native.h
        │   └── KHR
        │       └── khrplatform.h
        ├── lib
        │   └── libglfw3.a
        └── src
            └── glad.c


- **Envirenment Setup**
  - [Controls](./docs/misc.md#controls)
    1.基本依赖
    1)基本编译库
    sudo apt-get install build-essential
    2)需要 OpenGL 库
    sudo apt-get install libgl1-mesa-dev
    3)安装cmake工具
    sudo apt-get install cmake

    2.第三方库
    1)GLFW
    1>安装GLFW X11依赖库
    sudo apt-get install xorg-dev 
    2>下载GLFW source code(也可以直接官网下载)并编译(可以选择文件夹内编译或者文件夹外编译)
    git clone https://github.com/glfw/glfw.git
    cd <glfw-root-dir>
    cmake .
    3>正真安装(默认头文件目录：/usr/local/include, lib目录：/usr/local/lib)
    make
    make install

    2)glad
    通过网站 https://glad.dav1d.de/ 直接生成。
    在这个网站上生成合适的库，我选择了C/C++ OpenGL Core Version 4.6然后点击GENERATE即可得到压缩包。
    把压缩包内include目录的东西放到第三方库(../thirdParty/inc/glad), 把src下的源码拷贝到(../thirdParty/src)
  - [Debug window](./docs/misc.md#debug-window)
  - [Create a Sample](./docs/create_sample.md)
- **Make file**  
  - [The makefile](./Makefile)


    3)其他第三方库（使用/usr/local/lib来存放库文件）
    对于需要使用的其他第三方库，，
    3.1 按照其方法编译(比如使用Cmake等工具);
    3.2 把头文件拷贝到inc目录下;
    3.3 把静态文件.a或者动态文件.so拷贝到目录/usr/local/lib,在文件/etc/ld.so.conf中加入目录/usr/local/lib(通常已经都有这个目录了),并调用命令ldconfig刷新;
    3.4 在makefile中的LDFLAGS中加上参数 -llibname;


## Setup

Clone the repo with submodules using the following command:

```
git clone --recurse-submodules https://github.com/KhronosGroup/Vulkan-Samples.git
cd Vulkan-Samples
```

Follow build instructions for your platform below.

## Build

### Supported Platforms
- Windows - [Build Guide](./docs/build.md#windows "Windows Build Guide")
- Linux - [Build Guide](./docs/build.md#linux "Linux Build Guide")
- macOS - [Build Guide](./docs/build.md#macos "macOS Build Guide")
- Android - [Build Guide](./docs/build.md#android "Android Build Guide")

## Usage

The following shows some example command line usage on how to configure and run the Vulkan Samples.

```
# Run Swapchain Images sample
vulkan_samples swapchain_images

# Run AFBC sample in benchmark mode for 5000 frames
vulkan_samples --sample afbc --benchmark 5000

# Run bonza test offscreen
vulkan_samples --test bonza --hide

# Run all the performance samples
vulkan_samples --batch performance

# Run Swapchain Images sample on an Android device
adb shell am start-activity -n com.khronos.vulkan_samples/com.khronos.vulkan_samples.SampleLauncherActivity -e sample swapchain_images
```

## Tests

- System Test - [Usage Guide](docs/testing.md#system-test "System Test Guide")
- Generate Sample - [Usage Guide](docs/testing.md#generate-sample-test "Generate Sample Test Guide")


## License

See [LICENSE](LICENSE).

This project has some third-party dependencies, each of which may have independent licensing:

- [astc-encoder](https://github.com/ARM-software/astc-encoder): ASTC Evaluation Codec
- [CTPL](https://github.com/vit-vit/CTPL): Thread Pool Library
- [docopt](https://github.com/docopt/docopt.cpp): A C++11 port of the Python argument parsing library
- [glfw](https://github.com/glfw/glfw): A multi-platform library for OpenGL, OpenGL ES, Vulkan, window and input
- [glm](https://github.com/g-truc/glm): OpenGL Mathematics
- [glslang](https://github.com/KhronosGroup/glslang): Shader front end and validator
- [dear imgui](https://github.com/ocornut/imgui): Immediate Mode Graphical User Interface
  - [dear imgui shaders](https://github.com/SaschaWillems/Vulkan/tree/master/data/shaders/imgui): GLSL shaders for dear imgui
- [HWCPipe](https://github.com/ARM-software/HWCPipe): Interface to mobile Hardware Counters
- [KTX-Software](https://github.com/KhronosGroup/KTX-Software): Khronos Texture Library and Tools
- [spdlog](https://github.com/gabime/spdlog): Fast C++ logging library
- [SPIRV-Cross](https://github.com/KhronosGroup/SPIRV-Cross): Parses and converts SPIR-V to other shader languages
- [stb](https://github.com/nothings/stb): Single-file public domain (or MIT licensed) libraries
- [tinygltf](https://github.com/syoyo/tinygltf): Header only C++11 glTF 2.0 file parser
- [nlohmann json](https://github.com/nlohmann/json): C++ JSON Library (included by [tinygltf](https://github.com/syoyo/tinygltf))
- [vma](https://github.com/GPUOpen-LibrariesAndSDKs/VulkanMemoryAllocator): Vulkan Memory Allocator
- [volk](https://github.com/zeux/volk): Meta loader for Vulkan API
- [vulkan](https://github.com/KhronosGroup/Vulkan-Docs): Sources for the formal documentation of the Vulkan API

This project uses assets from [vulkan-samples-assets](https://github.com/KhronosGroup/Vulkan-Samples-Assets). Each one has its own licence.

### Trademarks

## Contributions

See [CONTRIBUTORS](CONTRIBUTORS.md) for the full contributor list.

Also see [CONTRIBUTING](CONTRIBUTING.md) for contribution guidelines.

## Related resources

- [Linux(Ubuntu) OpenGL 开发环境](https://www.cnblogs.com/psklf/p/9705688.html): A tutorial to setup OpenGL envirenment step by step
- [how-to-build-install-glfw-3-and-use-it-in-a-linux-project](https://stackoverflow.com/questions/17768008/how-to-build-install-glfw-3-and-use-it-in-a-linux-project): A answer about install GLFW

2021/12/18:
Add the learnning Code From [OGL-dev Modern OpenGL Turorials](https://ogldev.org)
