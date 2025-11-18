#!/bin/bash
set -e

REMOTE_USER="pearlibl"
REMOTE_HOST="192.168.1.64"
REMOTE_DIR="/usr/local/bin"
SSH_KEY="/home/gitlab-runner/.ssh/id_ed25519"

# Копируем артефакты
scp -i ${SSH_KEY} -o StrictHostKeyChecking=no src/cat/s21_cat src/grep/s21_grep ${REMOTE_USER}@${REMOTE_HOST}:/tmp/

# Перемещаем и выставляем права
ssh -i ${SSH_KEY} -o StrictHostKeyChecking=no ${REMOTE_USER}@${REMOTE_HOST} "
  sudo mv /tmp/s21_cat ${REMOTE_DIR}/s21_cat &&
  sudo mv /tmp/s21_grep ${REMOTE_DIR}/s21_grep &&
  sudo chmod +x ${REMOTE_DIR}/s21_cat ${REMOTE_DIR}/s21_grep
"