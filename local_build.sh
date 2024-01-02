if ! test -d .build; then
    mkdir .build
fi
cd ~/projects/otus_labs/.build
cmake -DBUILD_SHARED_LIBS=TRUE ..
cmake --build . --config Release

# TESTS LAUNCH
./helloworld/boost_tests/boost_tests
./helloworld/gtests/gtests
