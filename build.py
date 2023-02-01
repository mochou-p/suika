#

from os         import getcwd, mkdir, rmdir, system
from os.path    import abspath, exists, isdir
from shutil     import rmtree
from subprocess import run
from sys        import argv
from time       import time


DEBUG        = 0
RELEASE      = 1
TESTING      = 2

BUILD_MODE   = TESTING

USAGE        = "usage: 'python build.py <flags>'\n" \
               "flags: c - compile\n"               \
               "       r - run\n"                   \
               "       x - clean"

APP          = "suika"

BIN          = "./bin"
INC          = "./inc"
LIB          = "./lib"
SRC          = "./src"

GLFW         = f"{LIB}/GLFW"
IMGUI        = f"{LIB}/IMGUI"

SOURCES      = f"{IMGUI}/*.cpp {SRC}/*.cpp"
OUTPUT       = f"{BIN}/{APP}"
HEADERS      = f"-I{INC} -I{GLFW}/include -I{IMGUI}"
LINKS        = f"-L{GLFW}/lib -lglfw3 -lcomdlg32 -lopengl32 -lgdi32" \
               + (" -mwindows" if BUILD_MODE is RELEASE else "")

STD          = "-std=c++17"
OPTIMISATION = ("-Og",                     "-O2",  "-O0")[BUILD_MODE]
DEBUG        = ("-g3",                     "-g0",  "-g0")[BUILD_MODE]
WARNINGS     = ("-Wall -Wextra -Werror",   *([""]   * 2))[BUILD_MODE]
EXCEPTIONS   = ("-Wno-cast-function-type", *(["-w"] * 2))[BUILD_MODE]
EXTRA        = "-pipe"

CXX          = "g++"
CXXFLAGS     = f"{STD} {OPTIMISATION} {DEBUG} {WARNINGS} {EXCEPTIONS} {EXTRA}"

BUILD_CMD    = f"{CXX} {CXXFLAGS} {SOURCES} -o {OUTPUT} {HEADERS} {LINKS}"


c            = False
r            = False
x            = False
bindir       = False


def main():
    global c, r, x, bindir

    if len(argv) != 2:
        print(USAGE)
        return

    c = "c" in argv[1]
    r = "r" in argv[1]
    x = "x" in argv[1]

    if not (c or r or x):
        print(USAGE)
        return

    bindir = isdir(BIN)

    if c:
        if not bindir:
            print(f"making directory '{BIN}'..")
            mkdir(BIN)
            bindir = True

        print("compiling..")
        t = time()

        if system(BUILD_CMD):
            if bindir:
                try:
                    rmdir(BIN)
                except OSError:
                    pass

            return

        print(f"project compiled in {int(time() - t)} seconds")

    if r:
        app = f"{abspath(getcwd())}\{BIN[2::]}\{APP}.exe"

        if not exists(app):
            print("project is not built")
            return

        print("app running..")
        run(app)
        print("app closed")

    if x:
        if not bindir:
            print("project is already clean")
            return

        print(f"removing directory '{BIN}'..")
        rmtree(BIN)
        bindir = False

        print("project cleaned")


if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        if c and not r and bindir:
            try:
                rmdir(BIN)
            except OSError:
                pass

        print(":c")
