LIB := libSimpleOpenGL.so
SHADERS := basic
TESTS := FakeCube.bin Primitives.bin

BUILDDIR := .build

LIBDIR := SimpleOpenGL
SRCDIR := $(LIBDIR)/src
INCDIR := $(LIBDIR)/inc
RESDIR := $(LIBDIR)/res

LIBSRC := $(shell find $(SRCDIR) -type f -name '*.cpp')
LIBOBJ := $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(LIBSRC))

SHADERFILES := $(patsubst %, $(RESDIR)/Shaders/%.vs.glsl, $(SHADERS)) $(patsubst %, $(RESDIR)/Shaders/%.fs.glsl, $(SHADERS))
SHADERHEADERS := $(patsubst $(RESDIR)/Shaders/%.glsl, $(INCDIR)/Shaders/%.h, $(SHADERFILES))

CXXFLAGS = -I$(INCDIR) -std=c++11

OS := $(shell uname)
ifeq ($(OS), Darwin)
LDLIBS = -lglfw -framework OpenGL
else
LDLIBS = -lglfw -lGL
endif

all : $(LIB) $(TESTS)

$(LIB) : $(SHADERHEADERS) $(LIBOBJ) 
	$(CXX) $(LDLIBS) $(LIBOBJ) -shared -o $@

$(INCDIR)/Shaders/%.h : $(RESDIR)/Shaders/%.glsl
	@mkdir -p $(dir $@)
	xxd -i $< > $@
	sed -i "" -e 's/unsigned/const/g' $@

-include $(shell find $(BUILDDIR) -type f -name '*.d')

%.bin : %/main.cpp
	$(CXX) $(CXXFLAGS) -L. -lSimpleOpenGL $(basename $@)/main.cpp -o $@

$(BUILDDIR)/%.o : $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) -c $(CXXFLAGS) $< -o $@
	$(CXX) -MM -MP $(CXXFLAGS) $< -MT $@ -MF $(BUILDDIR)/$*.d

.PHONY : clean tags

tags :
	/usr/local/Cellar/ctags/5.8_1/bin/ctags -R -o .tags

clean :
	-rm -rf $(BUILDDIR)/*
	-rm $(LIB)
	-rm $(TESTS)
	-rm .tags
	-rm $(SHADERHEADERS)

