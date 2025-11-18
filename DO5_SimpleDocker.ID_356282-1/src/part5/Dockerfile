FROM nginx:latest

RUN apt-get update && apt-get install -y --no-install-recommends \
    gcc \
    build-essential \
    spawn-fcgi \
    libfcgi-dev \
    wget \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Создаём рабочего пользователя (CIS-DI-0001)
RUN useradd -r -u 1001 appuser

WORKDIR /app

COPY MyServer.c .
RUN gcc MyServer.c -o MyServer -lfcgi
COPY nginx/nginx.conf /etc/nginx/nginx.conf
COPY start.sh .
RUN chmod +x start.sh && chown -R appuser:appuser /app

RUN mkdir -p /var/cache/nginx /var/run /var/log/nginx /run && \
    chown -R appuser:appuser /var/cache/nginx /var/run /var/log/nginx /run

# Удаляем опасные setuid/setgid биты(CIS-DI-0008)
RUN find / -xdev -perm /6000 -type f -exec chmod a-s {} \; 2>/dev/null || true

# Переходим на non-root пользователя
USER appuser

# Добавляем базовый healthcheck (CIS-DI-0006)
HEALTHCHECK --interval=30s --timeout=10s --start-period=5s --retries=3 \
    CMD wget -q --spider http://localhost:81/ || exit 1

CMD ["./start.sh"]
