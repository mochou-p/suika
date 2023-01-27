#

from os.path import isdir
from shutil  import rmtree


BIN = "./bin"


def main():
    if not isdir(BIN):
        print("project is already clean")
        return

    print(f"removing directory '{BIN}'..")
    rmtree(BIN)

    print("project cleaned")


if __name__ == "__main__":
    main()
