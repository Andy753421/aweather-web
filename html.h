/* Version information */
#define VERSION       "0.8"
#define VERSION_GRITS "0.8"
#define VERSION_WIN   "0.8"
#define VERSION_MAC   "0.8"

#define VERSION_DESC  "Version " VERSION " adds a compass rose, clickable radar labels, " \
                      "and a number of bug fixes."

/* Link info */
#define WIKI_INDEX    "/dev/projects/aweather/wiki"
#define WIKI_INSTALL  "/dev/projects/aweather/wiki/Install"

#define BUG_LIST      "/dev/projects/aweather/issues"
#define BUG_NEW       "/dev/projects/aweather/issues/new"

#define MAIL_LIST     "http://pileus.org/mailman/listinfo/dev"
#define MAIL_ARCH     "http://pileus.org/pipermail/dev/"

#define GIT_AWEATHER  "git://pileus.org/aweather"
#define GIT_GRITS     "git://pileus.org/grits"
#define GIT_RSL       "git://pileus.org/~andy/rsl"
#define GIT_PKG       "git://pileus.org/~andy/aweather-pkg"
#define GIT_WEB       "git://pileus.org/~andy/aweather-web"

#define GW_AWEATHER   "/git/?p=aweather"
#define GW_GRITS      "/git/?p=grits"
#define GW_RSL        "/git/?p=~andy/rsl"
#define GW_PKG        "/git/?p=~andy/aweather-pkg"
#define GW_WEB        "/git/?p=~andy/aweather-web"

#define RSL_TAR       "rsl-v1.43.tar.gz"
#define RSL_WEB       "http://trmm-fc.gsfc.nasa.gov/trmm_gv/software/rsl/"
#define RSL_FTP       "ftp://trmm-fc.gsfc.nasa.gov/software/"

#define GENTOO_HOME   "http://gpo.zugaina.org/sci-geosciences/aweather"
#define DEBIAN_HOME   "http://packages.debian.org/unstable/aweather"
#define UBUNTU_HOME   "http://packages.ubuntu.com/oneiric/science/aweather"
#define UBUNTU_PPA    "https://launchpad.net/~andy753421/+archive/aweather"
#define ARCH_HOME     "http://aur.archlinux.org/packages.php?ID=52003"
#define SLACKY_HOME   "http://www.slacky.eu/asche/pkgs/index.php?pkg=2682"

#define PREFIX        "http://pileus.org/aweather/"

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
const extern page_t header[];
const extern page_t other[];
const extern page_t footer[];
const extern page_t special[];

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
