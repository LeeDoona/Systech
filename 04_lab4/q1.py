from subprocess import call
import sys

print call(["cat", "/proc/"+ sys.argv[1]+"/cmdline" ])