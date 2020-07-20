# Dns Flush Resolver Cache
[![Build Status](https://api.travis-ci.org/coflery/DnsFlushResolverCache.svg?branch=master)](https://travis-ci.org/coflery/DnsFlushResolverCache)

The tool is a build file for windows platform.

This code is just a copy from [how-to-clear-flush-the-dns-cache-in-win32-apis](https://stackoverflow.com/questions/52007372/how-to-clear-flush-the-dns-cache-in-win32-apis) and just build it.

The author is [CristiFati](https://stackoverflow.com/users/4788546/cristifati)

## [NOTE](./note)

* Checked ipconfig.exe's dependencies using [Dependency Walker](http://www.dependencywalker.com)

* Found dnsapi.dll among them

* Checked its exported functions, and found DnsFlushResolverCache

* Shallowly browsed the web, and found its signature (only found references like this on official site: [Windows 8 API Sets](https://docs.microsoft.com/en-us/windows/desktop/apiindex/windows-8-api-sets), meaning it's **not** public, so **software relying on it, is not robust**)

* Created a small test program

## [Compile](./microload)

This code build pass on vs2015 with C environment.

## [cmd out put](./cmd-out-put)

    C:\Users\Administrator\Desktop>cd C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\

    C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC>vcvarsall.bat x86_amd64

    C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC>cd C:\

    C:\>cl -EHsc main.c
    用于 x64 的 Microsoft (R) C/C++ 优化编译器 19.00.24215.1 版
    版权所有(C) Microsoft Corporation。保留所有权利。

    main.c
    Microsoft (R) Incremental Linker Version 14.00.24215.1
    Copyright (C) Microsoft Corporation.  All rights reserved.

    /out:main.exe
    main.obj

    C:\>main.exe
    DnsFlushResolverCache succeeded
