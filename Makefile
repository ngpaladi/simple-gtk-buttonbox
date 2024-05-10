prefix?=/usr/local
debug_flags?=

build: ButtonBox.o main.o
	mkdir -p bin
	g++ $(debug_flags) main.o ButtonBox.o -std=c++11 -o bin/simple-gtk-buttonbox `pkg-config gtkmm-3.0 --cflags --libs`
main.o: ButtonBox.o src/main.cpp 
	mkdir -p bin
	g++ $(debug_flags) -c src/main.cpp -std=c++11 `pkg-config gtkmm-3.0 --cflags --libs`
ButtonBox.o: src/ButtonBox.cpp
	mkdir -p bin
	g++ $(debug_flags) -c src/ButtonBox.cpp -std=c++11 `pkg-config gtkmm-3.0 --cflags --libs`
install: build clean
	cp bin/simple-gtk-buttonbox $(prefix)/bin
clean:
	rm -rf *.o
uninstall:
	rm $(prefix)/bin/simple-gtk-buttonbox
