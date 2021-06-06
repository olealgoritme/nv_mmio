#!/usr/bin/env bash
lspci -v -d 10de: | grep 'size=16M' | awk '{print $3}' 

