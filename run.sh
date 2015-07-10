#!/usr/bin/env bash

g++ ./scr/words_tweeted.cpp -o words_tweeted
g++ ./scr/median_unique.cpp -o median_unique
./words_tweeted
./median_unique
