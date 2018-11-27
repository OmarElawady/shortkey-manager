install:
	@echo "" > keys.txt
	g++ --std=c++11 main.cpp src/*.cpp src/*.h -o ash -O2 -lX11

