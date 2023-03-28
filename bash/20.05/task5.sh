#! /bin/bash

ps -eo pid --sort=-%mem | head -n 6

#second variant
#ps aux | sort -nk 3,3 | tail -n 5
