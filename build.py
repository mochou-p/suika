#

from os      import mkdir, rmdir, system
from os.path import isdir


APP      = "suika"

BIN      = "./bin"
INC      = "./inc"
LIB      = "./lib"
SRC      = "./src"

GLFW     = f"{LIB}/GLFW"

SOURCES  = f"{SRC}/*.cpp"
OUTPUT   = f"{BIN}/{APP}"
HEADERS  = f"-I{INC} -I{GLFW}/include"
LINKS    = f"-L{GLFW}/lib -lglfw3 -lcomdlg32 -lopengl32 -lgdi32 -mwindows"

CXX      = "g++"
CXXFLAGS = "-std=c++11 -Wall -Wextra -Werror"

BUILD    = f"{CXX} {CXXFLAGS} {SOURCES} -o {OUTPUT} {HEADERS} {LINKS}"


def main():
    if not isdir(BIN):
        print(f"making directory '{BIN}'..")
        mkdir(BIN)

    print("compiling..")
    error = system(BUILD)

    if error:
        try:
            rmdir(BIN)
        except OSError:
            pass

        return

    print("project compiled")


if __name__ == "__main__":
    main()
