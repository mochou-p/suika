# suika

GLAD     = ../lib/GLAD
GLFW     = ../lib/GLFW
GLM      = ../lib/GLM
IMGUI    = ../lib/IMGUI

FILES    = $(GLAD)/src/glad.c $(GLAD)/src/glad_wgl.c $(IMGUI)/*.cpp

CXX      = g++ -std=c++17 -O0# -Wall

CXXFLAGS = -I. -I$(GLAD)/include -I$(GLFW)/include -I$(GLM) -I$(IMGUI)
LDFLAGS  = -L$(GLFW)/lib -lopengl32 -lglfw3 -lgdi32

SUIKA    = $(CXX) $(CXXFLAGS) -o ../suika.exe $(FILES) *.cpp $(LDFLAGS)

TARGET:
	cd "src/" && $(SUIKA)
	./suika
