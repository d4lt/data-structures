#!/bin/bash

set -xe

gcc -Wall -pedantic -fsanitize=address -o main bin-tree.c
