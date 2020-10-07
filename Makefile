CXX= g++
CXXFLAGS= -Wall -Wfatal-errors -std=c++17 $(INCLUDES)
INCLUDES= -I .\include
LDFLAGS= -L .\lib
LDLIBS= -lglfw3 -lopengl32 -lgdi32 -lglu32 -lglew32

install: 
	$(CXX) -o fractal_viewer main.cpp Monitor.cpp Renderer.cpp ShaderManager.cpp  -g $(CXXFLAGS) $(LDLIBS) $(LDFLAGS)

clean:
	rm -f *.o
