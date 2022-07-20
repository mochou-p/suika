# suika

GLAD     = .\..\lib\GLAD
GLFW     = .\..\lib\GLFW
IMGUI    = .\..\lib\IMGUI

FILES    = $(GLAD)\src\glad.c $(GLAD)\src\glad_wgl.c $(IMGUI)\*.cpp

CXX      = g++ -std=c++11 -O0 -Wall

CXXFLAGS = -I. -I$(GLAD)\include -I$(GLFW)\include -I$(IMGUI)
LDFLAGS  = -L$(GLFW)\lib -lopengl32 -lglfw3 -lgdi32

SUIKA    = $(CXX) $(CXXFLAGS) -o .\..\suika.exe $(FILES) *.cpp $(LDFLAGS)

TARGET:
	cd ".\src\" && $(SUIKA)
	.\suika

# temp: -O0, -Wall
