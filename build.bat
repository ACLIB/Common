mkdir buildMSVC
cd buildMSVC

mkdir build64
cd build64
cmake ../.. -G "Visual Studio 10 2010" -A x64
cmake --build .
cd ..

mkdir build32
cd build32
cmake ../.. -G "Visual Studio 10 2010" -A Win32
cmake --build .
