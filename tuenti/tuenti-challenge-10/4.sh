#!/bin/bash
curl -sH "Host: pre.steam-origin.contest.tuenti.net"  steam-origin.contest.tuenti.net:9876/games/cat_fight/get_key | jq '.key' | tr -d '"'
