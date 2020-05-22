# Blam Creation Suite
## What is Blam Creation Suite?
The Blam Creation Suite is a repository of tools for the purpose of creating custom content for the compilation of titles in Halo: The Master Chief Collection. This project is managed by the Assault on the Control you can find out more about this project and Halo modding at the official website [assaultonthecontrolroom.com](https://assaultonthecontrolroom.com) or join our [Discord](https://discord.gg/ksvhEQD) channel.

[![Build status](https://ci.appveyor.com/api/projects/status/tjha8f9o6brbbc4k/branch/master?svg=true)](https://ci.appveyor.com/project/Assault-on-the-Control-Room/Blam-Creation-Suite/branch/master) [![Discord](https://img.shields.io/discord/598260526480359454?label=Discord)](https://discord.gg/ksvhEQD)

## Download/Continuous Integration
You can find the latest builds available for download on the [AppVeyor Continuous Integration]([https://ci.appveyor.com/project/Assault-on-the-Control-Room/Blam-Creation-Suite/branch/master/artifacts](https://ci.appveyor.com/project/Assault-on-the-Control-Room/Blam-Creation-Suite/branch/master/artifacts))

## Engineering Overview
Blam Creation Suite is made up of a collection of tools and a very wide variety of programming expertise is spread throughout each project. The project structure is designed around engine, tooling, and library modules written in C++ and is designed to have no binary dependencies.
* **Opus** is a launcher framework for replacing the Unreal Engine loader for Master Chief Collection and allowing greater programming control over each of the game engines. Opus is designed to glue other projects in the Blam Creation Suite together and allow them to run in real-time with the engine. For example, running Mantle natively with the engine for real-time tag and resource editing.
* **Mantle** is a Blam tag/resource editing framework designed to fulfill the traditional role of the Guerilla/Bonobo tool from the authentic engine tools. Mantle is designed for extremely high performance and a high degree of game engine abstraction and relies on C++ code generation form Blofeld for the majority of its backend functionality.
* **Blofeld** is a Blam tag layout framework loosely based off of the original 2005 GDC presentation [Content Management for Halo 2 and Beyond]([https://nikon.bungie.org/misc/gdc2005_mnoguchi/](http://nikon.bungie.org/misc/gdc2005_mnoguchi/)). Blofeld contains tag definitions created from metadata within official tools and engines as well as approximated functionality between lesser understood versions of the game.

## Build Requirements
* Up-to-date Windows 10 installation
* Visual Studio 2019 16.5 or newer
    * Desktop Development with C++
    * Windows 10 SDK 10.0.18362.0
* [CMake 3.14]([https://cmake.org/download/](https://cmake.org/download/)) or newer is required (`cmake` is added to PATH)
* [SVN 1.13]([https://tortoisesvn.net/downloads.html](https://tortoisesvn.net/downloads.html)) or newer is required (`svn` is added to PATH)

> **Note**: Build support is not provided by team members in Discord. Our philosophy is that a green AppVeyor means a green build.
> 
> **Warning**: LLVM and Blender are built as local copies directly from source code and the entire project structure is multi-thread compilation enabled. Building from source on low end systems often results in failure due to flaws in the Windows operating system. To mitigate these issues, it is recommended to manually build projects under the `libs` project directory manually or build the solution using MSBuild with parallel project compilation disabled.
>

