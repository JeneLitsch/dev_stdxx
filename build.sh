cmake . -D CMAKE_CXX_COMPILER=clang++ -B ./build
cd build
make -j 8
cd ..

mkdir ./bin
mv ./build/bin/test ./bin/test
mv ./build/bin/sandbox ./bin/sandbox