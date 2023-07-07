typedef struct listagen ListaGen;
typedef struct listagenno ListaGenNo;

struct listagenno{
	
	void* info;
	ListaGenNo* prox;
};

struct listagen{
	
	ListaGenNo* prim;
};

ListaGen* lst_cria(void);

void lgen_insere(ListaGen* l, void* p);
void lgen_percorre(ListaGen* l, void(*cb)(void*));
void lgen_percorre2(ListaGen* l, void(*cb)(void*, int), int dado);

void lgen_remove(ListaGen* l, int(*cb)(void*, int), int dado);
void lgen_libera(ListaGen* l);
int lgen_vazia(ListaGen* l);