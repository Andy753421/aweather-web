/* Types */
typedef struct {
	const char *link;
	const char *name;
	void (*print)(void);
} page_t;

/* Data */
extern page_t header[];
extern page_t grits[];
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

void print_contact(void);
void print_legal(void);

void print_index(void);
void print_notfound(void);
