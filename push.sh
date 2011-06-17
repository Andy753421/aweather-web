#!/bin/bash
user=spenceal
dest=/home/lug/htdocs/proj/aweather/web/
rsync -uavz \
	.htaccess $user@lug.rose-hulman.edu:$dest
rsync -uavz \
	--delete \
	--exclude '*~' \
	--exclude '.*' \
	--exclude '*.o' \
	./ $user@lug.rose-hulman.edu:$dest
