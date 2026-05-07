#!/bin/bash
# ===== Configuration =====
THRESHOLD=80                     # Alert threshold in %
PARTITION="/home"
HOSTNAME=$(hostname)
DATE=$(date)
# ===== Get disk usage =====
                   # Disk partition to monitor
USAGE=$(df -h "$PARTITION" | awk 'NR==2 {gsub("%",""); print $5}')
# ===== Check threshold =====
if [ "$USAGE" -ge "$THRESHOLD" ]; then
    MESSAGE="WARNING: Disk usage on $HOSTNAME ($PARTITION) is at ${USAGE}% as 
of $DATE"
    # Send email alert
    echo "$MESSAGE"
    # Optional: log locally
    echo "$DATE - $MESSAGE" >> "$HOME/disk_monitor.log"
fi