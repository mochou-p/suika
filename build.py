#

from os      import mkdir, system
from os.path import isdir


APP      = "suika"

BIN      = "./bin"
INC      = "./inc"
SRC      = "./src"

INPUT    = f"{SRC}/*.cpp"
OUTPUT   = f"{BIN}/{APP}"

CXX      = "g++"
CXXFLAGS = "-std=c++11 -Wall -Wextra -Werror"

BUILD    = f"{CXX} {CXXFLAGS} {INPUT} -o {OUTPUT} -I{INC}"


def main():
    if not isdir(BIN):
        print(f"making directory '{BIN}'..")
        mkdir(BIN)

    print("compiling..")
    error = system(BUILD)

    if error:
        return

    print("project compiled")


if __name__ == "__main__":
    main()
