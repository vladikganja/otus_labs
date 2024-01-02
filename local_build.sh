if ! test -d .build; then
    mkdir .build
fi
cd ~/projects/otus_labs/.build
cmake ..
cmake --build . --config Release
cmake --build . --target package

# TESTS LAUNCH
./helloworld/boost_tests/boost_tests
./helloworld/gtests/gtests
