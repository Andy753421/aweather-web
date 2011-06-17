#!/bin/bash
user=spenceal
dest="/home/lug/htdocs/proj/aweather/"
rsync -uavz .htaccess \
	$user@lug.rose-hulman.edu:$dest
rsync -uavz --delete \
	--exclude '*~' \
	--exclude '.*' \
	index.cgi images screens data \
	$user@lug.rose-hulman.edu:$dest
