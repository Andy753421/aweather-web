/* Version information */
#define VERSION       "0.7"
#define VERSION_GRITS "0.7"
#define VERSION_WIN   "0.7"
#define VERSION_MAC   "0.7"

#define VERSION_DESC  "Version " VERSION " a GPS tracking plugin for Linux " \
                      "along with various other updates and bug fixes"

/* Link info */
#define WIKI_INDEX    "/code/projects/aweather/wiki"
#define WIKI_INSTALL  "/code/projects/aweather/wiki/Install"

#define BUG_LIST      "/code/projects/aweather/issues"
#define BUG_NEW       "/code/projects/aweather/issues/new"

#define GIT_AWEATHER  "git://lug.rose-hulman.edu/proj/aweather"
#define GIT_GRITS     "git://lug.rose-hulman.edu/proj/grits"
#define GIT_RSL       "git://lug.rose-hulman.edu/~spenceal/rsl"
#define GIT_PKG       "git://lug.rose-hulman.edu/~spenceal/aweather-pkg"
#define GIT_WEB       "git://lug.rose-hulman.edu/~spenceal/aweather-web"

#define GW_AWEATHER   "/git/?p=proj/aweather"
#define GW_GRITS      "/git/?p=proj/grits"
#define GW_RSL        "/git/?p=~spenceal/rsl"
#define GW_PKG        "/git/?p=~spenceal/aweather-pkg"
#define GW_WEB        "/git/?p=~spenceal/aweather-web"

#define RSL_TAR       "rsl-v1.42.tar.gz"
#define RSL_WEB       "http://trmm-fc.gsfc.nasa.gov/trmm_gv/software/rsl/"
#define RSL_FTP       "ftp://trmm-fc.gsfc.nasa.gov/software/"

#define GENTOO_HOME   "http://gpo.zugaina.org/sci-geosciences/aweather"
#define DEBIAN_HOME   "http://packages.debian.org/unstable/aweather"
#define UBUNTU_HOME   "http://packages.ubuntu.com/oneiric/science/aweather"
#define UBUNTU_PPA    "https://launchpad.net/~andy753421/+archive/aweather"
#define ARCH_HOME     "http://aur.archlinux.org/packages.php?ID=52003"
#define SLACKY_HOME   "http://www.slacky.eu/asche/pkgs/index.php?pkg=2682"

#define PREFIX        "http://lug.rose-hulman.edu/proj/aweather/"

/* Types */
typedef struct {
	const char *link;
	const char *name;
	void (*print)(void);
	float prio;
	/* Optional */
	const char *desc;
} page_t;

/* Data */
extern page_t header[];
extern page_t other[];
extern page_t footer[];
extern page_t special[];

/* Global functions */
void print_file(char *file);
void print_header(void);
void print_page(const page_t *which);

/* Pages */
void print_about(void);
void print_manual(void);
void print_news(void);
void print_oldnews(void);
void print_screenshots(void);
void print_download(void);
void print_development(void);
void print_grits(void);
void print_rsl(void);

void print_contact(void);
void print_legal(void);

void print_index(void);
void print_notfound(void);
void print_sitemap(const page_t **pages);
