#include <glib.h>
#include "html.h"

const char desc[] =
	"AWeather is a free real-time weather data viewer that "
	"supports Level-II NEXRAD files, polarimetric radars, "
	"and volume rendering.";

/* Page data */
page_t header[] = {
	{"about",       "About",       print_about,        0.7, NULL},
	{"news",        "News",        print_news,         0.3, NULL},
	{"screenshots", "Screenshots", print_screenshots,  0.5, NULL},
	{"download",    "Download",    print_download,     0.7, NULL},
	{"development", "Development", print_development,  0.3, NULL},
	{NULL,          NULL,          NULL,               0.0, NULL},
};
page_t other[] = {
	{"grits",       "Grits",       print_grits,        0.8, NULL},
	{"rsl",         "RSL",         print_rsl,          0.3, NULL},
	{NULL,          NULL,          NULL,               0.0, NULL},
};
page_t footer[] = {
	{"contact",     "Contact",     print_contact,      0.2, NULL},
	{NULL,          NULL,          NULL,               0.0, NULL},
};
page_t special[] = {
	{"",            NULL,          print_index,        1.0, desc},
	{NULL,          "Not found",   print_notfound,    -1.0, NULL},
	{NULL,          NULL,          NULL,               0.0, NULL},
};
const page_t *everything[] = {header, other, footer, special, NULL};
const page_t *index        = &special[0];
const page_t *notfound     = &special[1];

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
		const page_t *page = &everything[i][j];
		if (g_str_equal(name+1, page->link))
			return print_page(page), 0;
	}

	/* Print sitemap by itself */
	if (g_str_equal(name+1, "sitemap.xml"))
		return print_sitemap(everything), 0;

	/* 404 */
	return print_page(notfound), 0;
}
