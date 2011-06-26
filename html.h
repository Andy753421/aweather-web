/* Version information */
#define VERSION        "0.5"
#define VERSION_LINUX  VERSION
#define VERSION_GENTOO VERSION
#define VERSION_DEBIAN VERSION
#define VERSION_WIN32  VERSION
#define VERSION_MACOS  "0"

/* Link info */
#define WIKI_INDEX   "/code/projects/aweather/wiki"
#define WIKI_INSTALL "/code/projects/aweather/wiki/Install"

#define BUG_LIST     "/code/projects/aweather/issues"
#define BUG_NEW      "/code/projects/aweather/issues/new"

#define GIT_AWEATHER "git://lug.rose-hulman.edu/proj/aweather"
#define GIT_GRITS    "git://lug.rose-hulman.edu/proj/grits"
#define GIT_RSL      "git://lug.rose-hulman.edu/~spenceal/rsl"

#define GW_AWEATHER  "/git/?p=proj/aweather"
#define GW_GRITS     "/git/?p=proj/grits"
#define GW_RSL       "/git/?p=~spenceal/rsl"

#define RSL_WEB      "http://trmm-fc.gsfc.nasa.gov/trmm_gv/software/rsl/"
#define RSL_FTP      "ftp://trmm-fc.gsfc.nasa.gov/software/rsl-v1.41.tar.gz"

/* Types */
typedef struct {
	const char *link;
	const char *name;
	void (*print)(void);
} page_t;

/* Data */
extern page_t header[];
extern page_t other[];
extern page_t footer[];
extern page_t special[];

/* Global functions */
void print_header(void);
void print_page(const page_t *which);

/* Pages */
void print_about(void);
void print_news(void);
void print_screenshots(void);
void print_download(void);
void print_development(void);
void print_grits(void);
void print_rsl(void);

void print_contact(void);
void print_legal(void);

void print_index(void);
void print_notfound(void);
