// {
	if (match($0, /<h[0-9] id="([^"]*)">([0-9.]* *)([^<]*)<\/h[0-9]>/, arr)) {
		id   = arr[1];
		num  = arr[2];
		txt  = arr[3];
		toc  = toc  "\n" "<li>" num "<a href=\"#" id "\">" txt "</a></li>"
		body = body "\n" "<a id=\"" id "\"></a>"
	}
	body = body "\n" $0
}

END {
	print "<h2>Table of Contents</h2>";
	print "<ul style=\"list-style:none;\">" toc "</ul>";
	print body;
}
