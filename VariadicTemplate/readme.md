## Variadic Templates
A practical example using Variadic templates. For more info:
https://en.cppreference.com/w/cpp/language/parameter_pack

# How to run
cmake, VS19 (or some version) need to be installed.
To build & run in root dir either at:

**Command prompt**
* mkdir results
* mkdir build
* cd build
* cmake -G "Visual Studio 16 2019" ..
* cmake --build . --config Release
* cd ..
* .\build\Release\VariadicTemplateExample.exe

Or just type "run.bat".

**Shell**

* mkdir results
* mkdir build
* cd build
* cmake -G "Visual Studio 16 2019" ..
* cmake --build . --config Release
* cd ..
./build/Release/VariadicTemplateExample.exe

Or just type "sh run.sh".

This has been tested in Windows 10 and compiled/linked/ran as of my commit using both the above methods. Although I prefer Linux, it was not tested here.

# Source Code
TestApp is the driver and StateManager is the class containing the variadic templates.

# Sample output
This output shows the function and line number to display which UpdateState is called. This is more practical than many examples I've seen which show what looks like the parameters are going through a recursion. This is not the case, but actually the methods are generated at compile time and used with the remaining parameters. In this example, specific functions are added to execute logic - dumping the values passed in.

```StateManager::ProcessStateChange
StateManager::UpdateState: ln37
UpdateState: Paused: 4
StateManager::ProcessStateChange
StateManager::UpdateState: ln42
UpdateState: Running: eating cookies
StateManager::ProcessStateChange
StateManager::UpdateState: ln47
UpdateState: Error: tummy ache, error code: 65535```
