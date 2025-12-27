#!/usr/bin/env bash
set -euo pipefail

OUTPUT_FILE="history_log.txt"
HISTFILE_PATH="${HISTFILE:-$HOME/.zsh_history}"

LC_ALL=C sed 's/^: [0-9]\+:[0-9]\+;//' "$HISTFILE_PATH" > "$OUTPUT_FILE"
echo "Command history saved to $OUTPUT_FILE (from $HISTFILE_PATH)"

