#!/bin/bash
set -e
TASK="$1"
if [ -z "$TASK" ]; then echo "Usage: ./commit_task.sh 01"; exit 1; fi
git add "Task${TASK}"
git commit -m "Complete Task ${TASK}"
