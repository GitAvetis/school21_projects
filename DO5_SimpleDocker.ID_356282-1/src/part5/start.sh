#!/bin/sh

spawn-fcgi -p 8080 /app/MyServer &
nginx -g 'daemon off;'