LIB := libSimpleOpenGL.so
TESTS := FakeCube.bin Primitives.bin

LIBSRC := $(wildcard SimpleOpenGL/src/*.cpp)
LIBSRC += $(wildcard SimpleOpenGL/src/shapes/*.cpp)
LIBOBJ := $(patsubst SimpleOpenGL/src/%.cpp, .build/%.o, $(LIBSRC))

CXXFLAGS = -ISimpleOpenGL/inc -ISimpleOpenGL/inc/Shapes -std=c++11

OS := $(shell uname)
ifeq ($(OS), Darwin)
LDLIBS = -lglfw -framework OpenGL
else
LDLIBS = -lglfw -lGL
endif

all : $(LIB) $(TESTS) tags

$(LIB) : $(LIBOBJ)
	$(CXX) $(LDLIBS) $(LIBOBJ) -shared -o $@

-include $(wildcard .build/*.d)

%.bin : %/main.cpp
	$(CXX) $(CXXFLAGS) -L. -lSimpleOpenGL $(basename $@)/main.cpp -o $@

.build/%.o : SimpleOpenGL/src/%.cpp
	mkdir -p $(dir $@)
	$(CXX) -c $(CXXFLAGS) $< -o $@
	$(CXX) -MM -MP $(CXXFLAGS) $< -MT $@ -MF .build/$*.d

.PHONY : clean tags

clean :
	-rm -rf .build/*
	-rm $(LIB)
	-rm $(TESTS)
	-rm .tags

tags :
	/usr/local/Cellar/ctags/5.8_1/bin/ctags -R -o .tags
