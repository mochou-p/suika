#

from os      import mkdir, system
from os.path import isdir


APP      = "suika"

BIN      = "./bin"
SRC      = "./src"

INPUT    = f"{SRC}/main.cpp"
OUTPUT   = f"{BIN}/{APP}"

CXX      = "g++"
CXXFLAGS = "-std=c++11"

BUILD    = f"{CXX} {CXXFLAGS} {INPUT} -o {OUTPUT}"


def main():
    if not isdir(BIN):
        print(f"making directory '{BIN}'..")
        mkdir(BIN)

    print("compiling..")
    system(BUILD)

    print("project compiled")


if __name__ == "__main__":
    main()
