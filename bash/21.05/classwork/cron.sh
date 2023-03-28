#! /bin/bash

#Command - delete all swap files
delSwp="find /home/$USER -name '*.swp' -exec rm -i '{}' \;"

#Get crontab content and put in new file
crontab -l > mycron

#Echo new cron into cron file
echo "0 5 * * * $delSwp" >> mycron

#install new cron file
crontab mycron
rm mycron
