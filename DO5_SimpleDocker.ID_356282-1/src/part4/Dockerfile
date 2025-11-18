FROM nginx:latest

RUN apt-get update && apt-get install -y \
    gcc \
    spawn-fcgi \
    libfcgi-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY MyServer.c .
RUN gcc MyServer.c -o MyServer -lfcgi
COPY nginx/nginx.conf /etc/nginx/nginx.conf
COPY start.sh .
RUN chmod +x start.sh

CMD ["./start.sh"]