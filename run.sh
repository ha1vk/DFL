#!/bin/sh
./dfl-fuzz ./dfl_outuput f1 1234 ~/chrome_fuzz/chrome 2333 &
./dfl-fuzz ./dfl_outuput f2 1235 ~/chrome_fuzz/chrome 2334 &
./dfl-fuzz ./dfl_outuput f3 1236 ~/chrome_fuzz/chrome 2335 &
