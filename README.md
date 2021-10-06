# Blam Creation Suite
## What is Blam Creation Suite?
Blam Creation Suite is a combination of tools designed for creating custom content for the Halo franchise from Halo Combat Evolved through Halo Infinite. This project is managed by Chimps at Sea and you can find out more about this project on the official website [chimpsatsea.com](https://chimpsatsea.com) or join our [Discord](https://discord.gg/chimpsatsea) channel.

[![Build status](https://ci.appveyor.com/api/projects/status/tjha8f9o6brbbc4k/branch/master?svg=true)](https://ci.appveyor.com/project/ChimpMods/Blam-Creation-Suite/branch/master) [![Discord](https://img.shields.io/discord/598260526480359454?label=Discord)](https://discord.gg/chimpsatsea)

## Download/Continuous Integration
The latest release of Blam Creation Suite can be downloaded from [chimpsatsea.com](https://chimpsatsea.com) and you can find the latest development builds available for download on the [AppVeyor Continuous Integration]([https://ci.appveyor.com/project/ChimpsAtSea/Blam-Creation-Suite/branch/master/artifacts](https://ci.appveyor.com/project/ChimpsAtSea/Blam-Creation-Suite/branch/master/artifacts))

## Engineering Overview
Blam Creation Suite is made up of a collection of modular C++ frameworks for handling game content, user interface and visualization, 3d rendering capabilities using DirectX 12, and data abstraction. The project is designed to execute quickly and has no binary dependencies.
*    **Mandrill** is a Blam tag/resource editing framework designed to fulfill the traditional role of the Guerilla/Bonobo tool from the authentic engine tools. Mandrill is designed for extremely high performance and a high degree of game engine abstraction and relies on C++ code generation for functionality.
*    **Blofeld** is a Blam tag layout framework loosely based off of the original 2005 GDC presentation [Content Management for Halo 2 and Beyond]([https://nikon.bungie.org/misc/gdc2005_mnoguchi/](http://nikon.bungie.org/misc/gdc2005_mnoguchi/)). Blofeld contains tag definitions created from metadata within official tools and engines as well as approximated functionality between lesser understood versions of the game.

## Build Requirements
* Recommended minimum 8-core CPU and 64GiB of memory
* DirectX 12 capable GPU
* Up-to-date Windows 10 installation
* Visual Studio 2019 16.11 or newer
* Desktop Development with C++
* Windows 10 SDK 10.0.19041.0
* [CMake 3.21.3]([https://cmake.org/download/](https://cmake.org/download/)) or newer is required (`cmake` added to PATH)

> **Note**: Build support is not provided by team members in Discord. Our philosophy is that a green AppVeyor means a green build.
> 
> **Warning**: Building from source on low end systems often results in failure due to flaws in the way the MSVC compiler allocates memory. It is recommended to have a minimum of 8GiB of virtual memory per CPU thread on the development system.
>

