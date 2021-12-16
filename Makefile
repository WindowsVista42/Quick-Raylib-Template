d:
	ninja -C build/debug -f build.ninja
	./build/debug/run

r:
	ninja -C build/release -f build.ninja
	./build/release/run

b:
	rm -r build || true
	mkdir build || true
	cmake -B build/debug -GNinja -DCMAKE_BUILD_TYPE=Debug .
	cmake -B build/release -GNinja -DCMAKE_BUILD_TYPE=Release .

f:
	clang-format src/*.hpp src/*.cpp -i
