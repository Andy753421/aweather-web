#include <glib.h>
#include "html.h"

/* Page data */
page_t header[] = {
	{"about",       "About",       print_about},
	{"news",        "News",        print_news},
	{"screenshots", "Screenshots", print_screenshots},
	{"download",    "Download",    print_download},
	{"development", "Development", print_development},
	{NULL,          NULL,          NULL},
};
page_t other[] = {
	{"grits",       "Grits",       print_grits},
	{"rsl",         "RSL",         print_rsl},
	{NULL,          NULL,          NULL},
};
page_t footer[] = {
	{"contact",     "Contact",     print_contact},
	{NULL,          NULL,          NULL},
};
page_t special[] = {
	{"index.cgi",   NULL,          print_index},
	{"notfound",    "Not found",   print_notfound},
	{NULL,          NULL,          NULL},
};
page_t *everything[] = {header, other, footer, special, NULL};
const page_t *index    = &special[0];
const page_t *notfound = &special[1];

/* Main */
int main(int argc, char **argv)
{
	print_header();

	const gchar *name = g_getenv("PATH_INFO");
	if (name == NULL || name[0] == '\0' || name[1] == '\0')
		return print_page(index), 0;

	/* Look up a specific page */
	for (int i = 0; everything[i];         i++)
	for (int j = 0; everything[i][j].link; j++) {
		page_t *page = &everything[i][j];
		if (g_str_equal(page->link, name+1))
			return print_page(page), 0;
	}

	/* 404 */
	return print_page(notfound), 0;
}
