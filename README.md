# CMake-TCLAP-Template

Infrastructure for small course projects using [CMake](https://cmake.org/) and [TCLAP](http://tclap.sourceforge.net/).

## Overview

- [x] CMakeLists.txt for a user-defined library

- [x] VS Code configuration for [Mingw-w64](https://github.com/mirror/mingw-w64) compiler

- [x] [TCLAP](https://github.com/mirror/tclap) included

## Description

### File directory structure

```
  .
  ├─.vscode
  ├─include
  │  └─tclap
  └─library
```

### Content

- `./include/*` : head files.
- `./include/tclap`:  the TCLAP library implemented entirely in headers
- `./library`: a user-defined library.
