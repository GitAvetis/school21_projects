#!/bin/sh

spawn-fcgi -p 8080 -n /app/MyServer &

nginx -g 'daemon off;'