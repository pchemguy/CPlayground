### AddLib

This demo follows [Transmission Zero's][] [Building Windows DLLs with MinGW][] and [Advanced MinGW DLL Topics][] tutorials illustrating the process of creating a primitive dynamic link library using the MinGW toolchains (the *docs* subfolder contains saved copies of these pages). This library exports one function, taking two 32-bit signed integers, and returns their sum as another 32-bit signed integer. The library also exports two variables.

The demo folder includes

* "add\.c" - the source of the library,
* "add\.h" - header file used by the library and the client app,
* "addclient\.c" - source of the client,
* "AddLib\.sh" - script, building the library from a MinGWxx shell (must be built before the client; binaries are moved into the x32 or x64 subfolder),
* "AddClient\.sh" - script, building the client app from a MinGWxx shell (must be built after the library; binaries are moved into the x32 or x64 subfolder),
* "x32" and "x64" - directories containing precompiled library and client for x32 and x64 platforms.

<!-- References -->

[Transmission Zero's]: https://www.transmissionzero.co.uk/
[Building Windows DLLs with MinGW]: https://www.transmissionzero.co.uk/computing/building-dlls-with-mingw/
[Advanced MinGW DLL Topics]: https://www.transmissionzero.co.uk/computing/advanced-mingw-dll-topics/
