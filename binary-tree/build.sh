#!/bin/bash

set -xe

gcc -Wall -fsanitize=address -o main bin-tree.c
