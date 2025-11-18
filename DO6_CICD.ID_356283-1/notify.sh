#!/bin/bash

BOT_TOKEN="8397040010:AAFyBRiUdnTF37BTJPnj9rMKaEzOIyWqH5E"
CHAT_ID="718129829" 

if [ "$CI_JOB_STATUS" == "success" ]; then
  STATUS="✅ Успешно"
else
  STATUS="❌ Ошибка"
fi

# Формируем сообщение
MESSAGE="🔔 *Проект:* ${CI_PROJECT_NAME}%0A*Ветка:* ${CI_COMMIT_REF_NAME}%0A*Этап:* ${CI_JOB_STAGE}%0A*Статус:* ${STATUS}"

# Отправляем сообщение
curl -s -X POST "https://api.telegram.org/bot${BOT_TOKEN}/sendMessage" \
  -d chat_id="${CHAT_ID}" \
  -d text="${MESSAGE}"\
  -d parse_mode="Markdown"